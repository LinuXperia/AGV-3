#ifndef __VARIABLE_H_
#define __VARIABLE_H_


#include "include.h"
#include "config.h"
#include "custom_structure.h"
#include "extern_variable.h"

//״̬��
workState_e workState;
Car_State CarState={Static_State,Static_State, //���1 last now 
										Static_State,Static_State,
										Static_State,Static_State,
										Static_State,Static_State,
										Noturn_State,Noturn_State,
										Noturn_State,Noturn_State,
										Noturn_State,Noturn_State,
										Noturn_State,Noturn_State,};
//��ֵ״̬        ����״̬     ң��״̬ 
int EncoderState=0,zeroState=0,spstate; 
s32 steering_speed               = 0;
s32 hubmotor_speed=0;
s32 hubmotor_speed_1=0;
s32 hubmotor_speed_2=0;
s32 hubmotor_speed_3=0;
s32 hubmotor_speed_4=0;
int plussubSpeedVaule            = 0;
u16 key; //ң�ذ���ֵ
int InSituRotation_Flag          = 0;   
int returnToZero_Flag            = 0;

int sendSteeringControlCMD_Flag  = 0;																				//1������ Ĭ��:0 ��������
int sendHubControlCMD_Flag       = 0;					  														//1������ Ĭ��:0 ��������

u8 turnFlag=2;  //Ĭ��Ϊ2  ��ת��    0 ��ת  1 ��ת

//ת������ٶ�����
u32 steering_Max_Speed_1=0;
u32 steering_Max_Speed_2=0;
u32 steering_Max_Speed_3=0;
u32 steering_Max_Speed_4=0;
										
u16 		hub_5_temp,		hub_6_temp,		hub_7_temp,		hub_8_temp;
u16  		hub_5_,				hub_6_,				hub_7_,				hub_8_;
u16     zero=0;
#endif

