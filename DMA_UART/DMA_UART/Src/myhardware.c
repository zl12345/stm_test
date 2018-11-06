#include "myhardware.h"


// 要发送的数据大小
uint8_t data1[BUFFER_SIZE];
uint8_t data2[BUFFER_SIZE];

uint8_t receive_data[DMA_Rec_Len];

uint8_t send_flag;


void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
		
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0|GPIO_PIN_1,GPIO_PIN_SET);  //红色



}



 void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart)
{
		
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);  //蓝色


}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

	send_flag = START_SEND;
	


}
