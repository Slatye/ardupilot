#include <AP_HAL.h>

#if CONFIG_HAL_BOARD == HAL_BOARD_PX4
#include "PWMInput.h"
#include <drivers/drv_hrt.h>
#include <uORB/uORB.h>
#include <uORB/topics/pwm_input.h>

using namespace PX4;

extern const AP_HAL::HAL& hal;

void PX4PWMInput::init(void* unused)
{
	_perf_pwmin = perf_alloc(PC_ELAPSED, "APM_pwmin");
	_pwmin_sub = orb_subscribe(ORB_ID(pwm_input));
	if (_pwmin_sub == -1) {
		hal.scheduler->panic("Unable to subscribe to pwm_input");		
	}
        pthread_mutex_init(&pwmin_mutex, NULL);
}

bool PX4PWMInput::new_input() 
{
    pthread_mutex_lock(&pwmin_mutex);
    bool valid = _pwmin.timestamp != _last_read;
    pthread_mutex_unlock(&pwmin_mutex);
    return valid;
}

void PX4PWMInput::read(uint64_t * timestamp, uint64_t* errors, uint16_t * pulse_width, uint16_t * period) 
{
    pthread_mutex_lock(&pwmin_mutex);
	_last_read = _pwmin.timestamp;
	*timestamp = _pwmin.timestamp;
    *errors    = _pwmin.error_count;
    *pulse_width = _pwmin.pulse_width;
    *period = _pwmin.period;
    pthread_mutex_unlock(&pwmin_mutex);
    return;
}

void PX4PWMInput::_timer_tick(void)
{
	perf_begin(_perf_pwmin);
	bool pwm_updated = false;
    bool check_valid = orb_check(_pwmin_sub,&pwm_updated);
	if (pwm_updated && check_valid) {
            pthread_mutex_lock(&pwmin_mutex);
            orb_copy(ORB_ID(pwm_input), _pwmin_sub, &_pwmin);
            pthread_mutex_unlock(&pwmin_mutex);
	}
	perf_end(_perf_pwmin);
}

#endif
