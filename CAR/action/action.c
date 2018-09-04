#include "main.h"

double angle_=0;
double angle1=0,angle2=0,angle3=0,angle4=0;  //角度可以	显示正负
double angle1_rad=0,angle2_rad=0,angle3_rad=0,angle4_rad=0;  //弧度都设置为正值
double x1=0,x2=0;
double R1=0,R2=0,R3=0,R4=0;

//angle大于0  左转
//      小于0  右转

void action(double angle)
{
	if(angle>-60&&angle<60&&angle!=0)
	{
		if(angle>0)  //左转
		{
			angle1_rad=angle*PI/180;
			angle3_rad=angle*PI/180;
			x1=305.0/tan(angle1_rad);
			x2=x1+386.0;
			angle2_rad=atan2(305.0,x2);
			angle4_rad=-angle2_rad;
			R1=305.0/sin(angle1_rad);
			R2=305.0/sin(angle2_rad);
			R3=R1;
			R4=R2;
			angle1=angle;
			angle2=angle2_rad*180/PI;
			angle3=(-angle);
			angle4=(-angle2);
		}
		else if(angle<0)
		{
			angle2_rad=-(angle*PI/180);
			angle3_rad=-(angle*PI/180);
			x2=305.0/tan(angle2_rad);
			x1=x2+386.0;
			angle1_rad=atan2(305.0,x1);
			angle4_rad=angle2_rad;
			R1=305.0/sin(angle1_rad);
			R2=305.0/sin(angle2_rad);
			R2=x1+193.0;
			R3=R1;
			R4=R2;
			angle1=-angle1_rad*180/PI;
			angle2=angle;
			angle3=(-angle1);
			angle4=(-angle);
		}
	}
	else if(angle==0)
	{
		angle1=0;
		angle2=0;
		angle3=0;
		angle4=0;
//		setSteeringServoRotation(0x0001,angle1);
//		setSteeringServoRotation(0x0002,angle2);
//		setSteeringServoRotation(0x0003,angle3);
//		setSteeringServoRotation(0x0004,angle4);
	}
	
			LCD_ShowxNum(250,630,(int)angle1,8,16,0X00);
			LCD_ShowxNum(250,660,(int)angle2,8,16,0X00);
			LCD_ShowxNum(250,690,(int)angle3,8,16,0X00);
			LCD_ShowxNum(250,720,(int)angle4,8,16,0X00);

}

