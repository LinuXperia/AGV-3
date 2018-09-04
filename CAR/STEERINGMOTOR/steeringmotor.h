#ifndef __STEERINGMOTOR_H
#define __STEERINGMOTOR_H
#include "sys.h"

/***************************转向电机*********************************************/
void setSteeringServoMotoCtrlSign( u16 DevID,u8 i);  					//设置转向电机控制信号来源
void setSteeringServoMode(u16 DevID,int i); 									//设置转向电机模式
void setSteeringServoControlEnable(u16 DevID,u8 i); 					// 使能/失能转向电机
void setSteeringServoZero(u16 DevID);													//设置转向电机归零
void setSteeringServoNowZero(void);														//设置转向电机编码器当前位置为0
void setSteeringServoRotation(u16 DevID,double rotation);			//设置转向电机旋转角度 
void setSteeringServoMaxSpeed(u16 DevID,u32 speed);						//设置转向电机最大速度 
void setSteeringServoSpeed(u16 DevID,int speed);						  //设置转向电机速度 
void setSteeringRotationAndSpeed(u16 DevID,double rotation,u32 speed);			//设置转向电机旋转角度和转向速度


void steeringSpeed(int Count);															  //转速计算
void steeringRation(int Count);																//角度计算
int returnToZero(void);						                            //归零
int returnToZero_SP2(void);																		//按键归零
#endif

