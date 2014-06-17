
#ifndef __AP_HAL_PWM_INPUT_H__
#define __AP_HAL_PWM_INPUT_H__

#include "AP_HAL_Namespace.h"

class AP_HAL::PWMInput {
public:
    
    virtual void init(void* implspecific) = 0;

    /**
     * Return true if there has been new input since the last read() call
     */
    virtual bool  new_input() = 0;

    /* Read a single channel at a time */
    virtual void read(uint64_t * timestamp, uint64_t* errors, uint32_t * pulse_width, uint32_t * period) = 0;


};

#endif // __AP_HAL_RC_INPUT_H__

