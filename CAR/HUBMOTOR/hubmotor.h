#ifndef __HUBMOTOR_H
#define __HUBMOTOR_H


#include "sys.h"

/***************************轮毂电机********************************************/
void setHubMotorEnable(u16 DevID,int i); 											//启动或关闭轮毂电机
void setHubMotorMode(int i); 																	//设置轮毂电机工作模式
void setHubMotorPlusSubSpeed(int i) ; 												//设置轮毂电机加减速时间
void setHubMotorPositionMaxSpeed(u16 DevID,int i); 						//设置轮毂电机加减速时间
void setHubMotorPositionModeControlWord(int mode); 						//设置轮毂电机位置模式控制字
void getHubMotorNowPosition(u16 DevID); 											//获得轮毂电电机当前位置
void setHubMotorTargetPosition(u16 DevID); 										//设置轮毂电机目标位置
void setHubMotorTargetSpeed(u16 DevID,int i);  								//设置轮毂电机目标速度
void setHubMotorLength(u16 DevID,int i);											//设置轮毂电机行进距离
void hubMotorSpeed(int hubCounte);														//计算轮毂电机速度
void setHubMotorLengthAndSpeed(u16 DevID,s32 length,s32 speed);				//设置轮毂电机行进长度和行进速度
void hubMotorPul(int hubCounte);															//轮毂电机脉冲
#endif


