#include "measure.h"
#include "gpio.h"
#include "memory.h"
#include "string.h"
#include "portdata.h"
#include "modbus.h"
#include "iwdg.h"
#include "usart.h"
MEASURE  measure;

void  MeasureInit()
{
	memset(&measure,0,sizeof(measure));
	measure.channelcount=System.channe_count;
	
	//最多6个点，最少1个点
	if(measure.channelcount>6)measure.channelcount=6;
	if(measure.channelcount<1)measure.channelcount=1;
	
	measure.measuretime=System.measure_time*60;
	measure.changetime=System.change_time*60;
	measure.pausetime=System.pause_time*60;
	measure.zerotime=System.zero_time*60;
	measure.stoptime=System.stop_time*60;
	
	measure.step=STEP_ZERO;
	
	measure.zero_flag=0;
	measure.one_flag=0;
	measure.two_flag=0;
	measure.three_flag=0;
	measure.four_flag=0;
	measure.five_flag=0;
	measure.six_flag=0;
	measure.change_flag=0;
	measure.pause_flag=0;
	measure.stop_flag=0;
	measure.current_channel=6;
	
	
}



//开始测量
void  MeasureControl()
{		
	
	PrintfLog("measure start...\r\n");
	switch(measure.step)
	{
		//零点自校准状态
		case STEP_ZERO:			
			if(measure.zerotime>0)
			{
				PrintfLog("measure step=zero,zerotime=%d\r\n",measure.zerotime);
				if(measure.zero_flag!=1)
				{
					OpenZERO();
					OpenPUMP();
					measure.zero_flag=1;//打开0点标志位，避免重复开启IO
				}
            else
				{		
					HAL_IWDG_Refresh(&hiwdg);
					//break;
				}
			}
			else
			{
				PrintfLog("measure zerostep-over...\r\n");
				measure.step=STEP_MEASURE;//测量状态
				CloseZERO();
				ClosePUMP();
				measure.zero_flag=0;//复位0点标志位
				measure.zerotime=System.zero_time*60;
			}
			break;
		//正常测量状态
		case STEP_MEASURE:
		{
		    switch(measure.current_channel)
			 {
				 case 1:
					 if(measure.measuretime>0)
					 {
						 PrintfLog("measure step=measure,measurechannel=%d,measuretime=%d\r\n",measure.current_channel,measure.measuretime);
						if(measure.one_flag!=1)
						{
							OpenCH0();
							OpenPUMP();
							measure.one_flag=1;
						}
					   else
						{		
							HAL_IWDG_Refresh(&hiwdg);
							//break;
						}
					 }	 			 
					 else
					 {
						PrintfLog("measure  channel_1 measure step-over...\r\n");
						 measure.step=STEP_CHANGE;//置换状态
						 CloseCH0();
						 ClosePUMP();
						 measure.one_flag=0;
						 measure.measuretime=System.measure_time*60;												 
					 }
				 break;
					
				 case 2:
					 if(measure.channelcount<measure.current_channel)
					 {
						 break;
					 }
					 if(measure.measuretime>0)
					 {
						 PrintfLog("measure step=measure,measurechannel=%d,measuretime=%d\r\n",measure.current_channel,measure.measuretime);
						if(measure.two_flag!=1)
						{
							OpenCH1();
							OpenPUMP();
							measure.two_flag=1;
						}
                  else
						{	
							HAL_IWDG_Refresh(&hiwdg);							
							//break;
						}
					 }	 			 
					 else
					 {
						 PrintfLog("measure  channel_2 measure step-over...\r\n");
						 measure.step=STEP_CHANGE;//置换状态
						 CloseCH1();
						 ClosePUMP();
						 measure.two_flag=0;
						 measure.measuretime=System.measure_time*60;
					 }
					 
				 break;
				 
				 case 3:
					if(measure.channelcount<measure.current_channel)
					 {
						 break;
					 }
					 if(measure.measuretime>0)
					 {
						PrintfLog("measure step=measure,measurechannel=%d,measuretime=%d\r\n",measure.current_channel,measure.measuretime);
						if(measure.three_flag!=1)
						{
							OpenCH2();
							OpenPUMP();
							measure.three_flag=1;
						}
						else
						{	
							HAL_IWDG_Refresh(&hiwdg);
							//break;
						}
					 }	 			 
					 else
					 {
						 PrintfLog("measure  channel_3 measure step-over...\r\n");
						 measure.step=STEP_CHANGE;//置换状态
						 CloseCH2();
						 ClosePUMP();
						 measure.three_flag=0;
						 measure.measuretime=System.measure_time*60;
					 }
				 break;
				 
				 case 4:
					if(measure.channelcount<measure.current_channel)
					 {
						 break;
					 }
					 
					 if(measure.measuretime>0)
					 {
						 PrintfLog("measure step=measure,measurechannel=%d,measuretime=%d\r\n",measure.current_channel,measure.measuretime);
						if(measure.four_flag!=1)
						{
							OpenCH3();
							OpenPUMP();
							measure.four_flag=1;
						}
						else
						{		
							HAL_IWDG_Refresh(&hiwdg);
							//break;
						}
					 }	 			 
					 else
					 {
						 PrintfLog("measure  channel_4 measure step-over...\r\n");
						 measure.step=STEP_CHANGE;//置换状态
						 CloseCH3();
						 ClosePUMP();
						 measure.four_flag=0;
						 measure.measuretime=System.measure_time*60;
					 }
				 break;
				 
				 case 5:
					if(measure.channelcount<measure.current_channel)
					 {
						 break;
					 }
					 if(measure.measuretime>0)
					 {
						 PrintfLog("measure step=measure,measurechannel=%d,measuretime=%d\r\n",measure.current_channel,measure.measuretime);
						if(measure.five_flag!=1)
						{
							OpenCH4();
							OpenPUMP();
							measure.five_flag=1;
						}
					   else
						{	
							HAL_IWDG_Refresh(&hiwdg);
							//break;
						}
					 }	 			 
					 else
					 {
						 PrintfLog("measure  channel_5 measure step-over...\r\n");
						 measure.step=STEP_CHANGE;//置换状态
						 CloseCH4();
						 ClosePUMP();
						 measure.five_flag=0;
						 measure.measuretime=System.measure_time*60;
					 }
				 break;
				 
				 case 6:
					 if(measure.channelcount<measure.current_channel)
					 {
						 break;
					 }
					 if(measure.measuretime>0)
					 {
						 PrintfLog("measure step=measure,measurechannel=%d,measuretime=%d\r\n",measure.current_channel,measure.measuretime);
						if(measure.six_flag!=1)
						{
							OpenCH5();
							OpenPUMP();
							measure.six_flag=1;
						}
					   else
						{	
							HAL_IWDG_Refresh(&hiwdg);
							//break;
						}
					 }	 			 
					 else
					 {
						 PrintfLog("measure  channel_6 measure step-over...\r\n");
						 measure.step=STEP_CHANGE;//置换状态
						 CloseCH5();
						 ClosePUMP();
						 measure.six_flag=0;
						 measure.measuretime=System.measure_time*60;
					 }
				 break;
			 }
		 }
			break;
			 
		//置换状态
		case STEP_CHANGE:
				if(measure.changetime>0)
				{
					if(measure.change_flag!=1)
					{
						PrintfLog("measure step=change,measurechannel=%d,changetime=%d\r\n",measure.current_channel,measure.changetime);
						OpenZERO();
						OpenPUMP();
						measure.change_flag=1;//打开0点标志位，避免重复开启IO
					}
					else
					{		
						HAL_IWDG_Refresh(&hiwdg);
						//break;
					}
				}
				else
				{					
					PrintfLog("measure changestep-over...\r\n");
					measure.step=STEP_PAUSE;//暂停状态
					CloseZERO();
					ClosePUMP();
					measure.change_flag=0;//复位0点标志位
					measure.changetime=System.change_time*60;
				}
			break;
				
		case STEP_PAUSE:
				if(measure.pausetime>0)
				{
					PrintfLog("measure step=pause,pausetime=%d\r\n",measure.pausetime);
					if(measure.pause_flag!=1)
					{						
						CloseZERO();
						ClosePUMP();
						measure.pause_flag=1;
					}
					else
					{		
						HAL_IWDG_Refresh(&hiwdg);
						//break;
					}
				}
				else
				{
					PrintfLog("measure pausestep-over...\r\n");
					measure.pause_flag=0;
					measure.pausetime=System.pause_time*60;
					
					//如果当前的通道为最后一个通道，重新赋值当前的通道
					if(measure.current_channel==measure.channelcount)
					{
						measure.current_channel=1;
						measure.step=STEP_STOP;
					}
					else
					{
						//置换停止完直接进入下一个通道
						measure.current_channel++;
						measure.step=STEP_MEASURE;
					}					
				}
		
			break;
		
		case STEP_STOP:
				if(measure.stoptime>0)
				{
					PrintfLog("measure step=stop,stop=%d\r\n",measure.stoptime);
					if(measure.stop_flag!=1)
					{
						CloseZERO();
						ClosePUMP();
						measure.stop_flag=1;
					}
					else
					{
						HAL_IWDG_Refresh(&hiwdg);
						//break;
					}
				}
				else
				{
					PrintfLog("measure stopstep-over...\r\n");
					measure.stop_flag=0;
					measure.stoptime=System.stop_time*60;
					measure.step=STEP_ZERO;//停止时间到了，重新进行0点校准
				}
			
			break;				        						 			 			 			 		 
	}

	//测量数据
	
	ReadSensorData();
	
}

