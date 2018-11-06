#include "handle_my_hardware.h"









//配置 GPIOB pin0 pin1 pin5为输出模式
void test_my_teststm32_led()
{
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);

		HAL_Delay(1000);

		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);


		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);

		HAL_Delay(1000);

		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);


		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);
		HAL_Delay(1000);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);

		HAL_Delay(1000);


}


//按键1按下亮蓝灯 在 GPIOA pin0输入模式下
void test_my_teststm32_key1()
{
		
	 if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)==GPIO_PIN_SET)
	 {
			open_blue_led();

			
	 
	 }
}






//按键1按下亮绿灯 在GPIOC pin13输入模式下
void test_my_teststm32_key2()
{
		


		if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13)==GPIO_PIN_SET)
		{
				open_green_led();

		}




}


void open_blue_led()
{
		 //清灯
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
			
			
			
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);

}


void open_green_led()
{
//清灯
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
			
			
			
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);

}

