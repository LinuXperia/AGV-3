#ifndef __EXTERN_VARIABLE_H
#define  __EXTERN_VARIABLE_H


#include "include.h"
#include "custom_structure.h"
//全局变量
extern unsigned short encode1_value,encode2_value,encode3_value,encode4_value;
extern ZLAC706_Receive ZLAC706[4];   			 //轮毂电机 状态 位置 速度 电流
extern ZWSK_Receive    ZWSK[4];			 			 //转向电机 状态  位置  速度 
extern s32 steering_speed;           			 //转向电机速度 
extern s32 hubmotor_speed;
extern s32 hubmotor_speed_1;								 //轮毂电机速度
extern s32 hubmotor_speed_2;
extern s32 hubmotor_speed_3;
extern s32 hubmotor_speed_4;
extern int EncoderState,zeroState,spstate; //读值状态  归零状态 键盘状态
extern u16 key; 													 //遥控按键值

//限位标志位
extern int left_flag1,left_flag2,left_flag3,left_flag4;           //0表示非限位状态   1表示处于限位状态
extern int right_flag1,right_flag2,right_flag3,right_flag4;      //0表示非限位状态   1表示处于限位状态

//原地自转标志位
extern int InSituRotation_Flag;     //1允许设置为自转角度         默认值：0，不允许设置为自转角度
extern int returnToZero_Flag;				//1允许归零并处于归零状态      0不允许归零

//工作状态
extern workState_e workState;
extern Car_State CarState;

//命令允许发送标志
extern int sendSteeringControlCMD_Flag;      //1允许发送  0 不允许发送
extern int sendHubControlCMD_Flag;					 //1允许发送  0 不允许发送

extern double angle_;
extern double angle1,angle2,angle3,angle4;
extern double angle1_rad,angle2_rad,angle3_rad,angle4_rad;
extern double R1,R2,R3,R4;
extern u8 turnFlag; 

extern float   hubmotor_5_speed,	hubmotor_6_speed,	hubmotor_7_speed,	hubmotor_8_speed;
extern u16 hub_5_,hub_6_,hub_7_,hub_8_;
extern u16 hub_5_temp,hub_6_temp,hub_7_temp,hub_8_temp;
extern u16 zero;


extern u32 steering_Max_Speed_1,steering_Max_Speed_2,steering_Max_Speed_3,steering_Max_Speed_4;
#endif

