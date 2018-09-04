#ifndef _CUSTOM_STRUCTURE_H
#define  _CUSTOM_STRUCTURE_H


#include "sys.h"
typedef enum
{
	Normal_Control,									//左右转 前进后退
	Zeroing,												//正在归零
	InSituRo_Control,		  					//自转控制状态
	InSituRoing,          					//自转角度设置中
	Speed_Postion_Control,					//转向 轮毂都设置为速度和位置两个参数控制
	Stop,														//停止状态 
}workState_e;


//轮毂驱动器 当前的状态 距离 速度 电流 
typedef struct
{
	u8  State;       //当前状态 正常或者异常
	s32 Position;		//位置	
	s16 Speed;			//速度
	s16 TCurrent; 	//电流	
} ZLAC706_Receive;

//转向驱动器 当前的状态 距离 速度 电流 
typedef struct
{
	u16  State;         //当前状态 正常或者异常   10进制10 16机制 A
	s32 Position;		    //位置	   10进制1033    16进制409  
	s32 Speed;			    //速度           1036          40C
} ZWSK_Receive;





typedef enum
{
		Forward_State,         				//前进 
		Back_State,           			  //后退
		Static_State,          				//停止
}Hub_State;

typedef enum
{
		Right_State,																//右转
		Left_State,																	//左转
		Noturn_State,																//不转
}Steering_State;

//轮毂当前状态 	前一时刻状态
typedef struct 
{
	Hub_State				Hub1_LastState;								//轮毂1前一时刻状态
	Hub_State				Hub1_NowState;								//轮毂1当前状态
	Hub_State				Hub2_LastState;								//轮毂1前一时刻状态
	Hub_State				Hub2_NowState;								//轮毂1当前状态
	Hub_State				Hub3_LastState;								//轮毂1前一时刻状态
	Hub_State				Hub3_NowState;		 						//轮毂1当前状态
	Hub_State 			Hub4_LastState;								//轮毂1前一时刻状态
	Hub_State 			Hub4_NowState;								//轮毂1当前状态
	Steering_State	Steering1_LastState;				 	//转向1前一时刻状态
	Steering_State	Steering1_NowState;						//转向1当前状态
	Steering_State	Steering2_LastState;					//转向1前一时刻状态
	Steering_State	Steering2_NowState;						//转向1当前状态
	Steering_State	Steering3_LastState;					//转向1前一时刻状态
	Steering_State	Steering3_NowState;						//转向1当前状态
	Steering_State	Steering4_LastState;					//转向1前一时刻状态
	Steering_State	Steering4_NowState;						//转向1当前状态
}Car_State;																			//小车状态

typedef struct
{
	//轮毂电机
	s32 Hub1_Position;														//位置
	s16 Hub1_Speed;																//速度
	s32 Hub2_Position;
	s16 Hub2_Speed;
	s32 Hub3_Position;
	s16 Hub3_Speed;
	s32 Hub4_Position;
	s16 Hub4_Speed;
	//转向电机
	s32 Steering1_Position;											//位置
	s32 Steering1_Speed;												//速度
	s32 Steering2_Position;
	s32 Steering2_Speed;
	s32 Steering3_Position;
	s32 Steering3_Speed;
	s32 Steering4_Position;
	s32 Steering4_Speed;
	//绝对编码器数值
	u16 encode1_value;
	u16 encode2_value;
	u16 encode3_value;
	u16 encode4_value;
}Car_Vaule;
#endif
