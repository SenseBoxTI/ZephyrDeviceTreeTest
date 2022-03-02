#include "led.hpp"

Led::Led() {}

Led::Led(gpio_dt_spec device) {
    m_device = device;

    if (!device_is_ready(m_device.port)) {
        // throw "LED is not ready.";
    }

    if (gpio_pin_configure_dt(&m_device, GPIO_OUTPUT_ACTIVE)) {
        // throw "Failed to configure LED device";
    }
}

void Led::toggle() {
    if (gpio_pin_toggle_dt(&m_device) < 0) {
        // throw "Failed to toggle LED";
    }
}