#include "main.h"

extern int Count;
u16 encode1_value,encode2_value,encode3_value,encode4_value;
int left_flag1=0,left_flag2=0,left_flag3=0,left_flag4=0;    //0��ʾ����λ״̬   1��ʾ������λ״̬
int right_flag1=0,right_flag2=0,right_flag3=0,right_flag4=0;    //0��ʾ����λ״̬   1��ʾ������λ״̬
int xianwei(void)
{

		
		/***************************************��λ1**************************************************/
		if(encode1_value<max_encode1_value)  
		{		
			 left_flag1=0;  
		}
		if(encode1_value>min_encode1_value)
		{
			right_flag1=0;
		}
		if((encode1_value>max_encode1_value)&&left_flag1==0) 
		{		
			 setSteeringServoSpeed(0x0001, 0);
			 Count=0;
			 steering_speed=0;
			 left_flag1=1;
		}
		if((encode1_value<min_encode1_value)&&right_flag1==0)
		{
			 setSteeringServoSpeed(0x0001, 0);
			 Count=0;
			 steering_speed=0;
			 right_flag1=1;
		}	
	 /***************************************��λ2**************************************************/
		if(encode2_value<max_encode2_value)  
		{		
			 left_flag2=0;  
		}
		if(encode2_value>min_encode2_value)
		{
			 right_flag2=0;
		}
		if((encode2_value>max_encode2_value)&&left_flag2==0) 
		{		
			 setSteeringServoSpeed(0x0002, 0);
			 Count=0;
			 steering_speed=0;
			 left_flag2=1;
		}
		if((encode2_value<min_encode2_value)&&right_flag2==0)
		{
			 setSteeringServoSpeed(0x0002, 0);
			 Count=0;
			 steering_speed=0;
			 right_flag2=1;
		}
		/***************************************��λ3**************************************************/
		if(encode3_value<max_encode3_value)  
		{		
			 left_flag3=0;  
		}
		if(encode3_value>min_encode3_value)
		{
			right_flag3=0;
		}
		if((encode3_value>max_encode3_value)&&left_flag3==0) 
		{		
			 setSteeringServoSpeed(0x0003, 0);
			 Count=0;
			 steering_speed=0;
			 left_flag3=1;
		}
		if((encode3_value<min_encode3_value)&&right_flag3==0)
		{
			 setSteeringServoSpeed(0x0003, 0);
			 Count=0;
			 steering_speed=0;
			 right_flag3=1;
		}
		/***************************************��λ4**************************************************/
		if(encode4_value<max_encode4_value)  
		{		
			 left_flag4=0;  
		}
		if(encode4_value>min_encode4_value)
		{
			right_flag4=0;
		}
		if((encode4_value>max_encode4_value)&&left_flag4==0) 
		{		
			 setSteeringServoSpeed(0x0004, 0);
			 Count=0;
			 steering_speed=0;
			 left_flag4=1;
		}
		if((encode4_value<min_encode4_value)&&right_flag4==0)
		{
			 setSteeringServoSpeed(0x0004, 0);
			 Count=0;
			 steering_speed=0;
			 right_flag4=1;
		}
		return 0;	
		
}
