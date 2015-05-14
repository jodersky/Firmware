#include "board_config.h"
#include "kinetis_internal.h"


void
led_init(void)
{
	kinetis_pinconfig(GPIO_LED0);
}

void led_set(int led, bool value)
{
	switch(led) {
	case 0:
		kinetis_gpiowrite(led, value);
		break;
	default:
		return;
	}
}
