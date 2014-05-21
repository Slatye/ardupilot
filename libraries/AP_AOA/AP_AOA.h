/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#ifndef __AP_AOA_H__
#define __AP_AOA_H__

#include <AP_Common.h>
#include <AP_HAL.h>
#include <AP_Param.h>
#include <GCS_MAVLink.h>
#include <AP_Vehicle.h>
#include "../AP_HAL_PX4/PWMInput.h"

#define RAD2DEG(x) (x*180.0f/PI)

class AP_AOA
{
public:
    // constructor
    AP_AOA(const AP_Vehicle::FixedWing &parms) : 
        _healthy(false)
    {
		AP_Param::setup_object_defaults(this, var_info);
    };

    void init(void);

    // update _airspeed
    void            read(void);


    //
    float get_aoa_rad(void) const {
        return _aoa;
    }
    
    float get_aoa_deg(void) const {
        return RAD2DEG(_aoa);
    }


    // return true if airspeed is enabled, and airspeed use is set
    bool    use(void) const {
        return _enable && _use && _healthy;
    }

    // return true if airspeed is enabled
    bool    enabled(void) const {
        return _enable;
    }

    // force disable the airspeed sensor
    void  disable(void) {
        _enable.set(0);
    }

    // used by HIL to set the airspeed
    void set_HIL(float aoa) {
        _aoa = aoa;
    }

	// log data to MAVLink
	void log_mavlink_send(mavlink_channel_t chan);

    // return health status of sensor
    bool healthy(void) const { return _healthy; }

    // return time in ms of last update
    uint32_t last_update_ms(void) const { return _last_update_ms; }

    static const struct AP_Param::GroupInfo var_info[];

private:
    AP_Int8         _use;
    AP_Int8         _enable;
    float           _aoa;
    AP_Float        _offset;
    bool		    _healthy;
    uint32_t        _last_update_ms;

    float get_pressure(void);

    PX4::PX4PWMInput backend;

};


#endif // __AP_AOA_H__

