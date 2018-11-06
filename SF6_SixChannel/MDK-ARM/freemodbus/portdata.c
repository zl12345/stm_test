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
* ��	  �ƣ�eMBRegInputCB 
* ��    �ܣ���ȡ����Ĵ�������Ӧ�������� 04 eMBFuncReadInputRegister
* ��ڲ�����pucRegBuffer: ���ݻ�������������Ӧ����   
*						usAddress: �Ĵ�����ַ
*						usNRegs: Ҫ��ȡ�ļĴ�������
* ���ڲ�����
* ע	  �⣺��λ�������� ֡��ʽ��: SlaveAddr(1 Byte)+FuncCode(1 Byte)
*								+StartAddrHiByte(1 Byte)+StartAddrLoByte(1 Byte)
*								+LenAddrHiByte(1 Byte)+LenAddrLoByte(1 Byte)+
*								+CRCAddrHiByte(1 Byte)+CRCAddrLoByte(1 Byte)
*							3 ��
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
* ��	  �ƣ�eMBRegHoldingCB 
* ��    �ܣ���Ӧ�������У�06 д���ּĴ��� eMBFuncWriteHoldingRegister 
*													16 д������ּĴ��� eMBFuncWriteMultipleHoldingRegister
*													03 �����ּĴ��� eMBFuncReadHoldingRegister
*													23 ��д������ּĴ��� eMBFuncReadWriteMultipleHoldingRegister
* ��ڲ�����pucRegBuffer: ���ݻ�������������Ӧ����   
*						usAddress: �Ĵ�����ַ
*						usNRegs: Ҫ��д�ļĴ�������
*						eMode: ������
* ���ڲ�����
* ע	  �⣺4 ��
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
								//д���ܼĴ���
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
* ��	  �ƣ�eMBRegCoilsCB 
* ��    �ܣ���Ӧ�������У�01 ����Ȧ eMBFuncReadCoils
*													05 д��Ȧ eMBFuncWriteCoil
*													15 д�����Ȧ eMBFuncWriteMultipleCoils
* ��ڲ�����pucRegBuffer: ���ݻ�������������Ӧ����   
*						usAddress: ��Ȧ��ַ
*						usNCoils: Ҫ��д����Ȧ����
*						eMode: ������
* ���ڲ�����
* ע	  �⣺��̵��� 
*						0 ��
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
	else//����
	{
		eStatus = MB_ENOREG;
	}	
	
	return eStatus;
}
/****************************************************************************
* ��	  �ƣ�eMBRegDiscreteCB 
* ��    �ܣ���ȡ��ɢ�Ĵ�������Ӧ�������У�02 ����ɢ�Ĵ��� eMBFuncReadDiscreteInputs
* ��ڲ�����pucRegBuffer: ���ݻ�������������Ӧ����   
*						usAddress: �Ĵ�����ַ
*						usNDiscrete: Ҫ��ȡ�ļĴ�������
* ���ڲ�����
* ע	  �⣺1 ��
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

//modbus����
void MeasureDateAsModbus()
{	
	
	usRegHoldingBuf[0]=measure.sf6value;
	usRegHoldingBuf[1]=measure.o2value*10.0;
	usRegHoldingBuf[2]=measure.t*10.0;
	usRegHoldingBuf[3]=measure.rh*10.0;
	usRegHoldingBuf[4]=measure.current_channel;//��ǰ������ͨ��
	
	
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
