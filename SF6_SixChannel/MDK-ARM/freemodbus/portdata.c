#include "stm32f1xx_hal.h"
#include "mb.h"
#include "string.h"
#include "portdata.h"
#include "mbutils.h"
#include "measure.h"
#include "memory.h"
#include "usart.h"

/* ----------------------- Defines ------------------------------------------*/
#define REG_INPUT_START 1
#define REG_INPUT_NREGS 20
#define REG_HOLDING_START 	0x000
#define REG_HOLDING_NREGS 	50
#define REG_COIL_START 1
#define REG_COIL_NREGS 16

/* ----------------------- Static variables ---------------------------------*/
static USHORT   usRegInputStart = REG_INPUT_START;
static USHORT   usRegInputBuf[REG_INPUT_NREGS];
//static USHORT   usRegHoldingStart = REG_HOLDING_START;
unsigned char ucRegCoilsBuf[REG_COIL_NREGS] = {0};
uint16_t usRegHoldingBuf[REG_HOLDING_NREGS] = {0};
//uint16_t usRegHoldingBuf[REG_HOLDING_NREGS] = {0};

/****************************************************************************
* 名	  称：eMBRegInputCB 
* 功    能：读取输入寄存器，对应功能码是 04 eMBFuncReadInputRegister
* 入口参数：pucRegBuffer: 数据缓存区，用于响应主机   
*						usAddress: 寄存器地址
*						usNRegs: 要读取的寄存器个数
* 出口参数：
* 注	  意：上位机发来的 帧格式是: SlaveAddr(1 Byte)+FuncCode(1 Byte)
*								+StartAddrHiByte(1 Byte)+StartAddrLoByte(1 Byte)
*								+LenAddrHiByte(1 Byte)+LenAddrLoByte(1 Byte)+
*								+CRCAddrHiByte(1 Byte)+CRCAddrLoByte(1 Byte)
*							3 区
****************************************************************************/
eMBErrorCode
eMBRegInputCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs )
{
    eMBErrorCode    eStatus = MB_ENOERR;
    int             iRegIndex;

    if( ( usAddress >= REG_INPUT_START )
        && ( usAddress + usNRegs <= REG_INPUT_START + REG_INPUT_NREGS ) )
    {
        iRegIndex = ( int )( usAddress - usRegInputStart );
        while( usNRegs > 0 )
        {
            *pucRegBuffer++ = ( UCHAR )( usRegInputBuf[iRegIndex] >> 8 );
            *pucRegBuffer++ = ( UCHAR )( usRegInputBuf[iRegIndex] & 0xFF );
            iRegIndex++;
            usNRegs--;
        }
    }
    else
    {
        eStatus = MB_ENOREG;
    }

    return eStatus;
}

/****************************************************************************
* 名	  称：eMBRegHoldingCB 
* 功    能：对应功能码有：06 写保持寄存器 eMBFuncWriteHoldingRegister 
*													16 写多个保持寄存器 eMBFuncWriteMultipleHoldingRegister
*													03 读保持寄存器 eMBFuncReadHoldingRegister
*													23 读写多个保持寄存器 eMBFuncReadWriteMultipleHoldingRegister
* 入口参数：pucRegBuffer: 数据缓存区，用于响应主机   
*						usAddress: 寄存器地址
*						usNRegs: 要读写的寄存器个数
*						eMode: 功能码
* 出口参数：
* 注	  意：4 区
****************************************************************************/



eMBErrorCode
eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, eMBRegisterMode eMode )
{
	/* error state */
    eMBErrorCode    eStatus = MB_ENOERR;
    /* offset */
   static int16_t iRegIndex;
    /* test if the reg is in the range */
    if (((int16_t)usAddress-1 >= REG_HOLDING_START) 
        && (usAddress-1 + usNRegs <= REG_HOLDING_START + REG_HOLDING_NREGS))
    {
        /* compute the reg's offset */
        iRegIndex = (int16_t)(usAddress-1 - REG_HOLDING_START);
        switch (eMode)
        {
            case MB_REG_READ:
					 PrintfLog("step in modbus hodingreg rollback function..1\r\n");
                while (usNRegs > 0)
                {
                    *pucRegBuffer++ = (uint8_t)( usRegHoldingBuf[iRegIndex] >> 8 );
                    *pucRegBuffer++ = (uint8_t)( usRegHoldingBuf[iRegIndex] & 0xff);
                    iRegIndex ++;
                    usNRegs --;
						  PrintfLog("%02X ",(*pucRegBuffer));
                }
					 PrintfLog("step in modbus hodingreg rollback function..2\r\n");
                break;
            case MB_REG_WRITE:
                while (usNRegs > 0)
                {
                    usRegHoldingBuf[iRegIndex] = *pucRegBuffer++ << 8;
                    usRegHoldingBuf[iRegIndex] |= *pucRegBuffer++;
                    iRegIndex ++;
                    usNRegs --;
                }
								//写功能寄存器
								HoldingRegisterChange();
                break;
                
        }
    }
    else{
        eStatus = MB_ENOREG;
		 
    }
    PrintfLog("step in modbus hodingreg rollback function..3  %d\r\n",eStatus);
    return eStatus;
}

