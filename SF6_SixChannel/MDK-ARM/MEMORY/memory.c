/*
 * memory.c
 *
 *  Created on: 2018年1月5日
 *      Author: jijianyin
 */

#include "memory.h"
#include "string.h"


SYSTEM  System;


u16 Check(void* p,uint16_t length)
{
//    uint16_t total=0x55, i;
//    u8 *pbyte=p;
//    for(i=0;i<length;i++)
//    {
//        total += pbyte[i];
//    }
//		
//  return total;
	
	 u8 check=0;
  u16  i;
  for(i=0; i<length-2; i++)
  {
    check = check ^ ((u8*)p)[i];
  }
  check++;
  return check;
}



u8 CheckSystem(SYSTEM *pSystem)
{
    uint16_t crc, crc2;
    crc = Check(pSystem, sizeof(SYSTEM)-2);
    crc2 = pSystem->CheckCode;
    if(crc == crc2)
    {
        return 1;
    }
    return  0;
}




/****************************
*初始化存储数据
*modbus  addr=1   baudrate=9600
*修正值均为0
*编号12345678
*版本号1.0
*
*/
void System_Init(SYSTEM *pSystem)
{
    
    memset(pSystem, 0, sizeof(SYSTEM));
	
	   pSystem->channe_count=6;
		pSystem->zero_time = 3;
		pSystem->measure_time=3;
		pSystem->change_time=2;
		pSystem->pause_time=2;
	   pSystem->stop_time=60;
		pSystem->SF6Modify=0;
		pSystem->O2Modify=0;
		pSystem->TempModify=0;
		pSystem->HumModify=0;
		pSystem->isopenbuzzer=0;
		pSystem->SF6AlarmVal=1000;
	   pSystem->O2AlarmVal=18;
		pSystem->resetCount=0;
		pSystem->Version=10;
   
   
    pSystem->CheckCode = Check(pSystem, sizeof(SYSTEM)-2);
}

u8 SaveSystem(SYSTEM *pSystem)
{
    pSystem->CheckCode = Check(pSystem, sizeof(SYSTEM)-2);
    if(CheckSystem(pSystem)==1)
    {
        STMFLASH_Write(ADR_SYSTEM, (uint16_t *)&System, sizeof(SYSTEM));
        return 1;
    }
    else
    {
        return 0;
    }
}



u8 ReadSystem(SYSTEM *pSystem)
{
  uint8_t i;

  for(i=0; i<3; i++)
  {
	 STMFLASH_Read(ADR_SYSTEM, (uint16_t *)pSystem, sizeof(SYSTEM));  /* 读取系统参数 */
    if(CheckSystem(pSystem)==1)
    {
        return 1;
    }
  }
  System_Init(pSystem);
  return 0;
}


void InitMemory(void)
{
	ReadSystem(&System);
}



