#include <AP_HAL.h>

#if CONFIG_HAL_BOARD == HAL_BOARD_PX4
#include "PWMInput.h"
#include <uORB/uORB.h>
#include <uORB/topics/pwm_input.h>
#include "stm32.h"
#include "stm32_gpio.h"
#include "stm32_tim.h"

using namespace PX4;

extern const AP_HAL::HAL& hal;

void PX4PWMInput::init(void* unused)
{
//	_perf_pwmin = perf_alloc(PC_ELAPSED, "APM_pwmin");
	_pwmin_sub = orb_subscribe(ORB_ID(pwm_input));
//    _pwmin.pulse_width |= 32;
	if (_pwmin_sub == -1) {
//        _pwmin.pulse_width |= 16;
		hal.scheduler->panic("Unable to subscribe to pwm_input");		
	}
    pthread_mutex_init(&pwmin_mutex, NULL);
}

bool PX4PWMInput::new_input() {
    bool pwm_updated = false;
    int check_valid = orb_check(_pwmin_sub,&pwm_updated);
    if (pwm_updated && (check_valid == 0)) {
        return true;
    }
    return false;
}

void PX4PWMInput::read(uint64_t * timestamp, uint64_t* errors, uint32_t * pulse_width, uint32_t * period) 
{
   // *pulse_width = getreg32(STM32_GPIOA_AFRL);
    // From here on, it's definitely fine. Setting a value here results in it turning up on the Atom.
    bool pwm_updated = false;
    int check_valid = orb_check(_pwmin_sub,&pwm_updated);

	if (pwm_updated && (check_valid == 0)) {
        pthread_mutex_lock(&pwmin_mutex);
        orb_copy(ORB_ID(pwm_input), _pwmin_sub, &_pwmin);
        pthread_mutex_unlock(&pwmin_mutex);
	} 
	_last_read = _pwmin.timestamp;
	*timestamp = _pwmin.timestamp;
    *errors    = _pwmin.error_count;
    *pulse_width = _pwmin.pulse_width;
    *period = _pwmin.period;
//    pthread_mutex_unlock(&pwmin_mutex);
    return;
}
/*
void PX4PWMInput::read(uint64_t * timestamp, uint64_t* errors, uint16_t * pulse_width, uint16_t * period) 
{
    orb_stat(_pwmin_sub,timestamp);
    (*pulse_width) = (uint16_t) (*timestamp);
    return;
}*/


#endif
