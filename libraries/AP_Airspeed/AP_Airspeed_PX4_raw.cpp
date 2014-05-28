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

#include <AP_Airspeed_PX4_raw.h>
#include <drivers/drv_airspeed.h>
#include <uORB/topics/differential_pressure_raw_data.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

extern const AP_HAL::HAL& hal;

bool AP_Airspeed_PX4_raw::init()
{
	_differential_pressure_raw_data_sub = orb_subscribe(ORB_ID(differential_pressure_raw_data));
	if (_differential_pressure_raw_data_sub == -1) {
        return false;
	}
    return true;
}

// read the airspeed sensor
bool AP_Airspeed_PX4_raw::get_differential_pressure(float &pressure)
{
    struct differential_pressure_raw_data_s raw_data;
	bool data_updated = false;
    bool check_valid = orb_check(_differential_pressure_raw_data_sub, &data_updated);
	if (data_updated && check_valid) {
        orb_copy(ORB_ID(differential_pressure_raw_data), _differential_pressure_raw_data_sub, &raw_data);
	} else {
        return false;
    }
    
    uint8_t status = (raw_data.data[0] & 0xC0) >> 6;
    if (status != 0) {
        return false;
    }
    uint16_t pressure_raw = ((raw_data.data[0] << 8) | (raw_data.data[1])) & 0x3FFF;
    uint16_t temperature_raw = ((raw_data.data[2] << 3) | (raw_data.data[3] >> 5));
    _temperature = ((200.0f * temperature_raw) / 2047) - 50;
	const float P_min = -1.0f;
	const float P_max = 1.0f;
	const float InAq_to_Pa = 248.84f;

	pressure = (-((pressure_raw - 1638.3f) * (P_max-P_min)/(0.8f*16383) + P_min)) * InAq_to_Pa;
    return true;
}

// read the temperature
bool AP_Airspeed_PX4_raw::get_temperature(float &temperature)
{
    temperature = _temperature;
    return true;
}

#endif // CONFIG_HAL_BOARD
