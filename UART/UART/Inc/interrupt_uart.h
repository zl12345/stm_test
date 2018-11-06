#ifndef __INTERRUPT_UART__
#define __INTERRUPT_UART__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */
#include "stm32f1xx.h"

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif


extern uint8_t usart_interrupt_data;
extern void my_uart1();
extern void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);



#ifdef __cplusplus
}
#endif

#endif /* __INTERRUPT_UART__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
