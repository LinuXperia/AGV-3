#ifndef __TIMER_HUB_H_
#define __TIMER_HUB_H_

#include "sys.h"
 


void HUB_PIN_Init(void);
void setSpeed(u8 ID,float speed);  //�����ٶ�  ��������ǰ��  ����������� 0
void enableHub(u8 ID);            //�򿪵��
void disableHub(u8 ID);           //�رյ��
void setCyc(u8 ID,u16 cyc);        //��������
void setDir(u8 ID,int dir);        //���÷���
void EMB(u8 ID);                   //Emergency brake�����ƶ�
void setLineSpeed(u8 ID,int dir,u16 line); 
#endif

