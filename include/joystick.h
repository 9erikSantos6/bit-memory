#ifndef JOYSTICK_H
#define JOYSTICK_h

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

#define BAR_WIDTH 40
#define ADC_MAX ((1 << 12) - 1)

void init_adc();

uint read_adc_value(uint input);

void display_joystick(uint adc_x_raw, uint adc_y_raw);

#endif 