/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */
#include <stdint.h>
typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef volatile uint32_t  vu32;
typedef volatile uint16_t vu16;
typedef volatile uint8_t  vu8;




/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define OUT_CH4_Pin GPIO_PIN_0
#define OUT_CH4_GPIO_Port GPIOA
#define OUT_CH5_Pin GPIO_PIN_1
#define OUT_CH5_GPIO_Port GPIOA
#define OUT_ZERO_Pin GPIO_PIN_2
#define OUT_ZERO_GPIO_Port GPIOA
#define OUT_PUMP_Pin GPIO_PIN_3
#define OUT_PUMP_GPIO_Port GPIOA
#define ADDR1_Pin GPIO_PIN_4
#define ADDR1_GPIO_Port GPIOA
#define ADDR2_Pin GPIO_PIN_5
#define ADDR2_GPIO_Port GPIOA
#define ADDR3_Pin GPIO_PIN_6
#define ADDR3_GPIO_Port GPIOA
#define ADDR4_Pin GPIO_PIN_7
#define ADDR4_GPIO_Port GPIOA
#define ADDR5_Pin GPIO_PIN_4
#define ADDR5_GPIO_Port GPIOC
#define ADDR6_Pin GPIO_PIN_5
#define ADDR6_GPIO_Port GPIOC
#define ADDR7_Pin GPIO_PIN_0
#define ADDR7_GPIO_Port GPIOB
#define ADDR8_Pin GPIO_PIN_1
#define ADDR8_GPIO_Port GPIOB
#define TYPE2_Pin GPIO_PIN_12
#define TYPE2_GPIO_Port GPIOB
#define TYPE1_Pin GPIO_PIN_13
#define TYPE1_GPIO_Port GPIOB
#define RS485EN_READ_Pin GPIO_PIN_14
#define RS485EN_READ_GPIO_Port GPIOB
#define WORK_LED_Pin GPIO_PIN_11
#define WORK_LED_GPIO_Port GPIOA
#define SPEAKE_Pin GPIO_PIN_12
#define SPEAKE_GPIO_Port GPIOA
#define RS485EN_OUT_Pin GPIO_PIN_15
#define RS485EN_OUT_GPIO_Port GPIOA
#define ALARM1_Pin GPIO_PIN_2
#define ALARM1_GPIO_Port GPIOD
#define ALARM2_Pin GPIO_PIN_3
#define ALARM2_GPIO_Port GPIOB
#define IOINPUT1_Pin GPIO_PIN_4
#define IOINPUT1_GPIO_Port GPIOB
#define IOINPUT2_Pin GPIO_PIN_5
#define IOINPUT2_GPIO_Port GPIOB
#define OUT_CH0_Pin GPIO_PIN_6
#define OUT_CH0_GPIO_Port GPIOB
#define OUT_CH1_Pin GPIO_PIN_7
#define OUT_CH1_GPIO_Port GPIOB
#define OUT_CH2_Pin GPIO_PIN_8
#define OUT_CH2_GPIO_Port GPIOB
#define OUT_CH3_Pin GPIO_PIN_9
#define OUT_CH3_GPIO_Port GPIOB

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
