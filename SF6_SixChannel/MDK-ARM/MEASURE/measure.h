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



#define READ_SENSOR_PERIOD 2  //1秒钟读取一次数据
#define WAIT_SENSOR_PERIOD 1  //等待1S传感器回复

typedef struct	
	
{
	u8  channelcount;
	u8  step;    //测量步骤
	u16  zerotime;//零点自校准时间
	u16  measuretime;//测量时间
	u16  changetime;//置换时间
	u16  pausetime;//暂停时间
	u16  stoptime;//停止时间
	u8  current_channel;//当前测量的通道号
	
	//6个阀的标志位防
	u8  zero_flag;
	
	u8  one_flag;
	u8  two_flag;
	u8  three_flag;
	u8  four_flag;
	u8  five_flag;
	u8  six_flag;
	
	u8  change_flag;//置换标志位
	
	u8  pause_flag;//暂停标志位
	
	u8  stop_flag;//停止标志位
	
	u8 address;//测量的设备地址
	
	u8 type;//测量类型
	
	u8  send_cmd;
	u8  read_sensor_period;//读取传感器的周期(发送命令间隔)
	
	u8  sersor_comm_flag;//与传感器的通讯状态
	
	u8  sersor_error_counts;//通讯出错的次数
	
	u8 sf6buff[3];
	u8 o2buff[3];
	u8 tempbuf[3];
	u8 humbuf[3];
	
	u8 sf6alarm_flag;//SF6报警标志
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

