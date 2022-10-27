#include <stdio.h>
#include <stdint.h>
#include "./ADS1115.h"
#include "RGB.h"
#include <byteswap.h>
#include <pigpio.h>



int main()
{
	if(gpioInitialise() < 0)
	{
		fprintf(stderr, "GPIO Initialization Failed \n");
		return 1;
	}
	uint8_t fd = i2cOpen(1 , DEVICE_ADDR_GND , 0);	

	while(1)
	{
		uint32_t R = ADS1115_RGB_Value(fd , A1 , NO_OF_SAMPLES);
		uint32_t G = ADS1115_RGB_Value(fd , A2 , NO_OF_SAMPLES);
		uint32_t B = ADS1115_RGB_Value(fd , A3 , NO_OF_SAMPLES);
		RGB_make_color(R , G , B);
		printf("R = %d 		G = %d 		B = %d		 \n",R, G , B);
		gpioDelay(10000);

    }
}


// gcc -Wall -o main main.c ADS1115.c RGB.c -lpigpio -lrt
// sudo ./main