/****************************************************************************
* 名	  称：eMBRegCoilsCB 
* 功    能：对应功能码有：01 读线圈 eMBFuncReadCoils
*													05 写线圈 eMBFuncWriteCoil
*													15 写多个线圈 eMBFuncWriteMultipleCoils
* 入口参数：pucRegBuffer: 数据缓存区，用于响应主机   
*						usAddress: 线圈地址
*						usNCoils: 要读写的线圈个数
*						eMode: 功能码
* 出口参数：
* 注	  意：如继电器 
*						0 区
****************************************************************************/
eMBErrorCode
eMBRegCoilsCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils, eMBRegisterMode eMode )
{

eMBErrorCode    eStatus = MB_ENOERR;
    short           iNCoils = ( short )usNCoils;
    unsigned short  usBitOffset;

    /* Check if we have registers mapped at this block. */
    if( ( usAddress >= REG_COIL_START ) &&
        ( usAddress + usNCoils <= REG_COIL_START + REG_COIL_NREGS ) )
    {
        usBitOffset = ( unsigned short )( usAddress - REG_COIL_START );
       
        switch ( eMode )
        {
                /* Read current values and pass to protocol stack. */
            case MB_REG_READ:
                while( iNCoils > 0 )
                {
                    *pucRegBuffer++ =
                        xMBUtilGetBits( ucRegCoilsBuf, usBitOffset,
                                        ( unsigned char )( iNCoils >
                                                           8 ? 8 :
                                                           iNCoils ) );
                    iNCoils -= 8;
                    usBitOffset += 8;
                }

                /* Update current register values. */
            case MB_REG_WRITE:
                while( iNCoils > 0 )
                {
                    xMBUtilSetBits( ucRegCoilsBuf, usBitOffset,
                                    ( unsigned char )( iNCoils > 8 ? 8 : iNCoils ),
                                    *pucRegBuffer++ );
                    iNCoils -= 8;
                }		
							
                break;
        }
	}
	else//错误
	{
		eStatus = MB_ENOREG;
	}	
	
	return eStatus;
}
/****************************************************************************
* 名	  称：eMBRegDiscreteCB 
* 功    能：读取离散寄存器，对应功能码有：02 读离散寄存器 eMBFuncReadDiscreteInputs
* 入口参数：pucRegBuffer: 数据缓存区，用于响应主机   
*						usAddress: 寄存器地址
*						usNDiscrete: 要读取的寄存器个数
* 出口参数：
* 注	  意：1 区
****************************************************************************/
eMBErrorCode
eMBRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete )
{
    ( void )pucRegBuffer;
    ( void )usAddress;
    ( void )usNDiscrete;
    return MB_ENOREG;
}


void modbus_set_float_ex(float f, uint16_t *dest, uint16_t format)
{
    uint32_t i;

    memcpy(&i, &f, sizeof(uint32_t));
    if(format == 2143)
    {
      dest[0] = (uint16_t)i;
      dest[1] = (uint16_t)(i >> 16);
    }
    else if(format == 4321)
    {
    	dest[1] = (uint16_t)i;
    	dest[0] = (uint16_t)(i >> 16);
    }
}

float modbus_get_float_ex(const uint16_t *src, uint16_t format)
{
    float f;
    uint32_t i;

    if(format == 2143)
    {
      i = (((uint32_t)src[1]) << 16) + src[0];
    }
    else
    {
      i = (((uint32_t)src[0]) << 16) + src[1];
    }
    memcpy(&f, &i, sizeof(float));

    return f;
}

//modbus发布
void MeasureDateAsModbus()
{	
	
	usRegHoldingBuf[0]=measure.sf6value;
	usRegHoldingBuf[1]=measure.o2value*10.0;
	usRegHoldingBuf[2]=measure.t*10.0;
	usRegHoldingBuf[3]=measure.rh*10.0;
	usRegHoldingBuf[4]=measure.current_channel;//当前测量的通道
	
	
	usRegHoldingBuf[8]=System.resetCount;
	usRegHoldingBuf[9]=System.isopenbuzzer;	
	usRegHoldingBuf[10]=System.channe_count;
	usRegHoldingBuf[11]=System.zero_time;
	usRegHoldingBuf[12]=System.measure_time;
	usRegHoldingBuf[13]=System.change_time;
	usRegHoldingBuf[14]=System.pause_time;
	usRegHoldingBuf[15]=System.stop_time;
	usRegHoldingBuf[16]=System.SF6Modify;
	usRegHoldingBuf[17]=System.O2Modify*10;
	usRegHoldingBuf[18]=System.TempModify*10;
	usRegHoldingBuf[19]=System.HumModify*10;
	//modbus_set_float_ex(System.O2Modify,&usRegHoldingBuf[18],2143);
	//modbus_set_float_ex(System.TempModify,&usRegHoldingBuf[20],2143);
	//modbus_set_float_ex(System.HumModify,&usRegHoldingBuf[22],2143);
	
	usRegHoldingBuf[20]=System.Version;
	PrintfLog("modbus hoding reg getvalue...\r\n");
}

void ReadSystemParam()
{
//	usRegHoldingBuf[0]=System.channelnum;
//	usRegHoldingBuf[1]=System.sf6vol;
//	usRegHoldingBuf[2]=System.o2vol;
}



void HoldingRegisterChange()
{
	System.isopenbuzzer=usRegHoldingBuf[9];
	System.channe_count=usRegHoldingBuf[10];
	System.zero_time=usRegHoldingBuf[11];
	System.measure_time=usRegHoldingBuf[12];
	System.change_time=usRegHoldingBuf[13];
	System.pause_time=usRegHoldingBuf[14];
	System.stop_time=usRegHoldingBuf[15];
	System.SF6Modify=usRegHoldingBuf[16];
	System.O2Modify=usRegHoldingBuf[17]/10.0;
	System.TempModify=usRegHoldingBuf[18]/10.0;
	System.HumModify=usRegHoldingBuf[19]/10.0;
	//System.O2Modify=modbus_get_float_ex(&usRegHoldingBuf[18],2143);
	//System.TempModify=modbus_get_float_ex(&usRegHoldingBuf[20],2143);
	//System.HumModify=modbus_get_float_ex(&usRegHoldingBuf[22],2143);
	
	SaveSystem(&System);
	
}
