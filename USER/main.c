#include "variable.h"

								
int main(void)
{	  	
	hardwareInit();																															//硬件初始化
  hubMotorInit(2);	  																												//初始化轮毂电机为外部脉冲控制方式
	steeringServoInit(2);                                                       //初始化转向电机为速度模式
	loop1:
	if(encode1_value==0||encode2_value==0||encode3_value==0||encode4_value==0)   //确定先收到一次绝对编码器的数值
	{
		delay_ms(50);
		goto loop1;
	}
	zeroState=returnToZero();  																									//归零成功为1  归零异常为0
	steeringServoInit(3);                                                       //初始化转向电机为位置模式
	workState=Speed_Postion_Control;
	while(1)
	{	
		
		
		sendDriverCAN();
	  showState();	
		switch(workState)		
		{
			case Normal_Control:							//一般控制模式
			{
				Normal_Control_Task();
				break;
			}
			case Zeroing:											//归零状态
			{
				Zeroing_Task();
				break;
			}
			case InSituRo_Control:					//自转控制模式
			{
				
				InSituRo_Control_Task();
				break;
			}
			case InSituRoing:								//运转到自转指定角度
			{
				InSituRoing_Task();
				break;
			}
			case Speed_Postion_Control:								//速度和位置两个参数控制转向和轮毂
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
