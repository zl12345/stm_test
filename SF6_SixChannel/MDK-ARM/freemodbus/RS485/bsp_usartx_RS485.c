/**
  ******************************************************************************
  * �ļ�����: bsp_usartx_RS485.c 
  * ��    ��: ӲʯǶ��ʽ�����Ŷ�
  * ��    ��: V1.0
  * ��д����: 2017-03-30
  * ��    ��: ���ش��ڵײ���������
  ******************************************************************************
  * ˵����
  * ����������Ӳʯstm32������YS-F4Proʹ�á�
  * 
  * �Ա���
  * ��̳��http://www.ing10bbs.com
  * ��Ȩ��ӲʯǶ��ʽ�����Ŷ����У��������á�
  ******************************************************************************
  */

/* ����ͷ�ļ� ----------------------------------------------------------------*/
#include "bsp_usartx_RS485.h"

/* ˽�����Ͷ��� --------------------------------------------------------------*/
/* ˽�к궨�� ----------------------------------------------------------------*/
/* ˽�б��� ------------------------------------------------------------------*/
UART_HandleTypeDef husartx_rs485;

/* ��չ���� ------------------------------------------------------------------*/
/* ˽�к���ԭ�� --------------------------------------------------------------*/
/* ������ --------------------------------------------------------------------*/
/**
  * ��������: RS485ͨ�Ź�������GPIO��ʼ��
  * �������: ��
  * �� �� ֵ: ��
  * ˵    ������
  */
void RS485_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  
//  /* ��������ʱ��ʹ�� */
  RS485_USART_RCC_CLK_ENABLE();
  RS485_USARTx_GPIO_ClK_ENABLE();
  RS485_REDE_GPIO_ClK_ENABLE();
  
  /* �������蹦��GPIO���� */
  GPIO_InitStruct.Pin = RS485_USARTx_Tx_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(RS485_USARTx_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = RS485_USARTx_Rx_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(RS485_USARTx_PORT, &GPIO_InitStruct);
  
#if USE_RS485==1  
//  /* SP3485E��������ʹ�ܿ������ų�ʼ�� */
  HAL_GPIO_WritePin(RS485_REDE_PORT,RS485_REDE_PIN,GPIO_PIN_RESET);
  GPIO_InitStruct.Pin = RS485_REDE_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(RS485_REDE_PORT, &GPIO_InitStruct);
  RS485_RX_MODE();
#endif  
}

/**
  * ��������: ���ڲ�������.
  * �������: ��
  * �� �� ֵ: ��
  * ˵    ������
  */
void RS485_USARTx_Init(void)
{ 
  /* RS485ͨ�Ź�������GPIO��ʼ�� */
  RS485_GPIO_Init();
  
  husartx_rs485.Instance = RS485_USARTx;
  husartx_rs485.Init.BaudRate = RS485_USARTx_BAUDRATE;
  husartx_rs485.Init.WordLength = UART_WORDLENGTH_8B;
  husartx_rs485.Init.StopBits = UART_STOPBITS_1;
  husartx_rs485.Init.Parity = UART_PARITY_NONE;
  husartx_rs485.Init.Mode = UART_MODE_TX_RX;
  husartx_rs485.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  husartx_rs485.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&husartx_rs485);
  __HAL_UART_ENABLE(&husartx_rs485);
  
  /* USART1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(USARTx_IRQn, 0, 2);
  HAL_NVIC_EnableIRQ(USARTx_IRQn);    
}

/******************* (C) COPYRIGHT 2015-2020 ӲʯǶ��ʽ�����Ŷ� *****END OF FILE****/
