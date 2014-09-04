
#ifndef __AP_HAL_EMPTY_PWMINPUT_H__
#define __AP_HAL_EMPTY_PWMINPUT_H__

#include <AP_HAL_Empty.h>

class Empty::EmptyPWMInput : public AP_HAL::PWMInput {
public:
    void init(void* unused);
    bool new_input();
    bool read(uint64_t &timestamp, uint64_t &errors, uint32_t &pulse_width, uint32_t &period);
};

#endif // __AP_HAL_EMPTY_PWMINPUT_H__
