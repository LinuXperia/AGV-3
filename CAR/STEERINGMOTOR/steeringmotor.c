#include "main.h"


double  sumRotation=0.0;
u8 canbuf_Steering[32];

/******************************************************************** 
* ���ƣ�setSteeringServoMotoCtrlSign                 
* ���ܣ� ����ת���������ź���Դ                
* ��ڲ�����
		u16 DevID; 0x0001 0x0002 0x0003 0x0004
		int i;  0��ͨ���ⲿ�źſ���  1��ͨ����λ��ָ�����                     
*                              
* ���ڲ����� ��       
*******************************************************************/ 
void setSteeringServoMotoCtrlSign( u16 DevID,u8 i)
{
	if(i==1)  //�������λ��ָ�����
	{					
		canbuf_Steering[0]=0x10;																										//�����ĵ���д��Ӧ�÷���0x01  Ŀ��Ӧ�����ĵ�д����  ���뷢��0x10 (��Ҳ����갡)
		canbuf_Steering[1]=0x00;
		canbuf_Steering[2]=0x00;
		canbuf_Steering[3]=0x00;
		CAN_Send_Msg(canbuf_Steering, 4, 1,(u32)(u32)DevID<<16|(u32)(u32)0x0130,0);  //���豸ID������ID�ϲ�Ϊ��չID
		delay_ms(1);																																					 //��Ӧ�ĵ���   ����304

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
* ���ƣ�setSteeringServoMoto              
* ���ܣ�����ת����ģʽ                
* ��ڲ�����
		u16 DevID; 0x0001 0x0002 0x0003 0x0004
		u8 i;   0  ��������

				1  ת�ؿ���  ֻ���ŷ�����������Ч
				2  �ٶ�/ת�ؿ���
				3  λ��/ת�ؿ���
					�ݲ��ṩ
				4  λ��/�ٶ�/ת�ؿ���
					ֻ���ŷ���������Ч                    
*                              
* ���ڲ����� ��       
*******************************************************************/
void setSteeringServoMode(u16 DevID,int i)
{
	if(i==0)
	{
		canbuf_Steering[0] = 0x00;
		CAN_Send_Msg(canbuf_Steering, 1,1, (u32)DevID<<16|(u32)0x0303,0);					//��Ӧ�ĵ���   ����771
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
* ���ƣ�setSteeringServoControlEnable                
* ���ܣ�ת��������ʹ��                
* ��ڲ�����
		u16 DevID; 0x0001 0x0002 0x0003 0x0004
		u8 i;   ��״̬��������λ�������ⲿ�ź��޸ģ�ʧ�ܺ���� IDLE ״̬
						0��ʧ�ܵ������  
						1��ʹ�ܵ������                    
*                              
* ���ڲ����� ��       
*******************************************************************/
void setSteeringServoControlEnable(u16 DevID,u8 i)
{
	
	if(i==1)
	{
		canbuf_Steering[0] = 0x01;
		CAN_Send_Msg(canbuf_Steering, 1, 1,(u32)DevID<<16|(u32)0x0300,0);   //��Ӧ�ĵ���   ����768
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
* ���ƣ�steeringSpeed               
* ���ܣ�ת�ټ���                
* ��ڲ�����
		int cunt                  
*                              
* ���ڲ����� ��       
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
* ���ƣ�steeringRation              
* ���ܣ�ת�ټ���                
* ��ڲ�����
		int cunt                  
*                              
* ���ڲ����� ��       
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
* ���ƣ�setSteeringServoZero             
* ���ܣ�����ת��������λ         
* ��ڲ�����
		u16 DevID; 0x0001 0x0002 0x0003 0x0004                    
*                            
* ���ڲ�����    
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
//	unsigned short abencoder_zero_a=6766;		//1�ž��Ա�����ֵ������ʱ��
//	unsigned short abencoder_zero_b=6093;		//2�ž��Ա�����ֵ������ʱ��
//	unsigned short abencoder_zero_c=6149;		//3�ž��Ա�����ֵ������ʱ��
//	unsigned short abencoder_zero_d=6344;		//4�ž��Ա�����ֵ������ʱ��

//	if(DevID==0x0001)
//	{
//		  EncoderVaule=getAbEncoderVaule((u8)DevID);		//��þ��Ա������ĵ�ǰֵ
//			d=(int)abencoder_zero_a-(int)EncoderVaule;		//��ǰֵ�����ʱ����
//			steering=(long)(d*11/256);										//����Ϊת����ת���ľ���   ���������11/256����Ҫȷ��
//			p = (long*)(instruction[0] + 0);							//��ָ��ĵ�ַ����p
//			*p = steering;																//��������ʡȥlong�͵�unsigned short�͵�ת��
//			CAN_Send_Msg(instruction[0],8,1,0x00010304,0);	//��Ӧ�ĵ���   ����772
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
* ���ƣ�setSteeringServoNowZero           
* ���ܣ�����ת������������ǰλ��Ϊ0          
* ��ڲ�����
		��                 
*                          
* ���ڲ�����    
*******************************************************************/
void setSteeringServoNowZero(void)			
{
			unsigned char instruction[2][8] =
		{
		 {0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00},      
		};
																																				//�㲥 ����ת���������ǰλ��Ϊ0
		CAN_Send_Msg(instruction[0],1,1,0x00FF030A,0);												//��Ӧ�ĵ���   ����778
		delay_ms(1);	
}

/******************************************************************** 
* ���ƣ�setSteeringServoRotation             
* ���ܣ�����ת������ת�Ƕ�           
* ��ڲ�����
		u16 DevID; 0x0001 0x0002 0x0003 0x0004                    
*    int rotation; ��ת�Ƕ�   ��ֵ������ת  ��ֵ������ת                         
* ���ڲ�����    
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
	//sumRotation+=rotation;         											//�ۼӷ��͹����ĽǶ�  
	if(rotation>-90&&rotation<90)								//�������90�ȵ���90��֮�� 
	{
			Target=(long)(rotation*1.667);             //С�����飡����
			p = (long*)instruction[0];
			*p=Target;
			CAN_Send_Msg(instruction[0],8,1,(u32)DevID<<16|(u32)0x0304,0);							//��Ӧ�ĵ���   ����772
			delay_ms(1);
	}
	else if(rotation>=90)             									//��λ  ��������ת������90��
	{
			rotation=90;																		//���õ�ǰ�Ƕ�Ϊ90
			Target=(long)(150);
			p = (long*)instruction[0];
			*p=Target;
			CAN_Send_Msg(instruction[0],8,1,(u32)DevID<<16|(u32)0x0304,0);
			delay_ms(1);
	}
	else if(rotation<=(-90))								
	{
			rotation=-90;																	//���õ�ǰ�Ƕ�Ϊ-90
			Target=(long)(-150);
			p = (long*)instruction[0];
			*p=Target;
			CAN_Send_Msg(instruction[0],8,1,(u32)DevID<<16|(u32)0x0304,0);
			delay_ms(1);
	}
	
}


/******************************************************************** 
* ���ƣ�setSteeringServoMaxSpeed               
* ���ܣ�����ת��������ٶ�                
* ��ڲ�����
		u16 DevID; 0x0001 0x0002 0x0003 0x0004
		int speed: ����                 
*                              
* ���ڲ����� ��       
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
	CAN_Send_Msg(instruction[0],4,1,(u32)DevID<<16|(u32)0x0131,0);         //��������ٶ�
	delay_ms(1);
}	


/******************************************************************** 
* ���ƣ�setSteeringServoSpeed               
* ���ܣ�ת�����ٶ�                
* ��ڲ�����
		u16 DevID; 0x0001 0x0002 0x0003 0x0004
		int speed: ����                 
*                              
* ���ڲ����� ��       
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
	if(DevID==0x00)   																				//�㲥ģʽ
	{
		for(i=0;i<4;i++)
	  instruction[i][1]=0xDA;
	}
	
	 p = (s32*)(instruction[iIndexSpeed]);									
	*p = speed;															
	CAN_Send_Msg(instruction[0],4,1,(u32)DevID<<16|(u32)0x0305,0);         //����Ŀ���ٶ�
	delay_ms(1);

}	



/******************************************************************** 
����һ���ٶ�ģʽ����  ��ʼ������    
*******************************************************************/
int returnToZero(void)
{
  int i1=1,i2=1,i3=1,i4=1;
	while(i1||i2||i3||i4)
	{
		//1��ת�� ��ǰ
		if(encode1_value>=(zero_encode1_value+GRADIENT_4))    //����ת
		{
			setSteeringServoSpeed(0x0001, -40);   //��λ�� 
		}
		if((zero_encode1_value+GRADIENT_4)>encode1_value&&encode1_value>=(zero_encode1_value+GRADIENT_3))    //����ת
		{
			setSteeringServoSpeed(0x0001, -30);
		}
		if((zero_encode1_value+GRADIENT_3)>encode1_value&&encode1_value>=(zero_encode1_value+GRADIENT_2))    //����ת
		{
			setSteeringServoSpeed(0x0001, -10);
		}
		if((zero_encode1_value+GRADIENT_2)>encode1_value&&encode1_value>=(zero_encode1_value+GRADIENT_1))    //����ת
		{
			setSteeringServoSpeed(0x0001, -1);
		}
		if((zero_encode1_value+GRADIENT_1)>encode1_value&&encode1_value>=zero_encode1_value)    //����ת
		{
			setSteeringServoSpeed(0x0001, 0);
			LCD_ShowString(420,200,200,16,16,"ZERO1OK");
			i1=0;
		}
		
		
		if(zero_encode1_value>=encode1_value&&encode1_value>=(zero_encode1_value-GRADIENT_1))    //����ת
		{
			setSteeringServoSpeed(0x0001, 0);
			LCD_ShowString(420,200,200,16,16,"ZERO1OK");
			i1=0;
		}
		if((zero_encode1_value-GRADIENT_1)>encode1_value&&encode1_value>=(zero_encode1_value-GRADIENT_2))    //����ת
		{
			setSteeringServoSpeed(0x0001, 1);
		}
		if((zero_encode1_value-GRADIENT_2)>encode1_value&&encode1_value>=(zero_encode1_value-GRADIENT_3))    //����ת
		{
			setSteeringServoSpeed(0x0001, 10);
		}
		if((zero_encode1_value-GRADIENT_3)>encode1_value&&encode1_value>=(zero_encode1_value-GRADIENT_4))    //����ת
		{
			setSteeringServoSpeed(0x0001, 30);
		}
		if((zero_encode1_value-GRADIENT_4)>encode1_value)   			 //����ת
		{
			setSteeringServoSpeed(0x0001, 40);
			
		}
		//2��ת�� ��ǰ
	
		if(encode2_value>=(zero_encode2_value+GRADIENT_4))    //����ת
		{
			setSteeringServoSpeed(0x0002, -40);
		}
		if((zero_encode2_value+GRADIENT_4)>encode2_value&&encode2_value>=(zero_encode2_value+GRADIENT_3))    //����ת
		{
			setSteeringServoSpeed(0x0002, -30);
		}
		if((zero_encode2_value+GRADIENT_3)>encode2_value&&encode2_value>=(zero_encode2_value+GRADIENT_2))    //����ת
		{
			setSteeringServoSpeed(0x0002, -10);
		}
		if((zero_encode2_value+GRADIENT_2)>encode2_value&&encode2_value>=(zero_encode2_value+GRADIENT_1))    //����ת
		{
			setSteeringServoSpeed(0x0002, -1);
		}
		if((zero_encode2_value+GRADIENT_1)>encode2_value&&encode2_value>=zero_encode2_value)    //����ת
		{
			setSteeringServoSpeed(0x0002, 0);
			LCD_ShowString(420,230,200,16,16,"ZERO2OK");
			i2=0;
		}
		
		
		if(zero_encode2_value>=encode2_value&&encode2_value>=(zero_encode2_value-GRADIENT_1))    //����ת
		{
			setSteeringServoSpeed(0x0002, 0);
			LCD_ShowString(420,230,200,16,16,"ZERO2OK");
			i2=0;
		}
		if((zero_encode2_value-GRADIENT_1)>encode2_value&&encode2_value>=(zero_encode2_value-GRADIENT_2))    //����ת
		{
			setSteeringServoSpeed(0x0002, 1);
		}
		if((zero_encode2_value-GRADIENT_2)>encode2_value&&encode2_value>=(zero_encode2_value-GRADIENT_3))    //����ת
		{
			setSteeringServoSpeed(0x0002, 10);
		}
		if((zero_encode2_value-GRADIENT_3)>encode2_value&&encode2_value>=(zero_encode2_value-GRADIENT_4))    //����ת
		{
			setSteeringServoSpeed(0x0002, 30);
		}
		if((zero_encode2_value-GRADIENT_4)>encode2_value)   			
		{
			setSteeringServoSpeed(0x0002, 40);
			
		}

		//3��ת�� ���
	
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
		//4��ת�� �Һ�
	
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
		//4��ת�� �Һ�END
	}
	BEEP=1;		  
	delay_ms(15);//��ʱ5ms	  
	BEEP=0;
	return 1;  //��������
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
			if(steering_Max_Speed_1!=speed)  //�������ٶȸı�
			{
				//ֹͣ�Ӽ��ٹ���  ���������ٶ�
				 CAN_Send_Msg(instruction[1],1,1,(u32)DevID<<16|(u32)0x030E,0);				//��Ӧ�ĵ���   ����782	
				//��������ٶ�
				steering_Max_Speed_1=speed;
				speed_ = (u32*)instruction[0];
				*speed_ = speed;  
				CAN_Send_Msg(instruction[0],4,1,(u32)DevID<<16|(u32)0x0131,0);         //��������ٶ�
				delay_ms(1);				
			}
			break;
		case 0x0002:
			if(steering_Max_Speed_2!=speed)  //�������ٶȸı�
			{
				//ֹͣ�Ӽ��ٹ���  ���������ٶ�
				 CAN_Send_Msg(instruction[1],1,1,(u32)DevID<<16|(u32)0x030E,0);				//��Ӧ�ĵ���   ����782	
				//��������ٶ�
				steering_Max_Speed_2=speed;
				speed_ = (u32*)instruction[0];
				*speed_ = speed;  
				CAN_Send_Msg(instruction[0],4,1,(u32)DevID<<16|(u32)0x0131,0);         //��������ٶ�
				delay_ms(1);				
			}
			break;
		case 0x0003:
			if(steering_Max_Speed_3!=speed)  //�������ٶȸı�
			{
				//ֹͣ�Ӽ��ٹ���  ���������ٶ�
				 CAN_Send_Msg(instruction[1],1,1,(u32)DevID<<16|(u32)0x030E,0);							//��Ӧ�ĵ���   ����782	
				//��������ٶ�
				steering_Max_Speed_3=speed;
				speed_ = (u32*)instruction[0];
				*speed_ = speed; 
				CAN_Send_Msg(instruction[0],4,1,(u32)DevID<<16|(u32)0x0131,0);         //��������ٶ�
				delay_ms(1);				
			}
			break;
		case 0x0004:
			if(steering_Max_Speed_4!=speed)  //�������ٶȸı�
			{
				//ֹͣ�Ӽ��ٹ���  ���������ٶ�
				 CAN_Send_Msg(instruction[1],1,1,(u32)DevID<<16|(u32)0x030E,0);							//��Ӧ�ĵ���   ����782	
				//��������ٶ�
				steering_Max_Speed_4=speed;
				speed_ = (u32*)instruction[0];
				*speed_ = speed; 
				CAN_Send_Msg(instruction[0],4,1,(u32)DevID<<16|(u32)0x0131,0);         //��������ٶ�
				delay_ms(1);				
			}
			break;
		default:
			break;
	}

 
	if(rotation>-90&&rotation<90)								//�������90�ȵ���90��֮�� 
	{
		Target=(long)(rotation*1.667);             //С�����飡����
		rotation_ = (long*)instruction[0];
		*rotation_=Target;
		CAN_Send_Msg(instruction[0],8,1,(u32)DevID<<16|(u32)0x0304,0);							//��Ӧ�ĵ���   ����772
		delay_ms(1);
	}
	else if(rotation>=90)             									//��λ  ��������ת������90��
	{
		rotation=90;																		//���õ�ǰ�Ƕ�Ϊ90
		Target=(long)(150);
		rotation_ = (long*)instruction[0];
		*rotation_=Target;
		CAN_Send_Msg(instruction[0],8,1,(u32)DevID<<16|(u32)0x0304,0);
		delay_ms(1);
	}
	else if(rotation<=(-90))								
	{
		rotation=-90;																	//���õ�ǰ�Ƕ�Ϊ-90
		Target=(long)(-150);
		rotation_ = (long*)instruction[0];
		*rotation_=Target;
		CAN_Send_Msg(instruction[0],8,1,(u32)DevID<<16|(u32)0x0304,0);
		delay_ms(1);
	}
}











