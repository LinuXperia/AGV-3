#ifndef __TIMER_HUB_H_
#define __TIMER_HUB_H_

#include "sys.h"
 


void HUB_PIN_Init(void);
void setSpeed(u8 ID,float speed);  //设置速度  正数代表前进  负数代表后退 0
void enableHub(u8 ID);            //打开电机
void disableHub(u8 ID);           //关闭电机
void setCyc(u8 ID,u16 cyc);        //设置周期
void setDir(u8 ID,int dir);        //设置方向
void EMB(u8 ID);                   //Emergency brake紧急制动
void setLineSpeed(u8 ID,int dir,u16 line); 
#endif

