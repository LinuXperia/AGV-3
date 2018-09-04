#include "main.h"

u8 canbuf_hub[32];

/******************************************************************** 
* 名称  setHubMotorEnable          
* 功能：启动或关闭轮毂电机        单个控制
* 入口参数：
		u16 DevID; 0x0005 0x0006 0x0007 0x0008                    
*   inti; 0 释放 电机   1 启动 电机                     
* 出口参数：    
*******************************************************************/
void setHubMotorEnable(u16 DevID,int i)
{
	
	if(i==0)
	{
		canbuf_hub[0] =0x00;
		canbuf_hub[1] =0xFA;
		canbuf_hub[2] =0x00;
		canbuf_hub[3] =0x10;
		canbuf_hub[4] =0x00;
		canbuf_hub[5] =0x00;
		canbuf_hub[6] =0x00;
		canbuf_hub[7] =0x0F;

		CAN_Send_Msg(canbuf_hub,8,0,DevID,0);  //发送标准帧格式
		delay_ms(1);

	}
	else if (i==1)
	{
		canbuf_hub[0] =0x00;
		canbuf_hub[1] =0xFA;
		canbuf_hub[2] =0x00;
		canbuf_hub[3] =0x10;
		canbuf_hub[4] =0x00;
		canbuf_hub[5] =0x00;
		canbuf_hub[6] =0x00;
		canbuf_hub[7] =0x1F;
		CAN_Send_Msg(canbuf_hub,8,0,DevID,0);  //发送标准帧格式
		delay_ms(1);
	}

}	



/******************************************************************** 
* 名称setHubMotorMode           
* 功能：设置轮毂电机工作模式   广播模式      
* 入口参数：
		                   
*    int i; 1 速度模式  0 位置模式                       
* 出口参数：    
*******************************************************************/
void setHubMotorMode(int i)
{
	u16 DevID=0x0000;         														//设置为广播模式
	if(i==1)																							//设置为速度模式
	{
		canbuf_hub[0] =0x00;
		canbuf_hub[1] =0xDA;																//广播模式为DA，一般模式为FA
		canbuf_hub[2] =0x00;
		canbuf_hub[3] =0x19;																//19即为设置工作模式
		canbuf_hub[4] =0x00;
		canbuf_hub[5] =0x00;
		canbuf_hub[6] =0x00;
		canbuf_hub[7] =0x2F;
		CAN_Send_Msg(canbuf_hub,8,0,DevID,0);  									//发送标准帧格式
		delay_ms(1);
	}
	else if (i==0)																					//设置为位置模式
	{
		canbuf_hub[0] =0x00;
		canbuf_hub[1] =0xDA;
		canbuf_hub[2] =0x00;
		canbuf_hub[3] =0x19;
		canbuf_hub[4] =0x00;
		canbuf_hub[5] =0x00;
		canbuf_hub[6] =0x00;
		canbuf_hub[7] =0x3F;
		CAN_Send_Msg(canbuf_hub,8,0,DevID,0);  //发送标准帧格式
		delay_ms(1);
	}

}


/******************************************************************** 
* 名称setHubMotorPlusSubSpeed          
* 功能：设置轮毂电机加减速时间     广播模式 
* 入口参数： 
						int i; 1 速度模式  0 位置模式  :
                                  
* 出口参数：   
*******************************************************************/

void setHubMotorPlusSubSpeed(int i)         //直接用默认的加减速时间
{

	u16 DevID=0x0000;         														//设置为广播模式
	if(i==1)																							//设置速度模式下加减速时间
	{
		canbuf_hub[0] =0x00;
		canbuf_hub[1] =0xDA;
		canbuf_hub[2] =0x00;
		canbuf_hub[3] =0x13;
		canbuf_hub[4] =0x00;
		canbuf_hub[5] =0x00;
		canbuf_hub[6] =0x0A;
		canbuf_hub[7] =0x0A;
		CAN_Send_Msg(canbuf_hub,8,0,DevID,0);  										//发送标准帧格式
		delay_ms(1);

	}
	else if (i==0)																				//设置位置模式下加减速时间
	{
		canbuf_hub[0] =0x00;
		canbuf_hub[1] =0xDA;
		canbuf_hub[2] =0x00;
		canbuf_hub[3] =0x12;
		canbuf_hub[4] =0x00;
		canbuf_hub[5] =0x00;
		canbuf_hub[6] =0x0A;
		canbuf_hub[7] =0x0A;
		CAN_Send_Msg(canbuf_hub,8,0,DevID,0);  //发送标准帧格式
		delay_ms(1);

	}
}

