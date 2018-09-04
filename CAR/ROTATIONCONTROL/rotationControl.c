#include "main.h"



//运动到指定自转角度
int InSituRotation(void)
{
//首先确定现在所在位置   
//确定每个自转 应该所在角度
//梯形规划   规划后 ,每个轮毂电机运转方向   用右侧左右键控制自转方向
//在自转模式下 不允许前后键按下  不允许转向键按下 

  int i1=1,i2=1,i3=1,i4=1;
	while(i1||i2||i3||i4)
	{

		//1号转向 左前
	   if(encode1_value>=(rotation_encode1_value+GRADIENT_4))    //往右转
		{
			setSteeringServoSpeed(0x0001, -40);   //超位置 
		}
		if((rotation_encode1_value+GRADIENT_4)>encode1_value&&encode1_value>=(rotation_encode1_value+GRADIENT_3))    //往右转
		{
			setSteeringServoSpeed(0x0001, -30);
		}
		if((rotation_encode1_value+GRADIENT_3)>encode1_value&&encode1_value>=(rotation_encode1_value+GRADIENT_2))    //往右转
		{
			setSteeringServoSpeed(0x0001, -10);
		}
		if((rotation_encode1_value+GRADIENT_2)>encode1_value&&encode1_value>=(rotation_encode1_value+GRADIENT_1))    //往右转
		{
			setSteeringServoSpeed(0x0001, -1);
		}
		if((rotation_encode1_value+GRADIENT_1)>encode1_value&&encode1_value>=rotation_encode1_value)    //往右转
		{
			setSteeringServoSpeed(0x0001, 0);
			LCD_ShowString(150,200,200,16,16,"TURN_1OK");
			i1=0;
		}
		
		
		if(rotation_encode1_value>=encode1_value&&encode1_value>=(rotation_encode1_value-GRADIENT_1))    //往左转
		{
			setSteeringServoSpeed(0x0001, 0);
			LCD_ShowString(150,200,200,16,16,"TURN_1OK");
			i1=0;
		}
		if((rotation_encode1_value-GRADIENT_1)>encode1_value&&encode1_value>=(rotation_encode1_value-GRADIENT_2))    //往左转
		{
			setSteeringServoSpeed(0x0001, 1);
		}
		if((rotation_encode1_value-GRADIENT_2)>encode1_value&&encode1_value>=(rotation_encode1_value-GRADIENT_3))    //往左转
		{
			setSteeringServoSpeed(0x0001, 10);
		}
		if((rotation_encode1_value-GRADIENT_3)>encode1_value&&encode1_value>=(rotation_encode1_value-GRADIENT_4))    //往左转
		{
			setSteeringServoSpeed(0x0001, 30);
		}
		if((rotation_encode1_value-GRADIENT_4)>encode1_value)   			 //往左转
		{
			setSteeringServoSpeed(0x0001, 40);
			
		}
		
		//2号转向 右前	
		if(encode2_value>=(rotation_encode2_value+GRADIENT_4))    //往右转
		{
			setSteeringServoSpeed(0x0002, -40);
		}
		if((rotation_encode2_value+GRADIENT_4)>encode2_value&&encode2_value>=(rotation_encode2_value+GRADIENT_3))    //往右转
		{
			setSteeringServoSpeed(0x0002, -30);
		}
		if((rotation_encode2_value+GRADIENT_3)>encode2_value&&encode2_value>=(rotation_encode2_value+GRADIENT_2))    //往右转
		{
			setSteeringServoSpeed(0x0002, -10);
		}
		if((rotation_encode2_value+GRADIENT_2)>encode2_value&&encode2_value>=(rotation_encode2_value+GRADIENT_1))    //往右转
		{
			setSteeringServoSpeed(0x0002, -1);
		}
		if((rotation_encode2_value+GRADIENT_1)>encode2_value&&encode2_value>=rotation_encode2_value)    //往右转
		{
			setSteeringServoSpeed(0x0002, 0);
			LCD_ShowString(150,230,200,16,16,"TURN_2OK");
			i2=0;
		}
		
		
		if(rotation_encode2_value>=encode2_value&&encode2_value>=(rotation_encode2_value-GRADIENT_1))    //往左转
		{
			setSteeringServoSpeed(0x0002, 0);
			LCD_ShowString(150,230,200,16,16,"TURN_2OK");
			i2=0;
		}
		if((rotation_encode2_value-GRADIENT_1)>encode2_value&&encode2_value>=(rotation_encode2_value-GRADIENT_2))    //往左转
		{
			setSteeringServoSpeed(0x0002, 1);
		}
		if((rotation_encode2_value-GRADIENT_2)>encode2_value&&encode2_value>=(rotation_encode2_value-GRADIENT_3))    //往左转
		{
			setSteeringServoSpeed(0x0002, 10);
		}
		if((rotation_encode2_value-GRADIENT_3)>encode2_value&&encode2_value>=(rotation_encode2_value-GRADIENT_4))    //往左转
		{
			setSteeringServoSpeed(0x0002, 30);
		}
		if((rotation_encode2_value-GRADIENT_4)>encode2_value)   			
		{
			setSteeringServoSpeed(0x0002, 40);
			
		}
		
		//3号转向 左后
	
		if(encode3_value>=(rotation_encode3_value+GRADIENT_4))   
		{
			setSteeringServoSpeed(0x0003, 40);
		}
		if((rotation_encode3_value+GRADIENT_4)>encode3_value&&encode3_value>=(rotation_encode3_value+GRADIENT_3))    
		{
			setSteeringServoSpeed(0x0003, -30);
		}
		if((rotation_encode3_value+GRADIENT_3)>encode3_value&&encode3_value>=(rotation_encode3_value+GRADIENT_2))    
		{
			setSteeringServoSpeed(0x0003, -10);
		}
		if((rotation_encode3_value+GRADIENT_2)>encode3_value&&encode3_value>=(rotation_encode3_value+GRADIENT_1))    
		{
			setSteeringServoSpeed(0x0003, -1);
		}
		if((rotation_encode3_value+GRADIENT_1)>encode3_value&&encode3_value>=rotation_encode3_value)    
		{
			setSteeringServoSpeed(0x0003, 0);
			LCD_ShowString(150,250,200,16,16,"TURN_3OK");
			i3=0;
		}
		
		
		if(rotation_encode3_value>=encode3_value&&encode3_value>=(rotation_encode3_value-GRADIENT_1))    
		{
			setSteeringServoSpeed(0x0003, 0);
			LCD_ShowString(150,250,200,16,16,"TURN_3OK");
			i3=0;
		}
		if((rotation_encode3_value-GRADIENT_1)>encode3_value&&encode3_value>=(rotation_encode3_value-GRADIENT_2))    
		{
			setSteeringServoSpeed(0x0003, 1);
		}
		if((rotation_encode3_value-GRADIENT_2)>encode3_value&&encode3_value>=(rotation_encode3_value-GRADIENT_3))    
		{
			setSteeringServoSpeed(0x0003, 10);
		}
		if((rotation_encode3_value-GRADIENT_3)>encode3_value&&encode3_value>=(rotation_encode3_value-GRADIENT_2))    
		{
			setSteeringServoSpeed(0x0003, 30);
		}
		if((rotation_encode3_value-GRADIENT_4)>encode3_value)   			 
		{
			setSteeringServoSpeed(0x0003, 40);
			
		}
		//4号转向 右后
	
		if(encode4_value>=(rotation_encode4_value+GRADIENT_4))    
		{
			setSteeringServoSpeed(0x0004, -40);
		}
		if((rotation_encode4_value+GRADIENT_4)>encode4_value&&encode4_value>=(rotation_encode4_value+GRADIENT_3))    
		{
			setSteeringServoSpeed(0x0004, -30);
		}
		if((rotation_encode4_value+GRADIENT_3)>encode4_value&&encode4_value>=(rotation_encode4_value+GRADIENT_2))   
		{
			setSteeringServoSpeed(0x0004, -10);
		}
		if((rotation_encode4_value+GRADIENT_2)>encode4_value&&encode4_value>=(rotation_encode4_value+GRADIENT_1))    
		{
			setSteeringServoSpeed(0x0004, -1);
		}
		if((rotation_encode4_value+GRADIENT_1)>encode4_value&&encode4_value>=rotation_encode4_value)    
		{
			setSteeringServoSpeed(0x0004, 0);
			LCD_ShowString(150,280,200,16,16,"TURN_4OK");
			i4=0;
		}
		
		
		if(rotation_encode4_value>=encode4_value&&encode4_value>=(rotation_encode4_value-GRADIENT_1))    
		{
			setSteeringServoSpeed(0x0004, 0);
			LCD_ShowString(150,280,200,16,16,"TURN_4OK");
			i4=0;
		}
		if((rotation_encode4_value-GRADIENT_1)>encode4_value&&encode4_value>=(rotation_encode4_value-GRADIENT_2))    
		{
			setSteeringServoSpeed(0x0004, 1);
		}
		if((rotation_encode4_value-GRADIENT_2)>encode4_value&&encode4_value>=(rotation_encode4_value-GRADIENT_3))    
		{
			setSteeringServoSpeed(0x0004, 10);
		}
		if((rotation_encode4_value-GRADIENT_3)>encode4_value&&encode4_value>=(rotation_encode4_value-GRADIENT_4))    
		{
			setSteeringServoSpeed(0x0004, 30);
		}
		if((rotation_encode4_value-GRADIENT_4)>encode4_value)   			 
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

