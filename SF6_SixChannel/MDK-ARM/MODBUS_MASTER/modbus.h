#ifndef MODBUS_H
#define MODBUS_H


#include "stm32f1xx_hal.h"

#define READ_COIL     01
#define READ_DI       02
#define READ_HLD_REG  03
#define READ_AI       04
#define SET_COIL      05
#define SET_HLD_REG   06
#define WRITE_COIL    15
#define WRITE_HLD_REG 16


#define  M_ADDR  01
#define  M_STATE_REG  57
#define  M_READ_COUNT 10



#define HI(n) ((n)>>8)
#define LOW(n) ((n)&0xff)

#define RS485     PCout(9)


//ctl 485
#define RS485Send(){RS485=1;}
#define RS485Rec() {RS485=0;}

//∑¢ÀÕ
typedef struct 
{
	u8 buff[256];
	u16 cnt;
	u8 flag;
	
}RS485SEND;

//Ω” ’
typedef struct 
{
	u8 buff[256];
	u16 cnt;
	u8 flag;
	u8 currentbuff[1];
	u16  Master_ReadReg[100];
}RS485RECIVE;


extern RS485SEND  RS485Send;
extern RS485RECIVE  RS485Recive;

void Modbus_03_Solve(void);
void Master_03_Slove( u8 board_adr,u16 start_address,u16 lenth );
u16 CRC_Compute(u8 *puchMsg, u16 usDataLen); 
void Modbus_init(void);
void  my_uart_handle(void);
#endif



