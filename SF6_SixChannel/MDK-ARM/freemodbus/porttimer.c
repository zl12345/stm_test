/*
 * FreeModbus Libary: BARE Port
 * Copyright (C) 2006 Christian Walter <wolti@sil.at>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * File: $Id: porttimer.c,v 1.1 2006/08/22 21:35:13 wolti Exp $
 *
 */

/* ----------------------- Platform includes --------------------------------*/
#include "port.h"
#include "stm32f1xx_hal.h"

#include "bsp_GeneralTIM.h"
/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbport.h"
#include "measure.h"
#include "tim.h"
#include "memory.h"
/* ----------------------- static functions ---------------------------------*/
//void prvvTIMERExpiredISR( void );

/* ----------------------- Start implementation -----------------------------*/
BOOL xMBPortTimersInit( USHORT usTim1Timerout50us )
{
  GENERAL_TIMx_Init();
  
	return TRUE;;
}

inline void vMBPortTimersEnable(  )
{
  /* Enable the timer with the timeout passed to xMBPortTimersInit( ) */
  __HAL_TIM_CLEAR_IT(&htimx,TIM_IT_UPDATE);
  __HAL_TIM_SET_COUNTER(&htimx,0);
  
  /* 在中断模式下启动定时器 */
  HAL_TIM_Base_Start_IT(&htimx);
}

inline void vMBPortTimersDisable(  )
{
  /* Disable any pending timers. */
  HAL_TIM_Base_Stop_IT(&htimx);
  
  __HAL_TIM_SET_COUNTER(&htimx,0);
  __HAL_TIM_CLEAR_IT(&htimx,TIM_IT_UPDATE);  
}

/* Create an ISR which is called whenever the timer has expired. This function
 * must then call pxMBPortCBTimerExpired( ) to notify the protocol stack that
 * the timer has expired.
 */
void prvvTIMERExpiredISR( void )
{
  ( void )pxMBPortCBTimerExpired();
}

/**
  * 函数功能: 非阻塞模式下定时器的回调函数
  * 输入参数: htim：定时器句柄
  * 返 回 值: 无
  * 说    明: 无
  */
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)//注释3
//{
//  prvvTIMERExpiredISR();
//}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
    
		//100ms的定时器
    if (htim->Instance == TIM3){
       
        Kernel.ms++;//运行10ms
		  if(Kernel.ms>100)
		  {
			  Kernel.ms=0;
			  Kernel.second++;
			  if(measure.sersor_comm_flag==1)
			  {
				  HAL_GPIO_TogglePin(WORK_LED_GPIO_Port,WORK_LED_Pin);
			  }
			  else
			  {
				  HAL_GPIO_WritePin(WORK_LED_GPIO_Port,WORK_LED_Pin,GPIO_PIN_RESET);
			  }
			  
			  if(measure.read_sensor_period>0)measure.read_sensor_period--;
			  switch(measure.step)
				{
				  case STEP_ZERO:
					  if(measure.zerotime>0)measure.zerotime--;
					  break;
				  case STEP_MEASURE:
					  if(measure.measuretime>0)measure.measuretime--;
				  break;
				  case STEP_CHANGE:
					  if(measure.changetime>0)measure.changetime--;
				  break;
				  case STEP_PAUSE:
					  if(measure.pausetime>0)measure.pausetime--;
				  break;
				  case STEP_STOP:
					  if(measure.stoptime>0)measure.stoptime--;
				  break;				
				}
			  if(Kernel.second>=60)
			  {
				  Kernel.second=0;
				  Kernel.minute++;
				   
			  }			 
		  }				
    }
	 if(htim->Instance==GENERAL_TIMx)
	{
		 prvvTIMERExpiredISR();
   }
	 
}
