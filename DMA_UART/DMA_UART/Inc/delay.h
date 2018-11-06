#ifndef __DELAY_H
#define __DELAY_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"


void delay_init(int SYSCLK);



void delay_us(uint32_t nus);

void delay_ms(uint32_t nms);


//void SysTick_Delay_Us( __IO uint32_t us);

//void SysTick_Delay_Ms( __IO uint32_t ms);



#ifdef __cplusplus
}
#endif

#endif /*__ pinoutConfig_H */
