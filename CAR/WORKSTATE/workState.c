#include "main.h"

//  转向计数  轮毂计数
int Count=0,hubCount             = 0;
/**************************************
*  左右转  前进  后退   转为归零状态  
*											 转为自转控制
****************************************/
void Normal_Control_Task(void)	
{
	switch(key)
	{
		case 6: //右转  PSB_PAD_RIGHT,
		{
			if((right_flag1!=1)&&(right_flag2!=1)&&(right_flag3!=1)&&(right_flag4!=1))
			{
				Count--;
			} 
//			steeringRation(Count);  //获取转角值
			angle_--;
			action(angle_);         //计算每个转角值

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
		case 8:              //左转   PSB_PAD_LEFT,
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
		case 9:               	    //PSB_L2,   归零键 
		{
			Count=0;
			hubCount=0;
			steering_speed=0;
			hubmotor_speed=0;
			stop();
			workState=Zeroing;						 
			break;
		}
		case 10:             	 		  //PSB_R2,    自转角度设置键
		{
			Count=0;
			hubCount=0;
			steering_speed=0;
			hubmotor_speed=0;
			stop();
			workState=InSituRoing;	 
			break;
		}
		case 11:            			 //转向急停  PSB_L1,
		{
			steering_speed=0;
			Count=0;
			#if LCDSHOWN
			LCD_ShowxNum(150,130,Count,8,16,0X00);
			#endif
			sendSteeringControlCMD();
			break;
		}
		case 12: 									//轮毂急停    PSB_R1 
		{
			hubmotor_speed=0;
			hubCount=0;
			break;
		}
		case 13: 									//轮毂前进  PSB_GREEN,
		{
			LCD_ShowString(50,130,200,16,16,"Forward");
			hubCount++;
		//	hubMotorSpeed(hubCount);
			hubmotor_speed+=5;
			break;
		}	
		case 14: 																					//red,前面失能
		{
//			setHubMotorEnable(0x0005,0);           				//打开轮毂电机5	
//			setHubMotorEnable(0x0006,0);           				//打开轮毂电机6		
//			setHubMotorEnable(0x0007,1);           				//打开轮毂电机7
//			setHubMotorEnable(0x0008,1);           				//打开轮毂电机8
//			setHubMotorMode(1);   												//设置为速度模式
//			setHubMotorPlusSubSpeed(1);                   //设置速度模式加减速时间  默认值	
				setSteeringServoControlEnable(0x0003, 0);
				setSteeringServoControlEnable(0x0004, 0);
			break;
		}	
		case 15: 								//轮毂后退  PSB_BLUE,
		{
			LCD_ShowString(50,130,200,16,16,"Back    ");
			hubCount--;
//			hubMotorSpeed(hubCount);
			hubmotor_speed-=5;
			break;
		}	
		case 16: 																				// PSB_PINK  后面失能
		{
//			setHubMotorEnable(0x0005,1);           				//打开轮毂电机5	
//			setHubMotorEnable(0x0006,1);           				//打开轮毂电机6		
//			setHubMotorEnable(0x0007,0);           				//打开轮毂电机7
//			setHubMotorEnable(0x0008,0);           				//打开轮毂电机8
//			setHubMotorMode(1);   												//设置为速度模式
//			setHubMotorPlusSubSpeed(1);                   //设置速度模式加减速时间  默认值	
			break;
		}	
		default:
			break;		
	}

}
void Zeroing_Task(void)
{
	returnToZero();
	//归零后进入一般控制模式
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
		case 14:             	 		  //PSB_R2,    退出自转控制模式
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
			workState=Zeroing;	      //先进入归零模式 再进入一般控制模式			
			break;
		}
		case 12: 									//轮毂急停    PSB_R1 
		{
			hubmotor_speed=0;
			hubmotor_speed_1=0;
			hubmotor_speed_2=0;
			hubmotor_speed_3=0;
			hubmotor_speed_4=0;
			hubCount=0;
			break;
		}
		case 13: 									//自转左转  PSB_GREEN,
		{
			hubCount++;
			hubMotorSpeed(hubCount);
			break;
		}	
		case 15: 								 //自转右转 PSB_BLUE,
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
	InSituRotation();						  //转动到自转模式指定角度
	Count=0;
	hubCount=0;
	steering_speed=0;
	hubmotor_speed=0;
	key=0;
	workState=InSituRo_Control;   //进入到自转控制模式
}
void Stop_Task(void)
{

}


//转向和轮毂都是 速度、位置两个参数控制
void Speed_Postion_Control_Task(void)
{
	switch(key)
	{
		case 6: //右转  PSB_PAD_RIGHT,
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
		case 8:              //左转   PSB_PAD_LEFT,
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
		case 9:               	    //PSB_L2,   归零键 
		{
			Count=0;
			hubCount=0;
			steering_speed=0;
			hubmotor_speed=0;
			stop();
			workState=Zeroing;						 
			break;
		}
		case 10:             	 		  //PSB_R2,    自转角度设置键
		{
			Count=0;
			hubCount=0;
			steering_speed=0;
			hubmotor_speed=0;
			stop();
			workState=InSituRoing;	 
			break;
		}
		case 11:            			 //转向急停  PSB_L1,
		{
			steering_speed=0;
			Count=0;
			#if LCDSHOWN
			LCD_ShowxNum(150,130,Count,8,16,0X00);
			#endif
			sendSteeringControlCMD();
			break;
		}
		case 12: 									//轮毂急停    PSB_R1 
		{
		//	hubmotor_speed=0;
			EMB(0x0005);
			EMB(0x0006);
			EMB(0x0007);
			EMB(0x0008);
			hubCount=0;
			break;
		}
		case 13: 									//轮毂前进  PSB_GREEN,
		{
			LCD_ShowString(50,130,200,16,16,"Forward");
			hubCount++;
			hubMotorPul(hubCount);            //设置速度
			break;
		}	
		case 14: 																					//red
		{


			break;
		}	
		case 15: 								//轮毂后退  PSB_BLUE,
		{
			LCD_ShowString(50,130,200,16,16,"Back    ");
			hubCount--;
			hubMotorPul(hubCount);            //设置速度
			break;
		}	
		case 16: 																				// PSB_PINK  后面失能
		{

			break;
		}	
		default:
			break;		
	}

}