//分析数据
void AnalysisData()
{
	HAL_IWDG_Refresh(&hiwdg);
	memcpy(measure.sf6buff,&RS485Recive.buff[3],2);
	memcpy(measure.o2buff,&RS485Recive.buff[5],2);
	memcpy(measure.tempbuf,&RS485Recive.buff[7],2);
	memcpy(measure.humbuf,&RS485Recive.buff[9],2);
	
	
	measure.sf6value=(measure.sf6buff[0]<<8)|measure.sf6buff[1];
	measure.o2value=((measure.o2buff[0]<<8)|measure.o2buff[1])/10.0;
	measure.t=((measure.tempbuf[0]<<8)|measure.tempbuf[1])/10.0;
	measure.rh=((measure.humbuf[0]<<8)|measure.humbuf[1])/10.0;
	
	measure.sf6value+=System.SF6Modify;
	if(measure.sf6value<=0)measure.sf6value=0;
	if(measure.sf6value>3000)measure.sf6value=3000;
	if(measure.sf6value>System.SF6AlarmVal)
	{
		measure.sf6alarm_flag=1;
		OpenAlarm1();//开启输出继电器1
	}
	else
	{
		measure.sf6alarm_flag=0;
		CloseAlarm1();//关闭输出继电器1
	}
	
	measure.o2value+=System.O2Modify;
	if(measure.o2value<0)measure.o2value=0;
	if(measure.o2value>=25)measure.o2value=25.0;
	if(measure.o2value<System.O2AlarmVal)
	{
		measure.o2alarm_flag=1;
		OpenAlarm2();
	}
	else
	{
		measure.o2alarm_flag=0;
		CloseAlarm2();
	}
	
	
	measure.t+=System.TempModify;
	measure.rh+=System.HumModify;
	if(measure.rh<0)measure.rh=0;
	if(measure.rh>100)measure.rh=100;
	
	//如果开启了蜂鸣器
	
		if((measure.sf6alarm_flag==1)||(measure.o2alarm_flag==1))
		{
			if(System.isopenbuzzer==1)
			{
			   SpeakerOn();
			}
			else
			{
				SpeakerOff();
			}
		}
		else
		{
			SpeakerOff();
		}
		PrintfLog("Analysis recivedata ok...\r\n");
}



