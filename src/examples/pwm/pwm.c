#include <nuttx/config.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>

#include <drivers/drv_pwm_output.h>

__EXPORT int pwm_main(int argc, char *argv[]);

int pwm_main(int args, char *argv[]) {
  uint8_t channel = (uint8_t) atoi(argv[1]);
  uint16_t us = (uint16_t) atoi(argv[2]);
  
  printf("set pwm channel %d to %d us\n", channel, us);

  up_pwm_servo_init(1 << channel);
  up_pwm_servo_arm(true);
  up_pwm_servo_set(channel, us);
  return 0;
}
