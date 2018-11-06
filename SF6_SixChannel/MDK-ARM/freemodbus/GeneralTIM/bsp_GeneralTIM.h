#ifndef __GENERAL_TIM_H__
#define __GENERAL_TIM_H__

/* ����ͷ�ļ� ----------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* ���Ͷ��� ------------------------------------------------------------------*/
/* �궨�� --------------------------------------------------------------------*/
/********************ͨ�ö�ʱ��TIM�������壬TIM2~TIM5************/
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

// ���嶨ʱ��Ԥ��Ƶ����ʱ��ʵ��ʱ��Ƶ��Ϊ��84MHz/��GENERAL_TIM_PRESCALER+1��
#define GENERAL_TIM_PRESCALER           (6400-1)  // ʵ��ʱ��Ƶ��Ϊ��1MHz
// ���嶨ʱ�����ڣ�����ʱ����ʼ������BASIC_TIMx_PERIODֵ�Ǹ��¶�ʱ�������ɶ�Ӧ�¼����ж�
#define GENERAL_TIM_PERIOD              50  // ��ʱ�������ж�Ƶ��Ϊ��1MHz/1000=1KHz����1ms��ʱ����

// ���ն�ʱ��Ƶ�ʼ���Ϊ�� 84MHz/��GENERAL_TIM_PRESCALER+1��/GENERAL_TIM_PERIOD
// ������Ҫ����20ms���ڶ�ʱ����������Ϊ�� 84MHz/��83+1��/1000=1Hz����1ms����
// �������� GENERAL_TIM_PRESCALER=83��GENERAL_TIM_PERIOD=1000��

/* ��չ���� ------------------------------------------------------------------*/
extern TIM_HandleTypeDef htimx;

/* �������� ------------------------------------------------------------------*/

void GENERAL_TIMx_Init(void);

#endif	/* __GENERAL_TIM_H__ */
/******************* (C) COPYRIGHT 2015-2020 ӲʯǶ��ʽ�����Ŷ� *****END OF FILE****/