/******************************************************************** 
* 名称setHubMotorPositionMaxSpeed           
* 功能：设置轮毂电机位置模式下最大速度   
* 入口参数：
		u16 DevID; 0x0005 0x0006 0x0007 0x0008 
		int speed: 设置的最大速度值
                                 
* 出口参数：当前位置    
*******************************************************************/
void setHubMotorPositionMaxSpeed(u16 DevID,int speed)
{
	unsigned char instruction[2][8] =
  {
   {0x00,0xFA,0x00,0x14,0x00,0x00,0x00,0x00}, 
  };
	int i;
 	int *p;
  int iIndexSpeed = 0;
	unsigned char c;
	if(DevID==0x00)   																				//广播模式
	{
		for(i=0;i<4;i++)
	  instruction[i][1]=0xDA;
	}
	
	 p = (int*)(instruction[iIndexSpeed] + 4);									
	*p = (int)(speed*8192/3000);															//速度转换
	c = *(instruction[iIndexSpeed] + 4);											//转换后的四个字节1、2、3、4
																														//发送时要按照4、3、2、1的顺序发送才能正常控制
  *(instruction[iIndexSpeed] + 4) = *(instruction[iIndexSpeed] + 4 + 3);
  *(instruction[iIndexSpeed] + 4 + 3) = c;
  c = *(instruction[iIndexSpeed] + 4 + 1);
  *(instruction[iIndexSpeed] + 4 + 1) = *(instruction[iIndexSpeed] + 4 + 2);
  *(instruction[iIndexSpeed] + 4 + 2) = c;
	CAN_Send_Msg(instruction[0],8,0,DevID,0);
	delay_ms(1);


}


/******************************************************************** 
* 名称setHubMotorPositionModeControlWord           
* 功能：设置轮毂电机位置模式控制字  
* 入口参数：
		int mode： mode=0  相对位置模式
							 mode=1  绝对位置模式
                                 
* 出口参数：当前位置    
*******************************************************************/
void setHubMotorPositionModeControlWord(int mode)
{
	u16 DevID=0x0000;         														//设置为广播模式
	if(mode==1)																						//设置绝对位置模式
	{
		canbuf_hub[0] =0x00;
		canbuf_hub[1] =0xDA;
		canbuf_hub[2] =0x00;
		canbuf_hub[3] =0x17;
		canbuf_hub[4] =0x00;
		canbuf_hub[5] =0x00;
		canbuf_hub[6] =0x00;
		canbuf_hub[7] =0x4F;
		CAN_Send_Msg(canbuf_hub,8,0,DevID,0);  										//发送标准帧格式
		delay_ms(1);
	}
	else if (mode==0)																				//设置相对位置模式
	{
		canbuf_hub[0] =0x00;
		canbuf_hub[1] =0xDA;
		canbuf_hub[2] =0x00;
		canbuf_hub[3] =0x17;
		canbuf_hub[4] =0x00;
		canbuf_hub[5] =0x00;
		canbuf_hub[6] =0x00;
		canbuf_hub[7] =0x5F;
		CAN_Send_Msg(canbuf_hub,8,0,DevID,0);  //发送标准帧格式
		delay_ms(1);
	}
}


/******************************************************************** 
* 名称getHubMotorNowPosition           
* 功能：获得轮毂电电机当前位置   
* 入口参数：
		u16 DevID; 0x0005 0x0006 0x0007 0x0008  
                                 
* 出口参数：当前位置    
*******************************************************************/
void getHubMotorNowPosition(u16 DevID)
{
	

}

