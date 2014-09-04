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
 *   AP_AOA.cpp - angle of attack sensor driver
 */


#include <AP_HAL.h>
#include <AP_Math.h>
#include <AP_Common.h>
#include <AP_AOA.h>

extern const AP_HAL::HAL& hal;

//#include <sys/stat.h>
//#include <sys/types.h>
//#include <fcntl.h>
//#include <unistd.h>

// table of user settable parameters
const AP_Param::GroupInfo AP_AOA::var_info[] PROGMEM = {

    // @Param: ENABLE
    // @DisplayName: AoA enable
    // @Description: Enable angle of attack sensor
    // @Values: 0:Disable,1:Enable
    AP_GROUPINFO("ENABLE",  0, AP_AOA, _enable, 1),

    // @Param: USE
    // @DisplayName: AoA use
    // @Description: Use angle of attack sensor for flight control. Not currently supported.
    // @Values: 1:Use,0:Don't Use
    AP_GROUPINFO("USE", 1, AP_AOA, _use, 0),

    // @Param: OFFSET
    // @DisplayName: AoA offset
    // @Description: Angle of attack calibration offset (radians)
    // @Increment: 0.01
    AP_GROUPINFO("OFFSET",  2, AP_AOA, _offset, 0),

    AP_GROUPEND
};


void AP_AOA::init()
{
    _aoa = 0;
}

// read the angle of attack sensor
void AP_AOA::read(void)
{
    if (!_enable) {
        _healthy = false;
        _aoa = 0.0f;
        return;
    }
    uint64_t timestamp;
    uint64_t errors; 
    uint32_t pulse_width; 
    uint32_t period;
    // Check whether the sensor is healthy while getting new data.
    _healthy = hal.pwmin->read(timestamp, errors, pulse_width, period);
    if (!_healthy) {
        return;
    }
    // See MA3 digital encoder specifications
    // http://www.usdigital.com/products/encoders/absolute/rotary/shaft/ma3
    float scaled_width = (4098.0f * pulse_width) / period - 1;
    scaled_width = (scaled_width <= 4094.0f) ? scaled_width : 4095.0f;
    // Convert to radians
    float angle = scaled_width * 2.0f * PI / 4096.0f + _offset.get(); 
    // Ensure that the value is between -pi and +pi
    if (angle < -PI) {
        _aoa = angle + 2*PI;
    } else if (angle >= PI) {
        _aoa = angle - 2*PI;
    } else {
        _aoa = angle;
    }
    _last_update_ms = hal.scheduler->millis();
}

