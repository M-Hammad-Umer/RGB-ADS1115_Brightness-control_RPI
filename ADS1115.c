#include <stdio.h>
#include <stdint.h>
#include "./ADS1115.h"
#include <byteswap.h>
#include <pigpio.h>


uint16_t samples[NO_OF_SAMPLES];
uint16_t mean = 0;


//////////////////////PRIVATE FUNCTION ECLERATION//////////////////////////////
static void ADS1115_write_register(uint8_t fd , uint8_t regAddr, uint16_t data);
static uint16_t ADS1115_read_register(uint8_t fd , uint8_t regAddr);




////////////////////////PUBLIC FUNCTION DEFINITION//////////////////////

void ADS1115_reset(uint8_t fd)
{
	ADS1115_write_register(fd , ADS1115_CONFIG_REG_ADDR , ADS1115_CONFIG_REG_DEF);
	ADS1115_write_register(fd , ADS1115_LOW_TRESH_REG_ADDR , ADS1115_LOW_TRESH_REG_DEF);
	ADS1115_write_register(fd , ADS1115_HIGH_TRESH_REG_ADDR , ADS1115_HIGH_TRESH_REG_DEF);
}




uint16_t ADS1115_Read_Pin(uint8_t fd ,uint8_t pinNo)
{
	uint16_t swaped = 0x0000;
	uint16_t result = 0x0000;
	ADS1115_reset(fd);
	
	if(pinNo == A0)
		{
			swaped = __bswap_16(CONFIG_REG_FOR_A0);
			ADS1115_write_register(fd , ADS1115_CONFIG_REG_ADDR , swaped);
		}
	else if(pinNo == A1)
		{
			swaped = __bswap_16(CONFIG_REG_FOR_A1);
			ADS1115_write_register(fd , ADS1115_CONFIG_REG_ADDR , swaped);
		}
	else if(pinNo == A2)
		{
			swaped = __bswap_16(CONFIG_REG_FOR_A2);
			ADS1115_write_register(fd , ADS1115_CONFIG_REG_ADDR , swaped);
		}
	else if(pinNo == A3)
		{
			swaped = __bswap_16(CONFIG_REG_FOR_A3);
			ADS1115_write_register(fd , ADS1115_CONFIG_REG_ADDR , swaped);
		}
	
	result = ADS1115_read_register(fd , ADS1115_CONVERSION_REG_ADDR);
	result = __bswap_16(result);
	return(result);
}



pressure_t ADS1115_Mean_Value(uint8_t fd , uint8_t pinNo , uint16_t NoOfSamples)
{
	uint32_t sum = 0;
	pressure_t pressure;
		for(uint16_t i = 0 ; i < NO_OF_SAMPLES ; i++)
			{
				samples[i] =  ADS1115_Read_Pin(fd , pinNo);
				sum = sum + samples[i];	
			}
	mean = sum/NoOfSamples;
	pressure.PressureKpa = (0.0316*(mean)-900.41);   //424.41
	pressure.PressurePsi = (pressure.PressureKpa * 0.145038);
	pressure.PressureBar = (pressure.PressureKpa * 0.01);
	return pressure;
}



uint32_t ADS1115_RGB_Value(uint8_t fd , uint8_t pinNo , uint16_t NoOfSamples)
{
	uint32_t sum = 0;
		for(uint16_t i = 0 ; i < NO_OF_SAMPLES ; i++)
			{
				samples[i] =  ADS1115_Read_Pin(fd , pinNo);
				sum = sum + samples[i];	
			}
	mean = sum/NoOfSamples;
	uint8_t led =(0.007786021800861042*mean) - 104.09911147751211;
	
	return led;
}



//////////////////////PRIVATE FUNCTION DEFINITION//////////////////////////////
static void ADS1115_write_register(uint8_t fd , uint8_t regAddr , uint16_t data)
{
	i2cWriteWordData(fd , regAddr , data);
}



static uint16_t ADS1115_read_register(uint8_t fd , uint8_t regAddr)
{
	uint16_t buffer = i2cReadWordData(fd , regAddr); 
	return buffer;
}
