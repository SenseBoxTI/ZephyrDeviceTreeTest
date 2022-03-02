#pragma once
#include <drivers/gpio.h>

class Led {
    gpio_dt_spec m_device;

public:
    void toggle();
    Led();
    Led(gpio_dt_spec device);
};