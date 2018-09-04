#ifndef __INIT_H
#define __INIT_H

/***************************初始化函数********************************************/
void hardwareInit(void);																				//硬件初始化
void steeringServoInit(int i); 																	//转向电机初始化
void hubMotorInit(int  i); 																			//轮毂电机初始化
void LCDShowInit(void);
#endif
