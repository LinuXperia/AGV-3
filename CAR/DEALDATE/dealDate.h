#ifndef __DEALDATE_H_
#define __DEALDATE_H_
#include "sys.h"
#include "custom_structure.h"



////轮毂驱动器 当前的状态 距离 速度 电流 
//typedef struct
//{
//	u8  State;       //当前状态 正常或者异常
//	s32 Position;		//位置	
//	s16 Speed;			//速度
//	s16 TCurrent; 	//电流	
//} ZLAC706_Receive;

////转向驱动器 当前的状态 距离 速度 电流 
//typedef struct
//{
//	u16  State;         //当前状态 正常或者异常   10进制10 16机制 A
//	s32 Position;		    //位置	   10进制1033    16进制409  
//	s32 Speed;			    //速度           1036          40C
//} ZWSK_Receive;

void CAN_DATA_Receive(void);
void ZLAC706Data_deal(ZLAC706_Receive *Receive,CanRxMsg *msg);
void ZWSKData_deal(ZWSK_Receive *Receive,CanRxMsg *msg);
void showState(void);		//显示状态
#endif

