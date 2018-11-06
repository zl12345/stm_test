#include "uart_printf.h"
#include "usart.h"






/**  
* @brief Retargets the C library printf function to the USART.  
* @param None  
* @retval None  
*/  
PUTCHAR_PROTOTYPE  
{  
  /* Place your implementation of fputc here */  
  /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */  
  HAL_UART_Transmit(&huart3, (uint8_t *)&ch, 1, 0x0001);  
  return ch;  
}