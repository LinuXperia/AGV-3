#include "main.h"


double  sumRotation=0.0;
u8 canbuf_Steering[32];

/******************************************************************** 
* 名称：setSteeringServoMotoCtrlSign                 
* 功能： 设置转向电机控制信号来源                
* 入口参数：
		u16 DevID; 0x0001 0x0002 0x0003 0x0004
		int i;  0：通过外部信号控制  1：通过上位机指令控制                     
*                              
* 出口参数： 无       
*******************************************************************/ 
void setSteeringServoMotoCtrlSign( u16 DevID,u8 i)
{
	if(i==1)  //如果是上位机指令控制
	{					
		canbuf_Steering[0]=0x10;																										//按照文档上写的应该发送0x01  目测应该是文档写错了  必须发送0x10 (我也很惆怅啊)
		canbuf_Steering[1]=0x00;
		canbuf_Steering[2]=0x00;
		canbuf_Steering[3]=0x00;
		CAN_Send_Msg(canbuf_Steering, 4, 1,(u32)(u32)DevID<<16|(u32)(u32)0x0130,0);  //将设备ID和属性ID合并为扩展ID
		delay_ms(1);																																					 //对应文档中   属性304

	}
	else
	{
		canbuf_Steering[0]=0x00;
		canbuf_Steering[1]=0x00;
		canbuf_Steering[2]=0x00;
		canbuf_Steering[3]=0x00;
		CAN_Send_Msg(canbuf_Steering, 4,1, (u32)DevID<<16|(u32)0x0130,0);
		delay_ms(1);
	}
}


/******************************************************************** 
* 名称：setSteeringServoMoto              
* 功能：设置转向电机模式                
* 入口参数：
		u16 DevID; 0x0001 0x0002 0x0003 0x0004
		u8 i;   0  开环控制

				1  转矩控制  只对伺服类驱动器有效
				2  速度/转矩控制
				3  位置/转矩控制
					暂不提供
				4  位置/速度/转矩控制
					只对伺服驱动器有效                    
*                              
* 出口参数： 无       
*******************************************************************/
void setSteeringServoMode(u16 DevID,int i)
{
	if(i==0)
	{
		canbuf_Steering[0] = 0x00;
		CAN_Send_Msg(canbuf_Steering, 1,1, (u32)DevID<<16|(u32)0x0303,0);					//对应文档中   属性771
		delay_ms(1);
	}
	else if(i==1)
	{
		canbuf_Steering[0] = 0x01;
		CAN_Send_Msg(canbuf_Steering, 1,1, (u32)DevID<<16|(u32)0x0303,0);
		delay_ms(1);
	}
	else if(i==2)
	{
		canbuf_Steering[0] = 0x02;
		CAN_Send_Msg(canbuf_Steering, 1,1, (u32)DevID<<16|(u32)0x0303,0);
		delay_ms(1);
	}
		else if(i==3)
	{
		canbuf_Steering[0] = 0x03;
		CAN_Send_Msg(canbuf_Steering, 1,1, (u32)DevID<<16|(u32)0x0303,0);
		delay_ms(1);
	}
	else if(i==4)
	{
		canbuf_Steering[0] = 0x04;
		CAN_Send_Msg(canbuf_Steering, 1,1, (u32)DevID<<16|(u32)0x0303,0);
		delay_ms(1);
		//LCD_ShowString(30,40,200,16,16,"locationMode");
	}
		
}


/******************************************************************** 
* 名称：setSteeringServoControlEnable                
* 功能：转向电机控制使能                
* 入口参数：
		u16 DevID; 0x0001 0x0002 0x0003 0x0004
		u8 i;   该状态可以由上位机或者外部信号修改，失能后进入 IDLE 状态
						0：失能电机控制  
						1：使能电机控制                    
*                              
* 出口参数： 无       
*******************************************************************/
void setSteeringServoControlEnable(u16 DevID,u8 i)
{
	
	if(i==1)
	{
		canbuf_Steering[0] = 0x01;
		CAN_Send_Msg(canbuf_Steering, 1, 1,(u32)DevID<<16|(u32)0x0300,0);   //对应文档中   属性768
		delay_ms(1);
		
	}
	else
	{
		canbuf_Steering[0] = 0x00;
		CAN_Send_Msg(canbuf_Steering, 1,1, (u32)DevID<<16|(u32)0x0300,0);
		delay_ms(1);
		
	}
}	
	
