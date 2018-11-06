#include "address.h"






//获取风机控制器的地址
u8 getSensorAddress()
{

   u8 addr=0x00;       //地址码	
	
	 addr = addr|(HAL_GPIO_ReadPin(ADDR8_GPIO_Port,ADDR8_Pin)<<7);
	 addr = addr|(HAL_GPIO_ReadPin(ADDR7_GPIO_Port,ADDR7_Pin)<<6);
	 addr = addr|(HAL_GPIO_ReadPin(ADDR6_GPIO_Port,ADDR6_Pin)<<5);
	 addr = addr|(HAL_GPIO_ReadPin(ADDR5_GPIO_Port,ADDR5_Pin)<<4);
	 
	 addr = addr|(HAL_GPIO_ReadPin(ADDR4_GPIO_Port,ADDR4_Pin)<<3);
	 addr = addr|(HAL_GPIO_ReadPin(ADDR3_GPIO_Port,ADDR3_Pin)<<2);
	 addr = addr|(HAL_GPIO_ReadPin(ADDR2_GPIO_Port,ADDR2_Pin)<<1);
	 addr = addr|HAL_GPIO_ReadPin(ADDR1_GPIO_Port,ADDR1_Pin);
	
//	return (~addr)&0x00ff;
	return addr;
}




//获取风机控制器的类型
u8 getSensorType()
{
	u8 _type=0;
	
	_type= _type|(HAL_GPIO_ReadPin(TYPE1_GPIO_Port,TYPE1_Pin)<<1);;
	
	_type=_type| HAL_GPIO_ReadPin(TYPE2_GPIO_Port,TYPE2_Pin);
	
	
	return _type;
}






