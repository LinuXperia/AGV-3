#ifndef __DEALDATE_H_
#define __DEALDATE_H_
#include "sys.h"
#include "custom_structure.h"



////��������� ��ǰ��״̬ ���� �ٶ� ���� 
//typedef struct
//{
//	u8  State;       //��ǰ״̬ ���������쳣
//	s32 Position;		//λ��	
//	s16 Speed;			//�ٶ�
//	s16 TCurrent; 	//����	
//} ZLAC706_Receive;

////ת�������� ��ǰ��״̬ ���� �ٶ� ���� 
//typedef struct
//{
//	u16  State;         //��ǰ״̬ ���������쳣   10����10 16���� A
//	s32 Position;		    //λ��	   10����1033    16����409  
//	s32 Speed;			    //�ٶ�           1036          40C
//} ZWSK_Receive;

void CAN_DATA_Receive(void);
void ZLAC706Data_deal(ZLAC706_Receive *Receive,CanRxMsg *msg);
void ZWSKData_deal(ZWSK_Receive *Receive,CanRxMsg *msg);
void showState(void);		//��ʾ״̬
#endif

