#ifndef __MYHARDWARE_H
#define __MYHARDWARE_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"


extern void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);


extern void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart);

#define BUFFER_SIZE     30
#define DMA_Rec_Len 10      
#define START_SEND  ((uint8_t)1)
#define END_SEND  ((uint8_t)0)



extern uint8_t data1[BUFFER_SIZE];
extern uint8_t data2[BUFFER_SIZE];

extern uint8_t receive_data[DMA_Rec_Len];

extern uint8_t send_flag;


#ifdef __cplusplus
}
#endif

#endif /*__ pinoutConfig_H */
