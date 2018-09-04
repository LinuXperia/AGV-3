#include "main.h"


int i=0;   //临时变量
ZLAC706_Receive ZLAC706[4]={0};    //轮毂电机 
ZWSK_Receive    ZWSK[4]={0};       // 转向电机 

void ZLAC706Data_deal(ZLAC706_Receive *Receive,CanRxMsg *msg)
{
	if(msg->Data[1]==0xFF)
	{
		Receive->State=msg->Data[4];													 //异常状态  08编码器故障 20欠压  40 过载
	}
	else if(msg->Data[1]==0xFE&&msg->Data[3]==0x20)   //解析出位置
	{
		Receive->State=0;														    //正常状态
		Receive->Position=((s32)msg->Data[4]<<24 |
												(s32)msg->Data[5]<<16|
												(s32)msg->Data[6]<<8 |
												(s32)msg->Data[7]);
	}
	else if(msg->Data[1]==0xFE&&msg->Data[3]==0x21)   //解析出电流和速度 
	{
		Receive->State=0;														    //正常状态
		Receive->TCurrent =((s16)msg->Data[4]<<8|
												(s16)msg->Data[5]);
		Receive->Speed    =((s16)msg->Data[6]<<8|
												(s16)msg->Data[7]);
	}
}

void ZWSKData_deal(ZWSK_Receive *Receive,CanRxMsg *msg)
{
	switch((u16)(msg->ExtId))
	{
		case 0x000A: //当前状态
			Receive->State=(((uint32_t)msg->Data[3] << 24) |     //0代表没有错误
                      ((uint32_t)msg->Data[2] << 16) |
                      ((uint32_t)msg->Data[1] << 8)  | 
                      ((uint32_t)msg->Data[0]));
			break;
		case 0x0409:
			Receive->Position=(
												 ((s32)msg->Data[3] << 24) | 
												 ((s32)msg->Data[2] << 16) |
												 ((s32)msg->Data[1] << 8)  | 
												 ((s32)msg->Data[0]));
			break;
		case 0x040C:

			Receive->Speed=   (((s32)msg->Data[3] << 24) | 
												 ((s32)msg->Data[2] << 16) |
												 ((s32)msg->Data[1] << 8)  | 
												 ((s32)msg->Data[0]));
			break;
		default:
			break;
	
	}

}

//接收can中的数据
void CAN_DATA_Receive(void)
{
	 CanRxMsg RxMessage;
	 CAN_Receive(CAN1, 0, &RxMessage);
	 if(RxMessage.IDE== CAN_Id_Standard)
	 {
		  switch(RxMessage.StdId)
		 {
			 case 0x0005:
				 ZLAC706Data_deal(&ZLAC706[0],&RxMessage);
				 break;
			 case 0x0006:
				 ZLAC706Data_deal(&ZLAC706[1],&RxMessage);
				 break;	 
			 case 0x0007:
				 ZLAC706Data_deal(&ZLAC706[2],&RxMessage);
				 break;
			 case 0x0008:
				 ZLAC706Data_deal(&ZLAC706[3],&RxMessage);
				 break; 
			 default:
					break;
			}
		}
	 else
	 {
		 switch(RxMessage.ExtId>>16)
		 {
			 case 0x0001:
				 ZWSKData_deal(&ZWSK[0],&RxMessage);
				 break;
			 case 0x0002:
				 ZWSKData_deal(&ZWSK[1],&RxMessage);
				 break;	 
			 case 0x0003:
				 ZWSKData_deal(&ZWSK[2],&RxMessage);
				 break;
			 case 0x0004:
				 ZWSKData_deal(&ZWSK[3],&RxMessage);
				 break; 
			 default:
					break;
			}
		}
}

