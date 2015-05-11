#include <nuttx/config.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>

#include <drivers/drv_pwm_output.h>

__EXPORT int pwm_main(int argc, char *argv[]);

int pwm_main(int args, char *argv[]) {
  printf("set pwm0 to %d us\n", atoi(argv[1]));

  up_pwm_servo_init(1);
  up_pwm_servo_arm(true);
  up_pwm_servo_set(0, atoi(argv[1]));
  return 0;
}