/******************************************************************** 
* 名称setHubMotorTargetPosition          
* 功能：设置轮毂电机目标位置   
* 入口参数：
		u16 DevID; 0x0005 0x0006 0x0007 0x0008  
                                 
* 出口参数：  
*******************************************************************/
void setHubMotorTargetPosition(u16 DevID)
{
		
}

/******************************************************************** 
* 名称setHubMotorTargetSpeed          
* 功能：设置轮毂电机目标速度  
* 入口参数：
		u16 DevID; 0x0005 0x0006 0x0007 0x0008                    
*   int speed; 速度值    
			//驱动器内部换算 实际速度=设置值/8192*3000RPM
			//对于轮毂电机最高速度限制为 1000RPM
* 出口参数：    
*******************************************************************/
void setHubMotorTargetSpeed(u16 DevID,int speed)
{
 unsigned char instruction[2][8] =
  {
   {0x00,0xFA,0x00,0x11,0x00,0x00,0x00,0x00}, 
  };
	int i;
 	int *p;
  int iIndexSpeed = 0;
	unsigned char c;
	if(DevID==0x00)   																				//广播模式
	{
		for(i=0;i<4;i++)
	  instruction[i][1]=0xDA;
	}
	 p = (int*)(instruction[iIndexSpeed] + 4);									
	*p = (int)(speed*8192/3000);															//速度转换
	c = *(instruction[iIndexSpeed] + 4);											//转换后的四个字节1、2、3、4
																														//发送时要按照4、3、2、1的顺序发送才能正常控制
  *(instruction[iIndexSpeed] + 4) = *(instruction[iIndexSpeed] + 4 + 3);
  *(instruction[iIndexSpeed] + 4 + 3) = c;
  c = *(instruction[iIndexSpeed] + 4 + 1);
  *(instruction[iIndexSpeed] + 4 + 1) = *(instruction[iIndexSpeed] + 4 + 2);
  *(instruction[iIndexSpeed] + 4 + 2) = c;
	CAN_Send_Msg(instruction[0],8,0,DevID,0);	
	delay_ms(1);
}

/******************************************************************** 
* 名称setHubMotorLength          
* 功能：设置轮毂电机行进距离   
* 入口参数：
		u16 DevID; 0x0005 0x0006 0x0007 0x0008  
		int length: 距离                            
* 出口参数：  
*******************************************************************/
void setHubMotorLength(u16 DevID,int length)
{
	unsigned char instruction[2][8] =
  {
   {0x00,0xFA,0x00,0x16,0x00,0x00,0x00,0x00}, 
  };
	int i;
 	int *p;
  int iIndex = 0;
	unsigned char c;
	if(DevID==0x00)   																									//广播模式
	{
		for(i=0;i<4;i++)
	  instruction[i][1]=0xDA;
	}
	
	 p = (int*)(instruction[iIndex] + 4);									
	*p = (int)(length);																									//发送位置
	c = *(instruction[iIndex] + 4);																			//转换后的四个字节1、2、3、4
																																			//发送时要按照4、3、2、1的顺序发送才能正常控制
  *(instruction[iIndex] + 4) = *(instruction[iIndex] + 4 + 3);
  *(instruction[iIndex] + 4 + 3) = c;
  c = *(instruction[iIndex] + 4 + 1);
  *(instruction[iIndex] + 4 + 1) = *(instruction[iIndex] + 4 + 2);
  *(instruction[iIndex] + 4 + 2) = c;
	CAN_Send_Msg(instruction[0],8,0,DevID,0);		
	delay_ms(1);
}


