#ifndef __MYHARDWARE_H
#define __MYHARDWARE_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

#define LED_CLOSE {HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_5, GPIO_PIN_SET);}

#define LED_RED  {HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_5, GPIO_PIN_RESET); \
                  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0|GPIO_PIN_1,GPIO_PIN_SET);  }//��ɫ
    
#define LED_BLUE  {HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_5, GPIO_PIN_RESET); \
                  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0|GPIO_PIN_5,GPIO_PIN_SET);    }//��ɫ
    

#define LED_GREEN {HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_5, GPIO_PIN_RESET); \
                  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1|GPIO_PIN_5,GPIO_PIN_SET);  }//��ɫ




#ifdef __cplusplus
}
#endif

#endif /*__ pinoutConfig_H */