void showState(void)
{
 unsigned short	new_encode1_value,new_encode2_value,new_encode3_value,new_encode4_value;
//	new_encode1_value=encode1_value-zero_encode1_value;
//	new_encode2_value=encode2_value-zero_encode2_value;
//	new_encode3_value=encode3_value-zero_encode3_value;
//	new_encode4_value=encode4_value-zero_encode4_value;
	new_encode1_value=encode1_value;
	new_encode2_value=encode2_value;
	new_encode3_value=encode3_value;
	new_encode4_value=encode4_value;
	//转向电机
	printf("\r%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%f,%f,%f,%f,%d\r\n",
	ZWSK[0].State,ZWSK[0].Position,ZWSK[0].Speed,
	ZWSK[1].State,ZWSK[1].Position,ZWSK[1].Speed,
	ZWSK[2].State,ZWSK[2].Position,ZWSK[2].Speed,
	ZWSK[3].State,ZWSK[3].Position,ZWSK[3].Speed,
	ZLAC706[0].State,ZLAC706[0].Position,ZLAC706[0].Speed,ZLAC706[0].TCurrent,
	ZLAC706[1].State,ZLAC706[1].Position,ZLAC706[1].Speed,ZLAC706[1].TCurrent,
	ZLAC706[2].State,ZLAC706[2].Position,ZLAC706[2].Speed,ZLAC706[2].TCurrent,
	ZLAC706[3].State,ZLAC706[3].Position,ZLAC706[3].Speed,ZLAC706[3].TCurrent,
	new_encode1_value,new_encode2_value,new_encode3_value,new_encode4_value,
	angle1,angle2,angle3,angle4,hubmotor_speed); 

	LCD_ShowxNum(100,330,(int)(ZWSK[0].State),8,16,0X00);
	LCD_ShowxNum(300,330,(int)(ZWSK[0].Position),8,16,0X00);
	LCD_ShowxNum(200,330,(int)(ZWSK[0].Speed),8,16,0X00);
	LCD_ShowxNum(100,360,(int)(ZWSK[1].State),8,16,0X00);
	LCD_ShowxNum(300,360,(int)(ZWSK[1].Position),8,16,0X00);
	LCD_ShowxNum(200,360,(int)(ZWSK[1].Speed),8,16,0X00);
	LCD_ShowxNum(100,390,(int)(ZWSK[2].State),8,16,0X00);
	LCD_ShowxNum(300,390,(int)(ZWSK[2].Position),8,16,0X00);
	LCD_ShowxNum(200,390,(int)(ZWSK[2].Speed),8,16,0X00);
	LCD_ShowxNum(100,420,(int)(ZWSK[3].State),8,16,0X00);
	LCD_ShowxNum(300,420,(int)(ZWSK[3].Position),8,16,0X00);
	LCD_ShowxNum(200,420,(int)(ZWSK[3].Speed),8,16,0X00);
	
	//轮毂电机	
	LCD_ShowxNum(100,180,(int)(ZLAC706[0].State),8,16,0X00);
	LCD_ShowxNum(200,180,(int)(ZLAC706[0].Speed),8,16,0X00);
	LCD_ShowxNum(300,180,(int)(ZLAC706[0].Position),8,16,0X00);
	LCD_ShowxNum(100,210,(int)(ZLAC706[1].State),8,16,0X00);
	LCD_ShowxNum(200,210,(int)(ZLAC706[1].Speed),8,16,0X00);
	LCD_ShowxNum(300,210,(int)(ZLAC706[1].Position),8,16,0X00);
	LCD_ShowxNum(100,240,(int)(ZLAC706[2].State),8,16,0X00);	
	LCD_ShowxNum(200,240,(int)(ZLAC706[2].Speed),8,16,0X00);
	LCD_ShowxNum(300,240,(int)(ZLAC706[2].Position),8,16,0X00);
	LCD_ShowxNum(100,270,(int)(ZLAC706[3].State),8,16,0X00);
	LCD_ShowxNum(200,270,(int)(ZLAC706[3].Speed),8,16,0X00);
	LCD_ShowxNum(300,270,(int)(ZLAC706[3].Position),8,16,0X00);
}