void ReadSensorData()
{
	HAL_IWDG_Refresh(&hiwdg);
	if(measure.send_cmd==0)
	{
		Master_03_Slove(0x01,1,4);//读03寄存器，地址为1 起始寄存器为1，读去4个寄存器  1、SF6val 2、O2val*10 3、temp*10 4、hum*10
		measure.read_sensor_period=READ_SENSOR_PERIOD;
		measure.send_cmd=1;
	}
	else
	{
		if(measure.read_sensor_period==0)
		{
			 if(RS485Recive.flag==1)
			 {				
				//解析数据
				PrintfLog("get sensor_recivebuff ok...\r\n");
				AnalysisData();
				
				measure.sersor_comm_flag=1;//与传感器已通讯上
				measure.sersor_error_counts=0;//通讯错误次数复位					
			 }
			else
			 {			
				PrintfLog("get sensor_recivebuff err,err times=%d\r\n",measure.sersor_error_counts);
				 
				measure.sersor_error_counts++;//错误次数增加
				if(measure.sersor_error_counts>=10)
				{
					measure.sersor_error_counts=10;//异常次数不再增加
					measure.sersor_comm_flag=0;//错误次数连续大于10次则通讯异常
				}
			 }
			 measure.send_cmd=0;//解析完数据可以进行下一次的发送
			 memset(&RS485Recive,0,sizeof(RS485RECIVE));//不管通讯与否清空接收缓冲区	
		}	
	}
	
	
	MeasureDateAsModbus();
	
}




