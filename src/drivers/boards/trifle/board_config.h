#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include <nuttx/config.h>
#include <stdbool.h>

extern uint32_t __device_id;
#define UDID_START __device_id

#define GPIO_LED0 (PIN_PORTC | PIN5 | GPIO_HIGHDRIVE | GPIO_OUTPUT_ONE)

__EXPORT void led_init(void);

__EXPORT void led_set(int led, bool value);

#endif