/******************************************************************** 
* 名称：steeringSpeed               
* 功能：转速计算                
* 入口参数：
		int cunt                  
*                              
* 出口参数： 无       
*******************************************************************/
void steeringSpeed(int Count)
{

 if(Count>0&&Count<=8)
	{
		steering_speed=4;
  }
	else if(Count>8&&Count<=16)
	{
		steering_speed=8;
	}
	else if(Count>16&&Count<24)
	{
		steering_speed=12;
	}
	else if(Count>24)
	{
		Count=24;
	}
	else if(Count==0)
	{
		steering_speed=0;
	}
	else if(Count<0&&Count>=(-8))
	{
		steering_speed=-4;
	}
	else if(Count<(-8)&&Count>=(-16))
	{
		steering_speed=-8;
	}
	else if(Count<(-16)&&Count>(-24))
	{
		steering_speed=-12;
	}
	else if(Count<(-24))
	{
		Count=(-24);
	}
}


/******************************************************************** 
* 名称：steeringRation              
* 功能：转速计算                
* 入口参数：
		int cunt                  
*                              
* 出口参数： 无       
*******************************************************************/
void steeringRation(int Count)
{

 if(Count>0&&Count<=8)
	{
		turnFlag=0;
		angle_=4;		
  }
	else if(Count>8&&Count<=16)
	{
		turnFlag=0;
		angle_=10;
	}
	else if(Count>16&&Count<24)
	{
		turnFlag=0;
		angle_=20;
	}
	else if(Count>24)
	{
		turnFlag=0;
		Count=24;
	}
	else if(Count==0)
	{
		turnFlag=2;
		angle_=0;
	}
	else if(Count<0&&Count>=(-8))
	{
		turnFlag=1;
		angle_=-4;
	}
	else if(Count<(-8)&&Count>=(-16))
	{
		turnFlag=1;
		angle_=-10;
	}
	else if(Count<(-16)&&Count>(-24))
	{
		turnFlag=1;
		angle_=-50;
	}
	else if(Count<(-24))
	{
		turnFlag=1;
		Count=(-24);
	}
}

/******************************************************************** 
* 名称：setSteeringServoZero             
* 功能：设置转向电机归零位         
* 入口参数：
		u16 DevID; 0x0001 0x0002 0x0003 0x0004                    
*                            
* 出口参数：    
*******************************************************************/
void setSteeringServoZero(u16 DevID)
{
//	unsigned char instruction[2][8] =
//  {
//   {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},      
//  };
//	
//	int d;
//	long steering;
//	long *p;
//	unsigned short EncoderVaule;
//	unsigned short abencoder_zero_a=6766;		//1号绝对编码器值（归零时）
//	unsigned short abencoder_zero_b=6093;		//2号绝对编码器值（归零时）
//	unsigned short abencoder_zero_c=6149;		//3号绝对编码器值（归零时）
//	unsigned short abencoder_zero_d=6344;		//4号绝对编码器值（归零时）

//	if(DevID==0x0001)
//	{
//		  EncoderVaule=getAbEncoderVaule((u8)DevID);		//获得绝对编码器的当前值
//			d=(int)abencoder_zero_a-(int)EncoderVaule;		//当前值与归零时做差
//			steering=(long)(d*11/256);										//换算为转向电机转动的距离   这里有误差11/256还需要确认
//			p = (long*)(instruction[0] + 0);							//将指令的地址赋给p
//			*p = steering;																//这样可以省去long型到unsigned short型的转换
//			CAN_Send_Msg(instruction[0],8,1,0x00010304,0);	//对应文档中   属性772
//			delay_ms(1);
//	}
//	
//	else if(DevID==0x0002)
//	{
//			EncoderVaule=getAbEncoderVaule((u8)DevID);
//			d=(int)abencoder_zero_b-(int)EncoderVaule;
//			steering=(long)(d*11/256);
//			p = (long*)(instruction[0] + 0);
//			*p = steering;
//			CAN_Send_Msg(instruction[0],8,1,0x00020304,0);
//			delay_ms(1);
//	}
//	
//	else if(DevID==0x0003)
//	{
//			EncoderVaule=getAbEncoderVaule((u8)DevID);
//			d=(int)abencoder_zero_c-(int)EncoderVaule;
//			steering=(long)(d*11/256);
//			p = (long*)(instruction[0] + 0);
//			*p = steering;
//			CAN_Send_Msg(instruction[0],8,1,0x00030304,0);
//			delay_ms(1);
//	}
//	
//	else if(DevID==0x0004)
//	{
//			EncoderVaule=getAbEncoderVaule((u8)DevID);
//			d=(int)abencoder_zero_d-(int)EncoderVaule;
//			steering=(long)(d*11/256);
//			p = (long*)(instruction[0] + 0);
//			*p = steering;
//			CAN_Send_Msg(instruction[0],8,1,0x00040304,0);
//			delay_ms(1);
//	}
}

