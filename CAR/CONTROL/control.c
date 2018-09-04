#include "main.h"

//�����쳣 ����ת����Ϊ0 ������챵���ٶ�Ϊ0	
void stop(void)
{	
	setSteeringServoSpeed(0x0001, 0);
	setSteeringServoSpeed(0x0002, 0);
	setSteeringServoSpeed(0x0003, 0);
	setSteeringServoSpeed(0x0004, 0);
	setHubMotorTargetSpeed(0x0005,0);
	setHubMotorTargetSpeed(0x0006,0);
	setHubMotorTargetSpeed(0x0007,0);
	setHubMotorTargetSpeed(0x0008,0);
}

void sendSteeringControlCMD(void)
{
	sendSteeringControlCMD_Flag  = 0;
	setSteeringServoSpeed(0x0001, steering_speed);
	setSteeringServoSpeed(0x0002, steering_speed);
	setSteeringServoSpeed(0x0003, steering_speed);
	setSteeringServoSpeed(0x0004, steering_speed);
}

void sendHubControlCMD(void)
{
	if(hubmotor_speed==0)
	{
		setHubMotorTargetSpeed(0x0005,0);
		setHubMotorTargetSpeed(0x0006,0);
		setHubMotorTargetSpeed(0x0007,0);
		setHubMotorTargetSpeed(0x0008,0);
	}
	else
	{
		if(turnFlag==0)  //��ת
		{
			hubmotor_speed_1=hubmotor_speed;
			hubmotor_speed_2=hubmotor_speed_1*R2/R1;
			hubmotor_speed_3=hubmotor_speed;
			hubmotor_speed_4=hubmotor_speed_3*R2/R1;
		}
		else if(turnFlag==1)  //��ת
		{
			hubmotor_speed_1=hubmotor_speed_2*R1/R2;
			hubmotor_speed_2=hubmotor_speed;
			hubmotor_speed_3=hubmotor_speed_4*R1/R2;
			hubmotor_speed_4=hubmotor_speed;
		}
		else if(turnFlag==2)  //ֱ��
		{
			hubmotor_speed_1=hubmotor_speed;
			hubmotor_speed_2=hubmotor_speed;
			hubmotor_speed_3=hubmotor_speed;
			hubmotor_speed_4=hubmotor_speed;
		}
		setHubMotorTargetSpeed(0x0005,hubmotor_speed_1);
		setHubMotorTargetSpeed(0x0006,-hubmotor_speed_2);
		setHubMotorTargetSpeed(0x0007,hubmotor_speed_3);
		setHubMotorTargetSpeed(0x0008,-hubmotor_speed_4);
	}	
}

void sendDriverCAN(void)
{
//	u8 canbuf_Steering[2];
//	//��ȡ�ĸ���������״̬  ����Զ��֡
//	canbuf_Steering[0] = 0x00;
//	CAN_Send_Msg(canbuf_Steering, 1,1, 0x0001000A,1);
//	delay_ms(1);
//	CAN_Send_Msg(canbuf_Steering, 1,1, 0x0001040C,1);
//	delay_us(100);
//	CAN_Send_Msg(canbuf_Steering, 1,1, 0x00010409,1);	
//	delay_us(100);
//	CAN_Send_Msg(canbuf_Steering, 1,1, 0x0002000A,1);
//	delay_us(100);
//	CAN_Send_Msg(canbuf_Steering, 1,1, 0x00020409,1);	
//	delay_us(100);
//	CAN_Send_Msg(canbuf_Steering, 1,1, 0x0002040C,1);
//	delay_us(100);
//	CAN_Send_Msg(canbuf_Steering, 1,1, 0x0003000A,1);
//	delay_us(100);
//	CAN_Send_Msg(canbuf_Steering, 1,1, 0x00030409,1);	
//	delay_us(100);
//	CAN_Send_Msg(canbuf_Steering, 1,1, 0x0003040C,1);
//	delay_us(100);
//	CAN_Send_Msg(canbuf_Steering, 1,1, 0x0004000A,1);
//	delay_us(100);
//	CAN_Send_Msg(canbuf_Steering, 1,1, 0x00040409,1);
//	delay_us(100);	
//	CAN_Send_Msg(canbuf_Steering, 1,1, 0x0004040C,1);	
//	delay_us(100);
	
		u8 canbuf_Steering[2];
	//��ȡ�ĸ���������״̬  ����Զ��֡
	canbuf_Steering[0] = 0x00;
	CAN_Send_Msg(canbuf_Steering, 1,1, 0x0001000A,1);
	delay_ms(1);
	CAN_Send_Msg(canbuf_Steering, 1,1, 0x0001040C,1);
	delay_ms(1);
	CAN_Send_Msg(canbuf_Steering, 1,1, 0x00010409,1);	
	delay_ms(1);
	CAN_Send_Msg(canbuf_Steering, 1,1, 0x0002000A,1);
	delay_ms(1);
	CAN_Send_Msg(canbuf_Steering, 1,1, 0x00020409,1);	
	delay_ms(1);
	CAN_Send_Msg(canbuf_Steering, 1,1, 0x0002040C,1);
	delay_ms(1);
	CAN_Send_Msg(canbuf_Steering, 1,1, 0x0003000A,1);
	delay_ms(1);
	CAN_Send_Msg(canbuf_Steering, 1,1, 0x00030409,1);	
	delay_ms(1);
	CAN_Send_Msg(canbuf_Steering, 1,1, 0x0003040C,1);
	delay_ms(1);
	CAN_Send_Msg(canbuf_Steering, 1,1, 0x0004000A,1);
	delay_ms(1);
	CAN_Send_Msg(canbuf_Steering, 1,1, 0x00040409,1);
	delay_ms(1);	
	CAN_Send_Msg(canbuf_Steering, 1,1, 0x0004040C,1);	
	delay_ms(1);

}

