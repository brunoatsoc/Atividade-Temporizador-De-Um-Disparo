#include <stdio.h>
#include "pico/stdlib.h"

#define PIN_RED_LED 12
#define PIN_GREEN_LED 13
#define PIN_BLUE_LED 11
#define PIN_BUTTON 5

bool LED_ACTIVE = false;
volatile int STATE = 0;

void initialze_gpio_pin();
int64_t turn_off_callback(alarm_id_t id, void *user_data);

int main() {
    stdio_init_all();
    initialze_gpio_pin();

    while (true) {
        if(gpio_get(PIN_BUTTON) == 0 && !LED_ACTIVE) {
            sleep_ms(50);

            if(gpio_get(PIN_BUTTON) == 0) {
                gpio_put(PIN_RED_LED, true);
                gpio_put(PIN_GREEN_LED, true);
                gpio_put(PIN_BLUE_LED, true);

                LED_ACTIVE = true;
                STATE = 1;
                add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            }
        }

        sleep_ms(10);
    }
}

void initialze_gpio_pin() {
    gpio_init(PIN_RED_LED);
    gpio_set_dir(PIN_RED_LED, GPIO_OUT);

    gpio_init(PIN_GREEN_LED);
    gpio_set_dir(PIN_GREEN_LED, GPIO_OUT);

    gpio_init(PIN_BLUE_LED);
    gpio_set_dir(PIN_BLUE_LED, GPIO_OUT);

    gpio_init(PIN_BUTTON);
    gpio_set_dir(PIN_BUTTON, GPIO_IN);
    gpio_pull_up(PIN_BUTTON);
}

int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    if(STATE == 1) {
        gpio_put(PIN_BLUE_LED, false);
        STATE = 2;
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    } else if(STATE == 2) {
        gpio_put(PIN_RED_LED, false);
        STATE = 3;
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    } else if(STATE == 3) {
        gpio_put(PIN_GREEN_LED, false);
        STATE = 0;
        LED_ACTIVE = false;
    }

    return 0;
}
