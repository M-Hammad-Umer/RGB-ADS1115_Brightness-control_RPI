#include <stdio.h>
#include <stdint.h>
#include <pigpio.h>
#include "RGB.h"



void RGB(uint8_t color , uint8_t brightness)
{
    gpioSetPWMfrequency(color , GPIO_FREQUENCY);
    switch (color)
    {
    case RED:
        gpioPWM(color , brightness);
        gpioPWM(BLUE , 0);
        gpioPWM(GREEN , 0);
        break;
    case BLUE:
        gpioPWM(color , brightness);
        gpioPWM(RED , 0);
        gpioPWM(GREEN , 0);
        break;
    case GREEN:
        gpioPWM(color , brightness);
        gpioPWM(BLUE , 0);
        gpioPWM(RED , 0);
        break;
    }
    
}

void RGB_make_color(uint8_t red , uint8_t green , uint8_t blue)
{
    gpioSetPWMfrequency(RED , GPIO_FREQUENCY_RED);
    gpioSetPWMfrequency(GREEN , GPIO_FREQUENCY_GREEN);
    gpioSetPWMfrequency(BLUE , GPIO_FREQUENCY_BLUE);
    gpioPWM(RED , red);
    gpioPWM(GREEN , green);
    gpioPWM(BLUE , blue);
}