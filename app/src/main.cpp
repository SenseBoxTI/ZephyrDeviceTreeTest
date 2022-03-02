#include "led.hpp"
#include <sys/printk.h>

void main() {

    printk("Board: %s", CONFIG_BOARD);
    
    Led status_led;

    status_led = Led(GPIO_DT_SPEC_GET(DT_ALIAS(statusled), gpios));

    while (true) {    
        status_led.toggle();
        k_msleep(500);
    }

    //noreturn
}
