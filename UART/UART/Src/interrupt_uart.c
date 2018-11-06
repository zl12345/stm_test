
#include "interrupt_uart.h"
#include "usart.h"
#include "stm32f1xx.h"
#include "stm32f1xx_hal.h"

uint8_t usart_interrupt_data;


void my_uart1()
{
//	HAL_UART_Transmit(&huart1, (uint8_t *)&usart_interrupt_data, 1, 0x0001);  


//	HAL_UART_Receive_IT(&huart1,&usart_interrupt_data,1);//(USART1->DR); //读取接收到的数据 
//	
//	printf("%c",usart_interrupt_data);


}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{


	
			HAL_UART_Transmit(&huart1, (uint8_t *)&usart_interrupt_data, 1, 0x0001);  

			HAL_UART_Receive_IT(&huart1,&usart_interrupt_data,1);//(USART1->DR); //读取接收到的数据 
	
			printf("%c",usart_interrupt_data);





}




