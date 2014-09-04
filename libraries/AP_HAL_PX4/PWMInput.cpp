#include <AP_HAL.h>

#if CONFIG_HAL_BOARD == HAL_BOARD_PX4

#include "PWMInput.h"
#include <uORB/uORB.h>
#include <uORB/topics/pwm_input.h>
#include <errno.h>

using namespace PX4;

extern const AP_HAL::HAL& hal;

// Initialise the PWM input module.
// This just subscribes to the PWM messages provided by the PWM input 
// module in PX4Firmware.
void PX4PWMInput::init(void* unused)
{
    _pwmin_sub = orb_subscribe(ORB_ID(pwm_input));
    if (_pwmin_sub == -1) {
        hal.scheduler->panic("Unable to subscribe to pwm_input");
    }
    pthread_mutex_init(&pwmin_mutex, NULL);
}

// Check whether a new input has been received.
bool PX4PWMInput::new_input()
{
    bool pwm_updated = false;
    int check_valid = orb_check(_pwmin_sub,&pwm_updated);
    if (pwm_updated && (check_valid == 0)) {
        return true;
    }
    return false;
}

// Read data from the sensor.
bool PX4PWMInput::read(uint64_t & timestamp, uint64_t & errors, uint32_t & pulse_width, uint32_t & period) 
{
    bool pwm_updated = false;
    int check_valid = orb_check(_pwmin_sub,&pwm_updated);

    pulse_width = 0;
    if (pwm_updated && (check_valid == 0)) {
        pthread_mutex_lock(&pwmin_mutex);
        orb_copy(ORB_ID(pwm_input), _pwmin_sub, &_pwmin);
        pthread_mutex_unlock(&pwmin_mutex);
    } else {
        return false;
    }
    _last_read  = _pwmin.timestamp;
    timestamp   = _pwmin.timestamp;
    errors      = _pwmin.error_count;
    pulse_width = _pwmin.pulse_width;
    period      = _pwmin.period;
    return true;
}

#endif // CONFIG_HAL_BOARD
