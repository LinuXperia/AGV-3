#include "variable.h"

								
int main(void)
{	  	
	hardwareInit();																															//Ӳ����ʼ��
  hubMotorInit(2);	  																												//��ʼ����챵��Ϊ�ⲿ������Ʒ�ʽ
	steeringServoInit(2);                                                       //��ʼ��ת����Ϊ�ٶ�ģʽ
	loop1:
	if(encode1_value==0||encode2_value==0||encode3_value==0||encode4_value==0)   //ȷ�����յ�һ�ξ��Ա���������ֵ
	{
		delay_ms(50);
		goto loop1;
	}
	zeroState=returnToZero();  																									//����ɹ�Ϊ1  �����쳣Ϊ0
	steeringServoInit(3);                                                       //��ʼ��ת����Ϊλ��ģʽ
	workState=Speed_Postion_Control;
	while(1)
	{	
		
		
		sendDriverCAN();
	  showState();	
		switch(workState)		
		{
			case Normal_Control:							//һ�����ģʽ
			{
				Normal_Control_Task();
				break;
			}
			case Zeroing:											//����״̬
			{
				Zeroing_Task();
				break;
			}
			case InSituRo_Control:					//��ת����ģʽ
			{
				
				InSituRo_Control_Task();
				break;
			}
			case InSituRoing:								//��ת����תָ���Ƕ�
			{
				InSituRoing_Task();
				break;
			}
			case Speed_Postion_Control:								//�ٶȺ�λ��������������ת������
			{
				Speed_Postion_Control_Task();
				break;
			}
			case Stop:
			{
				break;
			}
			default:
				break;	
		}
		if(workState==Normal_Control)
		{
			sendHubControlCMD();
		}
		else if(workState==InSituRo_Control)
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
				setHubMotorTargetSpeed(0x0005,hubmotor_speed);
				setHubMotorTargetSpeed(0x0006,hubmotor_speed);
				setHubMotorTargetSpeed(0x0007,hubmotor_speed);
				setHubMotorTargetSpeed(0x0008,hubmotor_speed);
			}	
		}
			 
	}
}
