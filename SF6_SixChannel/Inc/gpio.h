/**
  ******************************************************************************
  * File Name          : gpio.h
  * Description        : This file contains all the functions prototypes for 
  *                      the gpio  
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
#ifndef __gpio_H
#define __gpio_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "main.h"

/* USER CODE BEGIN Includes */
	 
	 /*************控制电磁阀1--6**********/
#define OpenCH0()    HAL_GPIO_WritePin(OUT_CH0_GPIO_Port,OUT_CH0_Pin,GPIO_PIN_RESET);
#define CloseCH0()   HAL_GPIO_WritePin(OUT_CH0_GPIO_Port,OUT_CH0_Pin,GPIO_PIN_SET);
	 
#define OpenCH1()   HAL_GPIO_WritePin(OUT_CH1_GPIO_Port,OUT_CH1_Pin,GPIO_PIN_RESET);
#define CloseCH1()  HAL_GPIO_WritePin(OUT_CH1_GPIO_Port,OUT_CH1_Pin,GPIO_PIN_SET);
	 
#define OpenCH2()  HAL_GPIO_WritePin(OUT_CH2_GPIO_Port,OUT_CH2_Pin,GPIO_PIN_RESET);
#define CloseCH2() HAL_GPIO_WritePin(OUT_CH2_GPIO_Port,OUT_CH2_Pin,GPIO_PIN_SET);

#define OpenCH3()  HAL_GPIO_WritePin(OUT_CH3_GPIO_Port,OUT_CH3_Pin,GPIO_PIN_RESET);
#define CloseCH3() HAL_GPIO_WritePin(OUT_CH3_GPIO_Port,OUT_CH3_Pin,GPIO_PIN_SET);	

#define OpenCH4()  HAL_GPIO_WritePin(OUT_CH4_GPIO_Port,OUT_CH4_Pin,GPIO_PIN_RESET);
#define CloseCH4() HAL_GPIO_WritePin(OUT_CH4_GPIO_Port,OUT_CH4_Pin,GPIO_PIN_SET);	

#define OpenCH5()  HAL_GPIO_WritePin(OUT_CH5_GPIO_Port,OUT_CH5_Pin,GPIO_PIN_RESET);
#define CloseCH5() HAL_GPIO_WritePin(OUT_CH5_GPIO_Port,OUT_CH5_Pin,GPIO_PIN_SET);

#define OpenZERO()  HAL_GPIO_WritePin(OUT_ZERO_GPIO_Port,OUT_ZERO_Pin,GPIO_PIN_RESET);//零点自校准阀
#define CloseZERO() HAL_GPIO_WritePin(OUT_ZERO_GPIO_Port,OUT_ZERO_Pin,GPIO_PIN_SET);

#define OpenPUMP()  HAL_GPIO_WritePin(OUT_PUMP_GPIO_Port,OUT_PUMP_Pin,GPIO_PIN_RESET);//开泵
#define ClosePUMP() HAL_GPIO_WritePin(OUT_PUMP_GPIO_Port,OUT_PUMP_Pin,GPIO_PIN_SET);


#define OpenAlarm1()  HAL_GPIO_WritePin(ALARM1_GPIO_Port,ALARM1_Pin,GPIO_PIN_SET);//报警1输出
#define CloseAlarm1() HAL_GPIO_WritePin(ALARM1_GPIO_Port,ALARM1_Pin,GPIO_PIN_RESET);

#define OpenAlarm2()  HAL_GPIO_WritePin(ALARM2_GPIO_Port,ALARM2_Pin,GPIO_PIN_SET);//报警2输出
#define CloseAlarm2() HAL_GPIO_WritePin(ALARM2_GPIO_Port,ALARM2_Pin,GPIO_PIN_RESET);


#define SpeakerOn()  HAL_GPIO_WritePin(SPEAKE_GPIO_Port,SPEAKE_Pin,GPIO_PIN_SET);//蜂鸣器
#define SpeakerOff() HAL_GPIO_WritePin(SPEAKE_GPIO_Port,SPEAKE_Pin,GPIO_PIN_RESET);

#define OpenInput1() HAL_GPIO_WritePin(IOINPUT1_GPIO_Port,IOINPUT1_Pin,GPIO_PIN_RESET);//输出1
#define CloseInput1() HAL_GPIO_WritePin(IOINPUT1_GPIO_Port,IOINPUT1_Pin,GPIO_PIN_SET);

#define OpenInput2() HAL_GPIO_WritePin(IOINPUT2_GPIO_Port,IOINPUT2_Pin,GPIO_PIN_RESET);//输出2
#define CloseInput2() HAL_GPIO_WritePin(IOINPUT2_GPIO_Port,IOINPUT2_Pin,GPIO_PIN_SET);

//#define RS485OUTSEND() HAL_GPIO_WritePin(RS485EN_OUT_GPIO_Port,RS485EN_OUT_Pin,GPIO_PIN_SET);//输出485 
//#define RS485OUTRCV()  HAL_GPIO_WritePin(RS485EN_OUT_GPIO_Port,RS485EN_OUT_Pin,GPIO_PIN_RESET);

#define RS485READSEND() HAL_GPIO_WritePin(RS485EN_READ_GPIO_Port,RS485EN_READ_Pin,GPIO_PIN_SET);//读取485
#define RS485READRCV()  HAL_GPIO_WritePin(RS485EN_READ_GPIO_Port,RS485EN_READ_Pin,GPIO_PIN_RESET);



	 
	 
	 
/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
