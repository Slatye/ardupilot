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
 *   PX4 airspeed backend
 */


#include <AP_HAL.h>

#if CONFIG_HAL_BOARD == HAL_BOARD_PX4

#include <AP_Airspeed_PX4.h>
#include <drivers/drv_airspeed.h>
#include <uORB/topics/differential_pressure.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

extern const AP_HAL::HAL& hal;

bool AP_Airspeed_PX4::init(AP_Float * scale)
{
    _sensor_scale = scale;
    _sensor_scale_active = (*scale).get();
    _fd = open(AIRSPEED_DEVICE_PATH, O_RDONLY);
    if (_fd == -1) {
        return false;
    }
    if (OK != ioctl(_fd, SENSORIOCSPOLLRATE, 100) ||
        OK != ioctl(_fd, SENSORIOCSQUEUEDEPTH, 15)) {
        hal.console->println("Failed to setup airspeed driver rate and queue");
    }
    
    struct airspeed_scale scale_struct;
    scale_struct.offset_pa = 0.0;
    scale_struct.scale = (*scale).get();
    ioctl(_fd, AIRSPEEDIOCSSCALE, (unsigned long) (&scale_struct));
    return true;
}

// read the airspeed sensor
bool AP_Airspeed_PX4::get_differential_pressure(float &pressure)
{
    if (_fd == -1) {
        return false;
    }
    struct differential_pressure_s report;
    // Check if our pressure scaling has changed since the last update.
    if ((*_sensor_scale) != _sensor_scale_active) {
        // Update the pressure sensor scaling.
        struct airspeed_scale scale_struct;
        scale_struct.offset_pa = 0.0;
        scale_struct.scale = *_sensor_scale;
        ioctl(_fd, AIRSPEEDIOCSSCALE, (unsigned long) (&scale_struct));
        _sensor_scale_active = (*_sensor_scale);
        return false;
    } 

    // read from the PX4 airspeed sensor
    float psum = 0;
    float tsum = 0;
    uint8_t valid = 0;
    uint16_t count = 0;
    
    while (::read(_fd, &report, sizeof(report)) == sizeof(report) && report.timestamp != _last_timestamp) {
            
        psum += report.differential_pressure_raw_pa;
        tsum += report.temperature;
        count++;
        _last_timestamp = report.timestamp;
    }
    if (count == 0) {
        return false;
    }
    pressure = psum / count;
    _temperature = tsum / count;
    return true;
}

// read the temperature
bool AP_Airspeed_PX4::get_temperature(float &temperature)
{
    temperature = _temperature;
    return true;
}

#endif // CONFIG_HAL_BOARD
