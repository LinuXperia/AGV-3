#ifndef __HUBMOTOR_H
#define __HUBMOTOR_H


#include "sys.h"

/***************************��챵��********************************************/
void setHubMotorEnable(u16 DevID,int i); 											//������ر���챵��
void setHubMotorMode(int i); 																	//������챵������ģʽ
void setHubMotorPlusSubSpeed(int i) ; 												//������챵���Ӽ���ʱ��
void setHubMotorPositionMaxSpeed(u16 DevID,int i); 						//������챵���Ӽ���ʱ��
void setHubMotorPositionModeControlWord(int mode); 						//������챵��λ��ģʽ������
void getHubMotorNowPosition(u16 DevID); 											//�����챵�����ǰλ��
void setHubMotorTargetPosition(u16 DevID); 										//������챵��Ŀ��λ��
void setHubMotorTargetSpeed(u16 DevID,int i);  								//������챵��Ŀ���ٶ�
void setHubMotorLength(u16 DevID,int i);											//������챵���н�����
void hubMotorSpeed(int hubCounte);														//������챵���ٶ�
void setHubMotorLengthAndSpeed(u16 DevID,s32 length,s32 speed);				//������챵���н����Ⱥ��н��ٶ�
void hubMotorPul(int hubCounte);															//��챵������
#endif