/******************************************************************** 
* 名称：setSteeringServoNowZero           
* 功能：设置转向电机编码器当前位置为0          
* 入口参数：
		无                 
*                          
* 出口参数：    
*******************************************************************/
void setSteeringServoNowZero(void)			
{
			unsigned char instruction[2][8] =
		{
		 {0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00},      
		};
																																				//广播 设置转向编码器当前位置为0
		CAN_Send_Msg(instruction[0],1,1,0x00FF030A,0);												//对应文档中   属性778
		delay_ms(1);	
}

/******************************************************************** 
* 名称：setSteeringServoRotation             
* 功能：设置转向电机旋转角度           
* 入口参数：
		u16 DevID; 0x0001 0x0002 0x0003 0x0004                    
*    int rotation; 旋转角度   正值代表左转  负值代表右转                         
* 出口参数：    
*******************************************************************/

void setSteeringServoRotation(u16 DevID,double rotation)
{
	long Target=0;
	long *p;
	unsigned char instruction[2][8] =
	{
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}		 
	};
	//sumRotation+=rotation;         											//累加发送过来的角度  
	if(rotation>-90&&rotation<90)								//如果在左90度到右90度之间 
	{
			Target=(long)(rotation*1.667);             //小数点检查！！！
			p = (long*)instruction[0];
			*p=Target;
			CAN_Send_Msg(instruction[0],8,1,(u32)DevID<<16|(u32)0x0304,0);							//对应文档中   属性772
			delay_ms(1);
	}
	else if(rotation>=90)             									//限位  不让轮子转动超过90度
	{
			rotation=90;																		//设置当前角度为90
			Target=(long)(150);
			p = (long*)instruction[0];
			*p=Target;
			CAN_Send_Msg(instruction[0],8,1,(u32)DevID<<16|(u32)0x0304,0);
			delay_ms(1);
	}
	else if(rotation<=(-90))								
	{
			rotation=-90;																	//设置当前角度为-90
			Target=(long)(-150);
			p = (long*)instruction[0];
			*p=Target;
			CAN_Send_Msg(instruction[0],8,1,(u32)DevID<<16|(u32)0x0304,0);
			delay_ms(1);
	}
	
}


/******************************************************************** 
* 名称：setSteeringServoMaxSpeed               
* 功能：设置转向电机最大速度                
* 入口参数：
		u16 DevID; 0x0001 0x0002 0x0003 0x0004
		int speed: 对于                 
*                              
* 出口参数： 无       
*******************************************************************/
void setSteeringServoMaxSpeed(u16 DevID,u32 speed)
{
		unsigned char instruction[2][8] =
	{
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}		 
	};
	u32 *p;
	p= (u32*)instruction[0];
	*p = speed;
	CAN_Send_Msg(instruction[0],4,1,(u32)DevID<<16|(u32)0x0131,0);         //设置最大速度
	delay_ms(1);
}	


/******************************************************************** 
* 名称：setSteeringServoSpeed               
* 功能：转向电机速度                
* 入口参数：
		u16 DevID; 0x0001 0x0002 0x0003 0x0004
		int speed: 对于                 
*                              
* 出口参数： 无       
*******************************************************************/
void setSteeringServoSpeed(u16 DevID,s32 speed)
{
	u8 instruction[2][4] =
  {
   {0x00,0x00,0x00,0x10}, 
  };
	int i;
 	int *p;
  int iIndexSpeed = 0;
	if(DevID==0x00)   																				//广播模式
	{
		for(i=0;i<4;i++)
	  instruction[i][1]=0xDA;
	}
	
	 p = (s32*)(instruction[iIndexSpeed]);									
	*p = speed;															
	CAN_Send_Msg(instruction[0],4,1,(u32)DevID<<16|(u32)0x0305,0);         //设置目标速度
	delay_ms(1);

}	



