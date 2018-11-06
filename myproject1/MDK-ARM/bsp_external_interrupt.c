#include "handle_my_hardware.h"





void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
		if(GPIO_Pin ==GPIO_PIN_0)
		{
				open_green_led();

		
		}else if(GPIO_Pin ==GPIO_PIN_13)
		{
				open_blue_led();
		
		}



}
