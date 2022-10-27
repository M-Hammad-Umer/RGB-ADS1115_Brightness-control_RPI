#include <stdio.h>
#include <stdint.h>
#include <pigpio.h>

#define  BLUE 21
#define  RED  20
#define  GREEN 16

#define GPIO_FREQUENCY 100000  
#define GPIO_FREQUENCY_RED 100000
#define GPIO_FREQUENCY_GREEN 100000
#define GPIO_FREQUENCY_BLUE 100000

void RGB(uint8_t color , uint8_t brigtness);
void RGB_make_color(uint8_t red , uint8_t green , uint8_t blue);

