#include <nuttx/config.h>
#include <stdio.h>
#include <errno.h>
#include <chip.h>
#include <kinetis_ftm.h>
#include <kinetis_internal.h>
#include <up_arch.h>
#include <kinetis_sim.h>

#include <drivers/kinetis/drv_pwm_servo.h>


__EXPORT const struct  pwm_servo_timer pwm_servo_timers[PWM_SERVO_MAX_TIMERS] = {
  {
    .ftm_base = KINETIS_FTM0_BASE,
    .scgc = KINETIS_SIM_SCGC6,
    .scgc_enable = 1 << 24
  }
};

__EXPORT const struct pwm_servo_channel pwm_servo_channels[PWM_SERVO_MAX_CHANNELS] = {
  {
    .timer = &pwm_servo_timers[0],
    .ftm_channel = 5,
    .pinconfig = PIN_PORTD | PIN5 |  PIN_ALT4_OUTPUT | PIN_ALT4_HIGHDRIVE
  }
};
