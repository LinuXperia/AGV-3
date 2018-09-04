#include "main.h"

//  ת�����  ��챼���
int Count=0,hubCount             = 0;
/**************************************
*  ����ת  ǰ��  ����   תΪ����״̬  
*											 תΪ��ת����
****************************************/
void Normal_Control_Task(void)	
{
	switch(key)
	{
		case 6: //��ת  PSB_PAD_RIGHT,
		{
			if((right_flag1!=1)&&(right_flag2!=1)&&(right_flag3!=1)&&(right_flag4!=1))
			{
				Count--;
			} 
//			steeringRation(Count);  //��ȡת��ֵ
			angle_--;
			action(angle_);         //����ÿ��ת��ֵ

			key=0;
			#if LCDSHOWN
			LCD_ShowString(50,130,200,16,16,"turnRight");
			#endif
			if(encode1_value>min_encode1_value&&encode2_value>min_encode2_value&&encode3_value>min_encode3_value&&encode4_value>min_encode4_value)
			{	
				setSteeringServoRotation(0x0001,angle1);
				setSteeringServoRotation(0x0002,angle2);
				setSteeringServoRotation(0x0003,angle3);
				setSteeringServoRotation(0x0004,angle4);
				
			}
			break;
		}	
		case 8:              //��ת   PSB_PAD_LEFT,
		{
			if((left_flag1!=1)&&(left_flag2!=1)&&(left_flag3!=1)&&(left_flag4!=1))
			{
			  Count++;
			} 
			steeringRation(Count);
			angle_++;
			action(angle_);
			key=0;
			#if LCDSHOWN 
			LCD_ShowString(50,130,200,16,16,"turnLeft");
			#endif
			if(encode1_value<max_encode1_value&&encode2_value<max_encode2_value&&encode3_value<max_encode3_value&&encode4_value<max_encode4_value)
			{	
					setSteeringServoRotation(0x0001,angle1);
					setSteeringServoRotation(0x0002,angle2);
					setSteeringServoRotation(0x0003,angle3);
					setSteeringServoRotation(0x0004,angle4);
			}		
			break;
		} 
		case 9:               	    //PSB_L2,   ����� 
		{
			Count=0;
			hubCount=0;
			steering_speed=0;
			hubmotor_speed=0;
			stop();
			workState=Zeroing;						 
			break;
		}
		case 10:             	 		  //PSB_R2,    ��ת�Ƕ����ü�
		{
			Count=0;
			hubCount=0;
			steering_speed=0;
			hubmotor_speed=0;
			stop();
			workState=InSituRoing;	 
			break;
		}
		case 11:            			 //ת��ͣ  PSB_L1,
		{
			steering_speed=0;
			Count=0;
			#if LCDSHOWN
			LCD_ShowxNum(150,130,Count,8,16,0X00);
			#endif
			sendSteeringControlCMD();
			break;
		}
		case 12: 									//��챼�ͣ    PSB_R1 
		{
			hubmotor_speed=0;
			hubCount=0;
			break;
		}
		case 13: 									//���ǰ��  PSB_GREEN,
		{
			LCD_ShowString(50,130,200,16,16,"Forward");
			hubCount++;
		//	hubMotorSpeed(hubCount);
			hubmotor_speed+=5;
			break;
		}	
		case 14: 																					//red,ǰ��ʧ��
		{
//			setHubMotorEnable(0x0005,0);           				//����챵��5	
//			setHubMotorEnable(0x0006,0);           				//����챵��6		
//			setHubMotorEnable(0x0007,1);           				//����챵��7
//			setHubMotorEnable(0x0008,1);           				//����챵��8
//			setHubMotorMode(1);   												//����Ϊ�ٶ�ģʽ
//			setHubMotorPlusSubSpeed(1);                   //�����ٶ�ģʽ�Ӽ���ʱ��  Ĭ��ֵ	
				setSteeringServoControlEnable(0x0003, 0);
				setSteeringServoControlEnable(0x0004, 0);
			break;
		}	
		case 15: 								//��챺���  PSB_BLUE,
		{
			LCD_ShowString(50,130,200,16,16,"Back    ");
			hubCount--;
//			hubMotorSpeed(hubCount);
			hubmotor_speed-=5;
			break;
		}	
		case 16: 																				// PSB_PINK  ����ʧ��
		{
//			setHubMotorEnable(0x0005,1);           				//����챵��5	
//			setHubMotorEnable(0x0006,1);           				//����챵��6		
//			setHubMotorEnable(0x0007,0);           				//����챵��7
//			setHubMotorEnable(0x0008,0);           				//����챵��8
//			setHubMotorMode(1);   												//����Ϊ�ٶ�ģʽ
//			setHubMotorPlusSubSpeed(1);                   //�����ٶ�ģʽ�Ӽ���ʱ��  Ĭ��ֵ	
			break;
		}	
		default:
			break;		
	}

}
void Zeroing_Task(void)
{
	returnToZero();
	//��������һ�����ģʽ
	Count=0;
	hubCount=0;
	steering_speed=0;
	hubmotor_speed=0;
	workState=Normal_Control;
}
void InSituRo_Control_Task(void)
{
	switch(key)
	{
		case 14:             	 		  //PSB_R2,    �˳���ת����ģʽ
		{
			hubCount=0;
			hubmotor_speed=0;
			hubmotor_speed_1=0;
			hubmotor_speed_2=0;
			hubmotor_speed_3=0;
			hubmotor_speed_4=0;
			setHubMotorTargetSpeed(0x0005,0);
			setHubMotorTargetSpeed(0x0006,0);
			setHubMotorTargetSpeed(0x0007,0);
			setHubMotorTargetSpeed(0x0008,0);
			workState=Zeroing;	      //�Ƚ������ģʽ �ٽ���һ�����ģʽ			
			break;
		}
		case 12: 									//��챼�ͣ    PSB_R1 
		{
			hubmotor_speed=0;
			hubmotor_speed_1=0;
			hubmotor_speed_2=0;
			hubmotor_speed_3=0;
			hubmotor_speed_4=0;
			hubCount=0;
			break;
		}
		case 13: 									//��ת��ת  PSB_GREEN,
		{
			hubCount++;
			hubMotorSpeed(hubCount);
			break;
		}	
		case 15: 								 //��ת��ת PSB_BLUE,
		{
			hubCount--;
			hubMotorSpeed(hubCount);
			break;
		}	
		default:
			break;		
	}
}
void InSituRoing_Task(void)
{
	InSituRotation();						  //ת������תģʽָ���Ƕ�
	Count=0;
	hubCount=0;
	steering_speed=0;
	hubmotor_speed=0;
	key=0;
	workState=InSituRo_Control;   //���뵽��ת����ģʽ
}
void Stop_Task(void)
{

}


