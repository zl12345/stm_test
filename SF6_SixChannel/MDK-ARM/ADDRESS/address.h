#ifndef ADDRESS_H
#define ADDRESS_H



#include "stm32f1xx_hal.h"
#include "main.h"




u8 getSensorAddress(void);

u8 getSensorType(void);


void USART4_InitConfig(u32 BaudRate);
#endif




