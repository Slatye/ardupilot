/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/*
 *   APM_Airspeed.cpp - airspeed (pitot) driver
 */


#include <AP_HAL.h>
#include <AP_Math.h>
#include <AP_Common.h>
#include <AP_AOA.h>

extern const AP_HAL::HAL& hal;

 #include <sys/stat.h>
 #include <sys/types.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <drivers/drv_hrt.h>
 #include <uORB/topics/pwm_input.h>


// table of user settable parameters
const AP_Param::GroupInfo AP_AOA::var_info[] PROGMEM = {

    // @Param: ENABLE
    // @DisplayName: AoA enable
    // @Description: enable angle of attack sensor
    // @Values: 0:Disable,1:Enable
    AP_GROUPINFO("ENABLE",    0, AP_AOA, _enable, 1),

    // @Param: USE
    // @DisplayName: AoA use
    // @Description: use angle of attack sensor for flight control
    // @Values: 1:Use,0:Don't Use
    AP_GROUPINFO("USE",    1, AP_AOA, _use, 0),

    // @Param: OFFSET
    // @DisplayName: AoA offset
    // @Description: Angle of attack calibration offset (radians)
    // @Increment: 0.01
    AP_GROUPINFO("OFFSET", 2, AP_AOA, _offset, 0),

    AP_GROUPEND
};


void AP_AOA::init()
{   
    backend.init(NULL);
    _aoa = 0;
}

// read the airspeed sensor
void AP_AOA::read(void)
{
    if (!_enable) {
        _aoa = -1.0f;
        return;
    }
    uint64_t timestamp;
    uint64_t errors; 
    uint32_t pulse_width; 
    uint32_t period;
    backend.read(&timestamp, &errors, &pulse_width, &period);
    // See MA3 digital encoder specifications
    // http://www.usdigital.com/products/encoders/absolute/rotary/shaft/ma3
    float tmp = (4098.0f * pulse_width) / period - 1;
    tmp = (tmp <= 4094.0f) ? tmp : 4095.0f;
    tmp *= 2.0f * PI / 4096.0f; // Convert to radians.
    tmp += _offset.get();
    // Now move it to 0 <= AOA <= 2*PI
    if (tmp < 0) {
        _aoa = tmp + 2*PI;
    } else if (tmp >= 2*PI) {
        _aoa = tmp - 2*PI;
    } else {
        _aoa = tmp;
    }
    _last_update_ms         = hal.scheduler->millis();
}

