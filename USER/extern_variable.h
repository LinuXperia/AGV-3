#ifndef __EXTERN_VARIABLE_H
#define  __EXTERN_VARIABLE_H


#include "include.h"
#include "custom_structure.h"
//ȫ�ֱ���
extern unsigned short encode1_value,encode2_value,encode3_value,encode4_value;
extern ZLAC706_Receive ZLAC706[4];   			 //��챵�� ״̬ λ�� �ٶ� ����
extern ZWSK_Receive    ZWSK[4];			 			 //ת���� ״̬  λ��  �ٶ� 
extern s32 steering_speed;           			 //ת�����ٶ� 
extern s32 hubmotor_speed;
extern s32 hubmotor_speed_1;								 //��챵���ٶ�
extern s32 hubmotor_speed_2;
extern s32 hubmotor_speed_3;
extern s32 hubmotor_speed_4;
extern int EncoderState,zeroState,spstate; //��ֵ״̬  ����״̬ ����״̬
extern u16 key; 													 //ң�ذ���ֵ

//��λ��־λ
extern int left_flag1,left_flag2,left_flag3,left_flag4;           //0��ʾ����λ״̬   1��ʾ������λ״̬
extern int right_flag1,right_flag2,right_flag3,right_flag4;      //0��ʾ����λ״̬   1��ʾ������λ״̬

//ԭ����ת��־λ
extern int InSituRotation_Flag;     //1��������Ϊ��ת�Ƕ�         Ĭ��ֵ��0������������Ϊ��ת�Ƕ�
extern int returnToZero_Flag;				//1������㲢���ڹ���״̬      0���������

//����״̬
extern workState_e workState;
extern Car_State CarState;

//���������ͱ�־
extern int sendSteeringControlCMD_Flag;      //1������  0 ��������
extern int sendHubControlCMD_Flag;					 //1������  0 ��������

extern double angle_;
extern double angle1,angle2,angle3,angle4;
extern double angle1_rad,angle2_rad,angle3_rad,angle4_rad;
extern double R1,R2,R3,R4;
extern u8 turnFlag; 

extern int   hubmotor_5_speed,	hubmotor_6_speed,	hubmotor_7_speed,	hubmotor_8_speed;
extern u16 hub_5_,hub_6_,hub_7_,hub_8_;
extern u16 hub_5_temp,hub_6_temp,hub_7_temp,hub_8_temp;
extern u16 zero;


extern u32 steering_Max_Speed_1,steering_Max_Speed_2,steering_Max_Speed_3,steering_Max_Speed_4;

//���Լ��ϵġ���������������������������������������
//�Ӽ��ٱ仯б��
extern float Hub_Delta5,Hub_Delta6,Hub_Delta7,Hub_Delta8; 

extern int hub_5_speed,hub_6_speed,hub_7_speed,hub_8_speed;
extern int hub_5_speed_last,hub_6_speed_last,hub_7_speed_last,hub_8_speed_last;
extern int hub_5_speed_last_last,hub_6_speed_last_last,hub_7_speed_last_last,hub_8_speed_last_last;
extern int speed_cnt_5,speed_cnt_6,speed_cnt_7,speed_cnt_8;
extern float speed_temp_5,speed_temp_6,speed_temp_7,speed_temp_8;
extern int	HubMotorPlusSubSpeed;
extern u16 hub_5_cnt,hub_6_cnt,hub_7_cnt,hub_8_cnt;
//���Լ��ϵġ���������������������������������������

#endif

