/****************************************************************************
 *
 *   Copyright (C) 2015 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file drv_pwm_servo.h
 *
 * kinetis-specific PWM output data.
 */
#ifndef KINETIS_PWM_SERVO_H
#define KINETIS_PWM_SERVO_H

#define PWM_SERVO_MAX_TIMERS 1
#define PWM_SERVO_MAX_CHANNELS 6

#include <stdbool.h>
#include <drivers/drv_pwm_output.h>

/**
 * Flex timer module dedicated to PWM servo use 
 *
 */
struct pwm_servo_timer {

  /** Base memory address of timer module. */
  uint32_t ftm_base;

  /** Address of clock gating control register responsible
   * for the given timer module. */
  uint32_t scgc;

  /** Bitmask to enable clock input to the timer module. */
  uint32_t scgc_enable;
  
};

/**
 * Logical servo output channel 
 */
struct pwm_servo_channel {

  /** Pointer to the underlying timer structure. */
  const struct pwm_servo_timer* timer;

  /** Channel number of the underlying flex module timer. */
  uint8_t ftm_channel;

  /** Configuration of output pin, this value is passed to kinetis_pinconfig. */
  uint32_t pinconfig;

};

__EXPORT extern const struct pwm_servo_timer pwm_servo_timers[PWM_SERVO_MAX_TIMERS];

/** 
 * All available servo channels. Board specific.
 * Essentially, this array maps logical channel numbers to system-specific channel structures.
 */
__EXPORT extern const struct pwm_servo_channel pwm_servo_channels[PWM_SERVO_MAX_CHANNELS];

#endif
