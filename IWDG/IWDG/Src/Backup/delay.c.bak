#include "delay.h"




	int fac_us;



	void delay_init(int SYSCLK)
	{
	
	/* SystemFrequency / 1000          1ms中断一次
* SystemFrequency / 100000       10us中断一次
* SystemFrequency / 1000000     1us中断一次
*/

	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
	//SysTick频率为HCLK
	fac_us=SYSCLK; //不论是否使用OS,fac_us都需要使用

	}
	
	
void delay_us(uint32_t nus)
{
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
	fac_us=SystemCoreClock / 1000000; 
	
	uint32_t ticks;
	uint32_t told,tnow,tcnt=0;
	uint32_t reload=SysTick->LOAD; //LOAD的值
	ticks=nus*fac_us; //需要的节拍数
	told=SysTick->VAL; //刚进入时的计数器值
	while(1)
	{
		tnow=SysTick->VAL;
		
		if(tnow!=told)
		{
			if(tnow<told)
					tcnt+=told-tnow;//这里注意SYSTICK是递减的计数器就可以.
			else 
					tcnt+=reload-tnow+told;
			
			
			told=tnow;
			
		if(tcnt>=ticks)
			break; //时间超过/等于要延迟的时间,则退出.
		}
	};
}



void delay_ms(uint32_t nms)
{
	uint32_t i;
	for(i=0;i< nms;i++) 
		delay_us(1000);
}
