
#ifndef __AP_HAL_PX4_PWMINPUT_H__
#define __AP_HAL_PX4_PWMINPUT_H__

#include <AP_HAL_PX4.h>
#include <drivers/drv_hrt.h>
#include <systemlib/perf_counter.h>
#include <pthread.h>
#include <uORB/uORB.h>
#include <uORB/topics/pwm_input.h>

class PX4::PX4PWMInput : public AP_HAL::PWMInput {
public:
    void init(void* unused);
    bool new_input();
    void read(uint64_t * timestamp, uint64_t* errors, uint16_t * pulse_width, uint16_t * period);

    void _timer_tick(void);

private:
    /* override state */
    struct pwm_input_s _pwmin;
    int _pwmin_sub;
    uint64_t _last_read;
//    perf_counter_t _perf_pwmin;
    pthread_mutex_t pwmin_mutex;
};

#endif // __AP_HAL_PX4_RCINPUT_H__
