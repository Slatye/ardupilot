#include <AP_HAL.h>

#include "PWMInput.h"

using namespace Empty;

void EmptyPWMInput::init(void* unused)
{}

// New data has never been received.
bool EmptyPWMInput::new_input() {
    return false;
}

bool EmptyPWMInput::read(uint64_t & timestamp, uint64_t & errors, uint32_t & pulse_width, uint32_t & period) 
{
    timestamp = 0;
    errors = 0;
    pulse_width = 0;
    period = 0;
    return false;
}

