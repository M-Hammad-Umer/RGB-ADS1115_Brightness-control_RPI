#ifndef ADS1115_h
#define ADS1115_h

#include <stdio.h>
#include <stdint.h>
#include <byteswap.h>


//7-Bit Device Address options
#define DEVICE_ADDR_GND		0x48
#define DEVICE_ADDR_VDD		0x49
#define DEVICE_ADDR_SDA		0x4A
#define DEVICE_ADDR_SCL		0x4B


//Register Addresses
#define ADS1115_CONVERSION_REG_ADDR		0b00000000
#define ADS1115_CONFIG_REG_ADDR			0b00000001
#define ADS1115_LOW_TRESH_REG_ADDR		0b00000010
#define ADS1115_HIGH_TRESH_REG_ADDR		0b00000011

#define resistor 220
#define NO_OF_SAMPLES 5

//Defaults register values
#define ADS1115_CONVERSION_REG_DEF		0x0000
#define ADS1115_CONFIG_REG_DEF			0x8583
#define ADS1115_LOW_TRESH_REG_DEF		0x8000
#define ADS1115_HIGH_TRESH_REG_DEF		0x7FFF

//ADS1115 Analog Channel Single Ended Macros
#define A0 0
#define A1 1
#define A2 2
#define A3 3

// ADS CONFIG REG values when
#define CONFIG_REG_FOR_A0 0x4F3
#define CONFIG_REG_FOR_A1 0x54F3
#define CONFIG_REG_FOR_A2 0x64F3
#define CONFIG_REG_FOR_A3 0x74F3

// Pressure Stuct
typedef struct Pressure
{
	uint16_t PressureKpa;
	float PressurePsi;
	float PressureBar;
}pressure_t;



////////////////////////PUBLIC FUNCTION DECELERATION//////////////////////
void ADS1115_reset(uint8_t fd);
uint16_t ADS1115_Read_Pin(uint8_t fd , uint8_t pinNo);
pressure_t ADS1115_Mean_Value(uint8_t fd , uint8_t pinNo , uint16_t NoOfSamples);
uint32_t ADS1115_RGB_Value(uint8_t fd , uint8_t pinNo , uint16_t NoOfSamples);


#endif