/******************************************************************** 
尝试一下速度模式归零  初始化归零    
*******************************************************************/
int returnToZero(void)
{
  int i1=1,i2=1,i3=1,i4=1;
	while(i1||i2||i3||i4)
	{
		//1号转向 左前
		if(encode1_value>=(zero_encode1_value+GRADIENT_4))    //往右转
		{
			setSteeringServoSpeed(0x0001, -40);   //超位置 
		}
		if((zero_encode1_value+GRADIENT_4)>encode1_value&&encode1_value>=(zero_encode1_value+GRADIENT_3))    //往右转
		{
			setSteeringServoSpeed(0x0001, -30);
		}
		if((zero_encode1_value+GRADIENT_3)>encode1_value&&encode1_value>=(zero_encode1_value+GRADIENT_2))    //往右转
		{
			setSteeringServoSpeed(0x0001, -10);
		}
		if((zero_encode1_value+GRADIENT_2)>encode1_value&&encode1_value>=(zero_encode1_value+GRADIENT_1))    //往右转
		{
			setSteeringServoSpeed(0x0001, -1);
		}
		if((zero_encode1_value+GRADIENT_1)>encode1_value&&encode1_value>=zero_encode1_value)    //往右转
		{
			setSteeringServoSpeed(0x0001, 0);
			LCD_ShowString(420,200,200,16,16,"ZERO1OK");
			i1=0;
		}
		
		
		if(zero_encode1_value>=encode1_value&&encode1_value>=(zero_encode1_value-GRADIENT_1))    //往左转
		{
			setSteeringServoSpeed(0x0001, 0);
			LCD_ShowString(420,200,200,16,16,"ZERO1OK");
			i1=0;
		}
		if((zero_encode1_value-GRADIENT_1)>encode1_value&&encode1_value>=(zero_encode1_value-GRADIENT_2))    //往左转
		{
			setSteeringServoSpeed(0x0001, 1);
		}
		if((zero_encode1_value-GRADIENT_2)>encode1_value&&encode1_value>=(zero_encode1_value-GRADIENT_3))    //往左转
		{
			setSteeringServoSpeed(0x0001, 10);
		}
		if((zero_encode1_value-GRADIENT_3)>encode1_value&&encode1_value>=(zero_encode1_value-GRADIENT_4))    //往左转
		{
			setSteeringServoSpeed(0x0001, 30);
		}
		if((zero_encode1_value-GRADIENT_4)>encode1_value)   			 //往左转
		{
			setSteeringServoSpeed(0x0001, 40);
			
		}
		//2号转向 右前
	
		if(encode2_value>=(zero_encode2_value+GRADIENT_4))    //往右转
		{
			setSteeringServoSpeed(0x0002, -40);
		}
		if((zero_encode2_value+GRADIENT_4)>encode2_value&&encode2_value>=(zero_encode2_value+GRADIENT_3))    //往右转
		{
			setSteeringServoSpeed(0x0002, -30);
		}
		if((zero_encode2_value+GRADIENT_3)>encode2_value&&encode2_value>=(zero_encode2_value+GRADIENT_2))    //往右转
		{
			setSteeringServoSpeed(0x0002, -10);
		}
		if((zero_encode2_value+GRADIENT_2)>encode2_value&&encode2_value>=(zero_encode2_value+GRADIENT_1))    //往右转
		{
			setSteeringServoSpeed(0x0002, -1);
		}
		if((zero_encode2_value+GRADIENT_1)>encode2_value&&encode2_value>=zero_encode2_value)    //往右转
		{
			setSteeringServoSpeed(0x0002, 0);
			LCD_ShowString(420,230,200,16,16,"ZERO2OK");
			i2=0;
		}
		
		
		if(zero_encode2_value>=encode2_value&&encode2_value>=(zero_encode2_value-GRADIENT_1))    //往左转
		{
			setSteeringServoSpeed(0x0002, 0);
			LCD_ShowString(420,230,200,16,16,"ZERO2OK");
			i2=0;
		}
		if((zero_encode2_value-GRADIENT_1)>encode2_value&&encode2_value>=(zero_encode2_value-GRADIENT_2))    //往左转
		{
			setSteeringServoSpeed(0x0002, 1);
		}
		if((zero_encode2_value-GRADIENT_2)>encode2_value&&encode2_value>=(zero_encode2_value-GRADIENT_3))    //往左转
		{
			setSteeringServoSpeed(0x0002, 10);
		}
		if((zero_encode2_value-GRADIENT_3)>encode2_value&&encode2_value>=(zero_encode2_value-GRADIENT_4))    //往左转
		{
			setSteeringServoSpeed(0x0002, 30);
		}
		if((zero_encode2_value-GRADIENT_4)>encode2_value)   			
		{
			setSteeringServoSpeed(0x0002, 40);
			
		}

		//3号转向 左后
	
		if(encode3_value>=(zero_encode3_value+GRADIENT_4))   
		{
			setSteeringServoSpeed(0x0003, 40);
		}
		if((zero_encode3_value+GRADIENT_4)>encode3_value&&encode3_value>=(zero_encode3_value+GRADIENT_3))    
		{
			setSteeringServoSpeed(0x0003, -30);
		}
		if((zero_encode3_value+GRADIENT_3)>encode3_value&&encode3_value>=(zero_encode3_value+GRADIENT_2))    
		{
			setSteeringServoSpeed(0x0003, -10);
		}
		if((zero_encode3_value+GRADIENT_2)>encode3_value&&encode3_value>=(zero_encode3_value+GRADIENT_1))    
		{
			setSteeringServoSpeed(0x0003, -1);
		}
		if((zero_encode3_value+GRADIENT_1)>encode3_value&&encode3_value>=zero_encode3_value)    
		{
			setSteeringServoSpeed(0x0003, 0);
			LCD_ShowString(420,250,200,16,16,"ZERO3OK");
			i3=0;
		}
		
		
		if(zero_encode3_value>=encode3_value&&encode3_value>=(zero_encode3_value-GRADIENT_1))    
		{
			setSteeringServoSpeed(0x0003, 0);
			LCD_ShowString(420,250,200,16,16,"ZERO3OK");
			i3=0;
		}
		if((zero_encode3_value-GRADIENT_1)>encode3_value&&encode3_value>=(zero_encode3_value-GRADIENT_2))    
		{
			setSteeringServoSpeed(0x0003, 1);
		}
		if((zero_encode3_value-GRADIENT_2)>encode3_value&&encode3_value>=(zero_encode3_value-GRADIENT_3))    
		{
			setSteeringServoSpeed(0x0003, 10);
		}
		if((zero_encode3_value-GRADIENT_3)>encode3_value&&encode3_value>=(zero_encode3_value-GRADIENT_2))    
		{
			setSteeringServoSpeed(0x0003, 30);
		}
		if((zero_encode3_value-GRADIENT_4)>encode3_value)   			 
		{
			setSteeringServoSpeed(0x0003, 40);
			
		}
		//4号转向 右后
	
		if(encode4_value>=(zero_encode4_value+GRADIENT_4))    
		{
			setSteeringServoSpeed(0x0004, -40);
		}
		if((zero_encode4_value+GRADIENT_4)>encode4_value&&encode4_value>=(zero_encode4_value+GRADIENT_3))    
		{
			setSteeringServoSpeed(0x0004, -30);
		}
		if((zero_encode4_value+GRADIENT_3)>encode4_value&&encode4_value>=(zero_encode4_value+GRADIENT_2))   
		{
			setSteeringServoSpeed(0x0004, -10);
		}
		if((zero_encode4_value+GRADIENT_2)>encode4_value&&encode4_value>=(zero_encode4_value+GRADIENT_1))    
		{
			setSteeringServoSpeed(0x0004, -1);
		}
		if((zero_encode4_value+GRADIENT_1)>encode4_value&&encode4_value>=zero_encode4_value)    
		{
			setSteeringServoSpeed(0x0004, 0);
			LCD_ShowString(420,280,200,16,16,"ZERO4OK");
			i4=0;
		}
		
		
		if(zero_encode4_value>=encode4_value&&encode4_value>=(zero_encode4_value-GRADIENT_1))    
		{
			setSteeringServoSpeed(0x0004, 0);
			LCD_ShowString(420,280,200,16,16,"ZERO4OK");
			i4=0;
		}
		if((zero_encode4_value-GRADIENT_1)>encode4_value&&encode4_value>=(zero_encode4_value-GRADIENT_2))    
		{
			setSteeringServoSpeed(0x0004, 1);
		}
		if((zero_encode4_value-GRADIENT_2)>encode4_value&&encode4_value>=(zero_encode4_value-GRADIENT_3))    
		{
			setSteeringServoSpeed(0x0004, 10);
		}
		if((zero_encode4_value-GRADIENT_3)>encode4_value&&encode4_value>=(zero_encode4_value-GRADIENT_4))    
		{
			setSteeringServoSpeed(0x0004, 30);
		}
		if((zero_encode4_value-GRADIENT_4)>encode4_value)   			 
		{
			setSteeringServoSpeed(0x0004, 40);
			
		}
		//4号转向 右后END
	}
	BEEP=1;		  
	delay_ms(15);//延时5ms	  
	BEEP=0;
	return 1;  //归零正常
}

