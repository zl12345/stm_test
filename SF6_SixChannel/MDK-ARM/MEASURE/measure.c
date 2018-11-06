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
	
	//���6���㣬����1����
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



//��ʼ����
void  MeasureControl()
{		
	
	PrintfLog("measure start...\r\n");
	switch(measure.step)
	{
		//�����У׼״̬
		case STEP_ZERO:			
			if(measure.zerotime>0)
			{
				PrintfLog("measure step=zero,zerotime=%d\r\n",measure.zerotime);
				if(measure.zero_flag!=1)
				{
					OpenZERO();
					OpenPUMP();
					measure.zero_flag=1;//��0���־λ�������ظ�����IO
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
				measure.step=STEP_MEASURE;//����״̬
				CloseZERO();
				ClosePUMP();
				measure.zero_flag=0;//��λ0���־λ
				measure.zerotime=System.zero_time*60;
			}
			break;
		//��������״̬
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
						 measure.step=STEP_CHANGE;//�û�״̬
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
						 measure.step=STEP_CHANGE;//�û�״̬
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
						 measure.step=STEP_CHANGE;//�û�״̬
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
						 measure.step=STEP_CHANGE;//�û�״̬
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
						 measure.step=STEP_CHANGE;//�û�״̬
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
						 measure.step=STEP_CHANGE;//�û�״̬
						 CloseCH5();
						 ClosePUMP();
						 measure.six_flag=0;
						 measure.measuretime=System.measure_time*60;
					 }
				 break;
			 }
		 }
			break;
			 
		//�û�״̬
		case STEP_CHANGE:
				if(measure.changetime>0)
				{
					if(measure.change_flag!=1)
					{
						PrintfLog("measure step=change,measurechannel=%d,changetime=%d\r\n",measure.current_channel,measure.changetime);
						OpenZERO();
						OpenPUMP();
						measure.change_flag=1;//��0���־λ�������ظ�����IO
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
					measure.step=STEP_PAUSE;//��ͣ״̬
					CloseZERO();
					ClosePUMP();
					measure.change_flag=0;//��λ0���־λ
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
					
					//�����ǰ��ͨ��Ϊ���һ��ͨ�������¸�ֵ��ǰ��ͨ��
					if(measure.current_channel==measure.channelcount)
					{
						measure.current_channel=1;
						measure.step=STEP_STOP;
					}
					else
					{
						//�û�ֹͣ��ֱ�ӽ�����һ��ͨ��
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
					measure.step=STEP_ZERO;//ֹͣʱ�䵽�ˣ����½���0��У׼
				}
			
			break;				        						 			 			 			 		 
	}

	//��������
	
	ReadSensorData();
	
}

//��������
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
		OpenAlarm1();//��������̵���1
	}
	else
	{
		measure.sf6alarm_flag=0;
		CloseAlarm1();//�ر�����̵���1
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
	
	//��������˷�����
	
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
		Master_03_Slove(0x01,1,4);//��03�Ĵ�������ַΪ1 ��ʼ�Ĵ���Ϊ1����ȥ4���Ĵ���  1��SF6val 2��O2val*10 3��temp*10 4��hum*10
		measure.read_sensor_period=READ_SENSOR_PERIOD;
		measure.send_cmd=1;
	}
	else
	{
		if(measure.read_sensor_period==0)
		{
			 if(RS485Recive.flag==1)
			 {				
				//��������
				PrintfLog("get sensor_recivebuff ok...\r\n");
				AnalysisData();
				
				measure.sersor_comm_flag=1;//�봫������ͨѶ��
				measure.sersor_error_counts=0;//ͨѶ���������λ					
			 }
			else
			 {			
				PrintfLog("get sensor_recivebuff err,err times=%d\r\n",measure.sersor_error_counts);
				 
				measure.sersor_error_counts++;//�����������
				if(measure.sersor_error_counts>=10)
				{
					measure.sersor_error_counts=10;//�쳣������������
					measure.sersor_comm_flag=0;//���������������10����ͨѶ�쳣
				}
			 }
			 measure.send_cmd=0;//���������ݿ��Խ�����һ�εķ���
			 memset(&RS485Recive,0,sizeof(RS485RECIVE));//����ͨѶ�����ս��ջ�����	
		}	
	}
	
	
	MeasureDateAsModbus();
	
}




