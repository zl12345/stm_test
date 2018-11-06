#ifndef MEASURE_H
#define MEASURE_H



#include "stm32f1xx_hal.h"
#include "main.h"

#define CHANNEL_COUNT  2

#define ZERO_TIME    5
#define MEASURE_TIME 5
#define CHANGE_TIME   5
#define PAUSE_TIME   0
#define STOP_TIME    5

 
#define STEP_ZERO    0
#define STEP_MEASURE 1
#define STEP_CHANGE  2
#define STEP_PAUSE   3
#define STEP_STOP    4



#define READ_SENSOR_PERIOD 2  //1���Ӷ�ȡһ������
#define WAIT_SENSOR_PERIOD 1  //�ȴ�1S�������ظ�

typedef struct	
	
{
	u8  channelcount;
	u8  step;    //��������
	u16  zerotime;//�����У׼ʱ��
	u16  measuretime;//����ʱ��
	u16  changetime;//�û�ʱ��
	u16  pausetime;//��ͣʱ��
	u16  stoptime;//ֹͣʱ��
	u8  current_channel;//��ǰ������ͨ����
	
	//6�����ı�־λ��
	u8  zero_flag;
	
	u8  one_flag;
	u8  two_flag;
	u8  three_flag;
	u8  four_flag;
	u8  five_flag;
	u8  six_flag;
	
	u8  change_flag;//�û���־λ
	
	u8  pause_flag;//��ͣ��־λ
	
	u8  stop_flag;//ֹͣ��־λ
	
	u8 address;//�������豸��ַ
	
	u8 type;//��������
	
	u8  send_cmd;
	u8  read_sensor_period;//��ȡ������������(����������)
	
	u8  sersor_comm_flag;//�봫������ͨѶ״̬
	
	u8  sersor_error_counts;//ͨѶ����Ĵ���
	
	u8 sf6buff[3];
	u8 o2buff[3];
	u8 tempbuf[3];
	u8 humbuf[3];
	
	u8 sf6alarm_flag;//SF6������־
	u8 o2alarm_flag;//O2.....
	
	u16 sf6value;
	
	float o2value;
	
	float t;
	
	float rh;
	
}MEASURE;



extern MEASURE  measure;


void  MeasureInit(void);
void  MeasureControl(void);
void  ReadSensorData(void);








#endif

