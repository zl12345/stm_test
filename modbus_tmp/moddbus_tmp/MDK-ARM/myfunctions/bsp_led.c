#include "bsp_led.h"





void open_blue_led()
{
		 //���
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
			
			
			
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);

}


void open_green_led()
{
//���
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
			
			
			
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);

}


void open_red_led()
{
//���
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
			
			
			
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);

}




