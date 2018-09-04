#ifndef __STEERINGMOTOR_H
#define __STEERINGMOTOR_H
#include "sys.h"

/***************************ת����*********************************************/
void setSteeringServoMotoCtrlSign( u16 DevID,u8 i);  					//����ת���������ź���Դ
void setSteeringServoMode(u16 DevID,int i); 									//����ת����ģʽ
void setSteeringServoControlEnable(u16 DevID,u8 i); 					// ʹ��/ʧ��ת����
void setSteeringServoZero(u16 DevID);													//����ת��������
void setSteeringServoNowZero(void);														//����ת������������ǰλ��Ϊ0
void setSteeringServoRotation(u16 DevID,double rotation);			//����ת������ת�Ƕ� 
void setSteeringServoMaxSpeed(u16 DevID,u32 speed);						//����ת��������ٶ� 
void setSteeringServoSpeed(u16 DevID,int speed);						  //����ת�����ٶ� 
void setSteeringRotationAndSpeed(u16 DevID,double rotation,u32 speed);			//����ת������ת�ǶȺ�ת���ٶ�


void steeringSpeed(int Count);															  //ת�ټ���
void steeringRation(int Count);																//�Ƕȼ���
int returnToZero(void);						                            //����
int returnToZero_SP2(void);																		//��������
#endif