void setSteeringRotationAndSpeed(u16 DevID,double rotation,u32 speed)
{
	long Target=0;
	u32 *speed_;
	long *rotation_;
	u8 instruction[2][8] =
	{
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		{0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00}		 
	};
	switch(DevID)		
	{
		case 0x0001:
			if(steering_Max_Speed_1!=speed)  //如果最高速度改变
			{
				//停止加减速过程  重新设置速度
				 CAN_Send_Msg(instruction[1],1,1,(u32)DevID<<16|(u32)0x030E,0);				//对应文档中   属性782	
				//设置最高速度
				steering_Max_Speed_1=speed;
				speed_ = (u32*)instruction[0];
				*speed_ = speed;  
				CAN_Send_Msg(instruction[0],4,1,(u32)DevID<<16|(u32)0x0131,0);         //设置最大速度
				delay_ms(1);				
			}
			break;
		case 0x0002:
			if(steering_Max_Speed_2!=speed)  //如果最高速度改变
			{
				//停止加减速过程  重新设置速度
				 CAN_Send_Msg(instruction[1],1,1,(u32)DevID<<16|(u32)0x030E,0);				//对应文档中   属性782	
				//设置最高速度
				steering_Max_Speed_2=speed;
				speed_ = (u32*)instruction[0];
				*speed_ = speed;  
				CAN_Send_Msg(instruction[0],4,1,(u32)DevID<<16|(u32)0x0131,0);         //设置最大速度
				delay_ms(1);				
			}
			break;
		case 0x0003:
			if(steering_Max_Speed_3!=speed)  //如果最高速度改变
			{
				//停止加减速过程  重新设置速度
				 CAN_Send_Msg(instruction[1],1,1,(u32)DevID<<16|(u32)0x030E,0);							//对应文档中   属性782	
				//设置最高速度
				steering_Max_Speed_3=speed;
				speed_ = (u32*)instruction[0];
				*speed_ = speed; 
				CAN_Send_Msg(instruction[0],4,1,(u32)DevID<<16|(u32)0x0131,0);         //设置最大速度
				delay_ms(1);				
			}
			break;
		case 0x0004:
			if(steering_Max_Speed_4!=speed)  //如果最高速度改变
			{
				//停止加减速过程  重新设置速度
				 CAN_Send_Msg(instruction[1],1,1,(u32)DevID<<16|(u32)0x030E,0);							//对应文档中   属性782	
				//设置最高速度
				steering_Max_Speed_4=speed;
				speed_ = (u32*)instruction[0];
				*speed_ = speed; 
				CAN_Send_Msg(instruction[0],4,1,(u32)DevID<<16|(u32)0x0131,0);         //设置最大速度
				delay_ms(1);				
			}
			break;
		default:
			break;
	}

 
	if(rotation>-90&&rotation<90)								//如果在左90度到右90度之间 
	{
		Target=(long)(rotation*1.667);             //小数点检查！！！
		rotation_ = (long*)instruction[0];
		*rotation_=Target;
		CAN_Send_Msg(instruction[0],8,1,(u32)DevID<<16|(u32)0x0304,0);							//对应文档中   属性772
		delay_ms(1);
	}
	else if(rotation>=90)             									//限位  不让轮子转动超过90度
	{
		rotation=90;																		//设置当前角度为90
		Target=(long)(150);
		rotation_ = (long*)instruction[0];
		*rotation_=Target;
		CAN_Send_Msg(instruction[0],8,1,(u32)DevID<<16|(u32)0x0304,0);
		delay_ms(1);
	}
	else if(rotation<=(-90))								
	{
		rotation=-90;																	//设置当前角度为-90
		Target=(long)(-150);
		rotation_ = (long*)instruction[0];
		*rotation_=Target;
		CAN_Send_Msg(instruction[0],8,1,(u32)DevID<<16|(u32)0x0304,0);
		delay_ms(1);
	}
}











