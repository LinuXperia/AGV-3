#ifndef __CAN_H
#define __CAN_H	 
#include "sys.h"	  

#define CAN_RX0_INT_ENABLE	1		//0,��ʹ��;1,ʹ��.	


u8 CAN_Mode_Init(u8 tsjw,u8 tbs2,u8 tbs1,u16 brp,u8 mode);//CAN��ʼ��
u8 CAN_Send_Msg(u8* msg,u8 len,uint8_t IDE,uint32_t ID,u32 RTR);						//��������
#endif

