/******************************************************************** 
* 名称hubMotorSpeed          
* 功能：计算轮毂电机速度   
* 入口参数：
		int hubCounte     //计数值                           
* 出口参数：  
*******************************************************************/
void hubMotorSpeed(int hubCounte)
{
	if(hubCounte>24)
	{
		hubCounte=24;
	}
	else if(hubCounte>16&&hubCounte<=24)
	{
		hubmotor_speed=15;
	}
	else if(hubCounte>8&&hubCounte<=16)
	{
		hubmotor_speed=10;
	}
	else if(hubCounte>0&&hubCounte<=8)
	{
		hubmotor_speed=5;
	}
	else if(hubCounte==0)
	{
		hubmotor_speed=0;
	}
	else if(hubCounte<0&&hubCounte>=(-8))
	{
		hubmotor_speed=(-5);
	}
	else if(hubCounte<(-8)&&hubCounte>=(-16))
	{
		hubmotor_speed=(-10);
	}
	else if(hubCounte<(-16)&&hubCounte>=(-24))
	{
		hubmotor_speed=(-15);
	}
	else if(hubCounte<0&&hubCounte>=(-8))
	{
		hubCounte=(-24);
	}

}

/******************************************************************** 
* 名称hubMotorSpeed          
* 功能：计算轮毂电机速度   
* 入口参数：
		int hubCounte     //计数值                           
* 出口参数：  
*******************************************************************/
void hubMotorPul(int hubCounte)
{
	if(hubCounte>24)
	{
		hubCounte=24;
	}
	else if(hubCounte>16&&hubCounte<=24)
	{
//		setDir(0x0005,P_);
//		setDir(0x0006,P_);
//		setDir(0x0007,P_);
//		setDir(0x0008,P_);
//		setCyc(0x0005,900);
//		setCyc(0x0005,900);
//		setCyc(0x0005,900);
//		setCyc(0x0005,900);
	}
	else if(hubCounte>8&&hubCounte<=16)
	{
//		setDir(0x0005,P_);
//		setDir(0x0006,P_);
//		setDir(0x0007,P_);
//		setDir(0x0008,P_);
//		setCyc(0x0005,1000);
//		setCyc(0x0005,1000);
//		setCyc(0x0005,1000);
//		setCyc(0x0005,1000);
	}
	else if(hubCounte>0&&hubCounte<=8)
	{
		setDir(0x0005,P_);
		setDir(0x0006,P_);
		setDir(0x0007,P_);
		setDir(0x0008,P_);
		setCyc(0x0005,900);
		setCyc(0x0006,900);
		setCyc(0x0007,900);
		setCyc(0x0008,900);
	}
	else if(hubCounte==0)
	{
		setCyc(0x0005,0);
		setCyc(0x0006,0);
		setCyc(0x0007,0);
		setCyc(0x0008,0);
	}
	else if(hubCounte<0&&hubCounte>=(-8))
	{
		setDir(0x0005,N_);
		setDir(0x0006,N_);
		setDir(0x0007,N_);
		setDir(0x0008,N_);
		setCyc(0x0005,900);
		setCyc(0x0006,900);
		setCyc(0x0007,900);
		setCyc(0x0008,900);
	}
	else if(hubCounte<(-8)&&hubCounte>=(-16))
	{
//		setDir(0x0005,N_);
//		setDir(0x0006,N_);
//		setDir(0x0007,N_);
//		setDir(0x0008,N_);
//		setCyc(0x0005,1000);
//		setCyc(0x0005,1000);
//		setCyc(0x0005,1000);
//		setCyc(0x0005,1000);
	}
	else if(hubCounte<(-16)&&hubCounte>=(-24))
	{
//		setDir(0x0005,N_);
//		setDir(0x0006,N_);
//		setDir(0x0007,N_);
//		setDir(0x0008,N_);
//		setCyc(0x0005,900);
//		setCyc(0x0005,900);
//		setCyc(0x0005,900);
//		setCyc(0x0005,900);
	}
	else if(hubCounte<0&&hubCounte>=(-8))
	{
		hubCounte=(-24);
	}

}

//设置轮毂电机行进长度和行进速度
void setHubMotorLengthAndSpeed(u16 DevID,s32 length,s32 speed)
{



}
