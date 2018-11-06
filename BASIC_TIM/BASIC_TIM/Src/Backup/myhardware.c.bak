#include "myhardware.h"
#include "tim.h"


uint32_t tim6 = 0;

uint32_t tim7 = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

    if(htim == (&htim6))
    {
      tim6++;
      if(tim6 == 1000)
      {

      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
      }else if(tim6 == 2000)
      {
      tim6 = 0;
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);


      }

    }

    if(htim == (&htim7))
    {
      tim7++;
      if(tim7 == 1000)
      {

          HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_5, GPIO_PIN_RESET); //°×É«
      }else if(tim7 == 2000)
      {
        tim7 = 0;
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_5, GPIO_PIN_SET); //°×É«


      }

    }

}

