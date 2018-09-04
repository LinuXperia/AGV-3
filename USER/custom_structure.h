#ifndef _CUSTOM_STRUCTURE_H
#define  _CUSTOM_STRUCTURE_H


#include "sys.h"
typedef enum
{
	Normal_Control,									//����ת ǰ������
	Zeroing,												//���ڹ���
	InSituRo_Control,		  					//��ת����״̬
	InSituRoing,          					//��ת�Ƕ�������
	Speed_Postion_Control,					//ת�� ��챶�����Ϊ�ٶȺ�λ��������������
	Stop,														//ֹͣ״̬ 
}workState_e;


//��������� ��ǰ��״̬ ���� �ٶ� ���� 
typedef struct
{
	u8  State;       //��ǰ״̬ ���������쳣
	s32 Position;		//λ��	
	s16 Speed;			//�ٶ�
	s16 TCurrent; 	//����	
} ZLAC706_Receive;

//ת�������� ��ǰ��״̬ ���� �ٶ� ���� 
typedef struct
{
	u16  State;         //��ǰ״̬ ���������쳣   10����10 16���� A
	s32 Position;		    //λ��	   10����1033    16����409  
	s32 Speed;			    //�ٶ�           1036          40C
} ZWSK_Receive;





typedef enum
{
		Forward_State,         				//ǰ�� 
		Back_State,           			  //����
		Static_State,          				//ֹͣ
}Hub_State;

typedef enum
{
		Right_State,																//��ת
		Left_State,																	//��ת
		Noturn_State,																//��ת
}Steering_State;

//��챵�ǰ״̬ 	ǰһʱ��״̬
typedef struct 
{
	Hub_State				Hub1_LastState;								//���1ǰһʱ��״̬
	Hub_State				Hub1_NowState;								//���1��ǰ״̬
	Hub_State				Hub2_LastState;								//���1ǰһʱ��״̬
	Hub_State				Hub2_NowState;								//���1��ǰ״̬
	Hub_State				Hub3_LastState;								//���1ǰһʱ��״̬
	Hub_State				Hub3_NowState;		 						//���1��ǰ״̬
	Hub_State 			Hub4_LastState;								//���1ǰһʱ��״̬
	Hub_State 			Hub4_NowState;								//���1��ǰ״̬
	Steering_State	Steering1_LastState;				 	//ת��1ǰһʱ��״̬
	Steering_State	Steering1_NowState;						//ת��1��ǰ״̬
	Steering_State	Steering2_LastState;					//ת��1ǰһʱ��״̬
	Steering_State	Steering2_NowState;						//ת��1��ǰ״̬
	Steering_State	Steering3_LastState;					//ת��1ǰһʱ��״̬
	Steering_State	Steering3_NowState;						//ת��1��ǰ״̬
	Steering_State	Steering4_LastState;					//ת��1ǰһʱ��״̬
	Steering_State	Steering4_NowState;						//ת��1��ǰ״̬
}Car_State;																			//С��״̬

typedef struct
{
	//��챵��
	s32 Hub1_Position;														//λ��
	s16 Hub1_Speed;																//�ٶ�
	s32 Hub2_Position;
	s16 Hub2_Speed;
	s32 Hub3_Position;
	s16 Hub3_Speed;
	s32 Hub4_Position;
	s16 Hub4_Speed;
	//ת����
	s32 Steering1_Position;											//λ��
	s32 Steering1_Speed;												//�ٶ�
	s32 Steering2_Position;
	s32 Steering2_Speed;
	s32 Steering3_Position;
	s32 Steering3_Speed;
	s32 Steering4_Position;
	s32 Steering4_Speed;
	//���Ա�������ֵ
	u16 encode1_value;
	u16 encode2_value;
	u16 encode3_value;
	u16 encode4_value;
}Car_Vaule;
#endif
