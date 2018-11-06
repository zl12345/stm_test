#ifndef MEMORY_H
#define MEMORY_H

#include "stmflash.h"

#include "stm32f1xx_hal.h"

#define   ADR_SYSTEM      0x08010000   
  




  // 系统参数
  typedef struct
  { 
	 u8  channe_count;//通道点数
    u8  zero_time;//零点自校准时间
	 u8  measure_time;//每通道的测量时间
	 u8  change_time;//每通道的置换时间
	 u8  pause_time;//暂停时间（通道间）
	 u16 stop_time;//停止时间(所有通道测量完，停止的时间)	
	  
	 float  O2Modify;//O2修正值下
	 s16    SF6Modify;//SF6修正值
	 float  HumModify;
    float  TempModify;//温度修正值
	 
	 float  O2AlarmVal;
	 u16    SF6AlarmVal;
	 
	 u8 isopenbuzzer;//是否开启蜂鸣器
	 u16  resetCount;//重启次数
	 u16  ss;
	 u8  Version;//  版本号
    u8 CheckCode; 
  }SYSTEM;



extern SYSTEM  System;

  
void InitMemory(void);

u8 SaveSystem(SYSTEM *pSystem);
u16 Check(void* p,uint16_t length);
void System_Print(SYSTEM *pSystem);
	



#endif 
  
  