//ת�����챶��� �ٶȡ�λ��������������
void Speed_Postion_Control_Task(void)
{
	switch(key)
	{
		case 6: //��ת  PSB_PAD_RIGHT,
		{
			if((right_flag1!=1)&&(right_flag2!=1)&&(right_flag3!=1)&&(right_flag4!=1))
			{
				Count--;
			} 
		 

			key=0;
			#if LCDSHOWN
			LCD_ShowString(50,130,200,16,16,"turnRight");
			#endif
			if(encode1_value>min_encode1_value&&encode2_value>min_encode2_value&&encode3_value>min_encode3_value&&encode4_value>min_encode4_value)
			{	

				
			}
			break;
		}	
		case 8:              //��ת   PSB_PAD_LEFT,
		{
			if((left_flag1!=1)&&(left_flag2!=1)&&(left_flag3!=1)&&(left_flag4!=1))
			{
			  Count++;
			} 
			steeringRation(Count);
			angle_++;
			action(angle_);
			key=0;
			#if LCDSHOWN 
			LCD_ShowString(50,130,200,16,16,"turnLeft");
			#endif
			if(encode1_value<max_encode1_value&&encode2_value<max_encode2_value&&encode3_value<max_encode3_value&&encode4_value<max_encode4_value)
			{	

			}		
			break;
		} 
		case 9:               	    //PSB_L2,   ����� 
		{
			Count=0;
			hubCount=0;
			steering_speed=0;
			hubmotor_speed=0;
			stop();
			workState=Zeroing;						 
			break;
		}
		case 10:             	 		  //PSB_R2,    ��ת�Ƕ����ü�
		{
			Count=0;
			hubCount=0;
			steering_speed=0;
			hubmotor_speed=0;
			stop();
			workState=InSituRoing;	 
			break;
		}
		case 11:            			 //ת��ͣ  PSB_L1,
		{
			steering_speed=0;
			Count=0;
			#if LCDSHOWN
			LCD_ShowxNum(150,130,Count,8,16,0X00);
			#endif
			sendSteeringControlCMD();
			break;
		}
		case 12: 									//��챼�ͣ    PSB_R1 
		{
		//	hubmotor_speed=0;
			EMB(0x0005);
			EMB(0x0006);
			EMB(0x0007);
			EMB(0x0008);
			hubCount=0;
			break;
		}
		case 13: 									//���ǰ��  PSB_GREEN,
		{
			LCD_ShowString(50,130,200,16,16,"Forward");
			hubCount++;
			hubMotorPul(hubCount);            //�����ٶ�
			break;
		}	
		case 14: 																					//red
		{


			break;
		}	
		case 15: 								//��챺���  PSB_BLUE,
		{
			LCD_ShowString(50,130,200,16,16,"Back    ");
			hubCount--;
			hubMotorPul(hubCount);            //�����ٶ�
			break;
		}	
		case 16: 																				// PSB_PINK  ����ʧ��
		{

			break;
		}	
		default:
			break;		
	}

}

