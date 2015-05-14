#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include <nuttx/config.h>
#include <stdbool.h>

//totally random
#define UDID_START 0x2000000

#define GPIO_LED0 (PIN_PORTC | PIN5 | GPIO_HIGHDRIVE | GPIO_OUTPUT_ONE)

__EXPORT void led_init(void);

__EXPORT void led_set(int led, bool value);

#endif
