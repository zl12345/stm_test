#ifndef __GENERAL_TIM_H__
#define __GENERAL_TIM_H__

/* 包含头文件 ----------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* 类型定义 ------------------------------------------------------------------*/
/* 宏定义 --------------------------------------------------------------------*/
/********************通用定时器TIM参数定义，TIM2~TIM5************/
#define GENERAL_TIMx                     TIM2
#define GENERAL_TIM_RCC_CLK_ENABLE()     __HAL_RCC_TIM2_CLK_ENABLE()
#define GENERAL_TIM_RCC_CLK_DISABLE()    __HAL_RCC_TIM2_CLK_DISABLE()
#define GENERAL_TIM_IRQ                  TIM2_IRQn
#define GENERAL_TIM_INT_FUN              TIM2_IRQHandler

//#define GENERAL_TIMx                     TIM3
//#define GENERAL_TIM_RCC_CLK_ENABLE()     __HAL_RCC_TIM3_CLK_ENABLE()
//#define GENERAL_TIM_RCC_CLK_DISABLE()    __HAL_RCC_TIM3_CLK_DISABLE()
//#define GENERAL_TIM_IRQ                  TIM3_IRQn
//#define GENERAL_TIM_INT_FUN              TIM3_IRQHandler

//#define GENERAL_TIMx                     TIM4
//#define GENERAL_TIM_RCC_CLK_ENABLE()     __HAL_RCC_TIM4_CLK_ENABLE()
//#define GENERAL_TIM_RCC_CLK_DISABLE()    __HAL_RCC_TIM4_CLK_DISABLE()
//#define GENERAL_TIM_IRQ                  TIM4_IRQn
//#define GENERAL_TIM_INT_FUN              TIM4_IRQHandler

//#define GENERAL_TIMx                     TIM5
//#define GENERAL_TIM_RCC_CLK_ENABLE()     __HAL_RCC_TIM5_CLK_ENABLE()
//#define GENERAL_TIM_RCC_CLK_DISABLE()    __HAL_RCC_TIM5_CLK_DISABLE()
//#define GENERAL_TIM_IRQ                  TIM5_IRQn
//#define GENERAL_TIM_INT_FUN              TIM5_IRQHandler

// 定义定时器预分频，定时器实际时钟频率为：84MHz/（GENERAL_TIM_PRESCALER+1）
#define GENERAL_TIM_PRESCALER           (6400-1)  // 实际时钟频率为：1MHz
// 定义定时器周期，当定时器开始计数到BASIC_TIMx_PERIOD值是更新定时器并生成对应事件和中断
#define GENERAL_TIM_PERIOD              50  // 定时器产生中断频率为：1MHz/1000=1KHz，即1ms定时周期

// 最终定时器频率计算为： 84MHz/（GENERAL_TIM_PRESCALER+1）/GENERAL_TIM_PERIOD
// 比如需要产生20ms周期定时，可以设置为： 84MHz/（83+1）/1000=1Hz，即1ms周期
// 这里设置 GENERAL_TIM_PRESCALER=83；GENERAL_TIM_PERIOD=1000；

/* 扩展变量 ------------------------------------------------------------------*/
extern TIM_HandleTypeDef htimx;

/* 函数声明 ------------------------------------------------------------------*/

void GENERAL_TIMx_Init(void);

#endif	/* __GENERAL_TIM_H__ */
/******************* (C) COPYRIGHT 2015-2020 硬石嵌入式开发团队 *****END OF FILE****/
