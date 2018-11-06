#ifndef __BSP_EXTERNAL_INTERRUPT_H
#define __BSP_EXTERNAL_INTERRUPT_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);





#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */
