#include "main.h"

void LCDShowInit(void)
{
	POINT_COLOR=BLUE;    					//设置字体为蓝色

	LCD_ShowString(100,150,600,16,16,"Current_State     Speed     Distance     Control_Mode");
	LCD_ShowString(10,180,100,16,16,"Wheel_Hub_1");
	LCD_ShowString(10,210,100,16,16,"Wheel_Hub_2");
	LCD_ShowString(10,240,100,16,16,"Wheel_Hub_3");
	LCD_ShowString(10,270,100,16,16,"Wheel_Hub_4");
	LCD_ShowString(100,300,600,16,16,"Current_State     Speed     Angle       Control_Mode");
	LCD_ShowString(10,330,100,16,16,"Steering_1");
	LCD_ShowString(10,360,100,16,16,"Steering_2");
	LCD_ShowString(10,390,100,16,16,"Steering_3");
	LCD_ShowString(10,420,100,16,16,"Steering_4");
	LCD_ShowString(100,450,600,16,16,"State     Data               State     Data");
	LCD_ShowString(10,480,600,16,16,"Ultrasonic1               Ultrasonic5 ");
	LCD_ShowString(10,510,600,16,16,"Ultrasonic2               Ultrasonic6 ");
	LCD_ShowString(10,540,600,16,16,"Ultrasonic3               Ultrasonic7 ");
	LCD_ShowString(10,570,600,16,16,"Ultrasonic4               Ultrasonic8 ");
	LCD_ShowString(100,600,600,16,16,"Current_State     Data");
	LCD_ShowString(10,630,100,16,16,"Encoder_1");
	LCD_ShowString(10,660,100,16,16,"Encoder_2");
	LCD_ShowString(10,690,100,16,16,"Encoder_3");
	LCD_ShowString(10,720,100,16,16,"Encoder_4");
	POINT_COLOR=BLACK;			       //设置字体颜色为黑色				

}

void hardwareInit(void)
{
	delay_init();	
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);															//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(115200);	 																												//串口初始化为115200
	//LED_Init();	//引脚有冲突	  																														//初始化与LED连接的硬件接口	
	LCD_Init();			   																													//初始化LCD 
	BEEP_Init();																																//BEEP初始化
	CAN_Mode_Init(CAN_SJW_1tq,CAN_BS2_8tq,CAN_BS1_9tq,4,CAN_Mode_Normal);				//CAN初始化普通,波特率500Kbps    
	RS485_Init(115200);																													//初始化RS485
	PS2_Init();																																	//初始化遥控
	LCDShowInit();																															//初始化屏幕显示  
	TIM6_Int_Init(1000,7199);																										//10Khz的计数频率，计数到2000为200ms
	TIM7_Int_Init(80,7199);																										//10Khz的计数频率，计数到500为50ms
	IWDG_Init(4,625);    																												//与分频数为64,重载值为625,溢出时间为1s	
	LCD_ShowString(10,100,100,16,16,"initok");
}



/******************************************************************** 
* 名称steeringServoInit         
* 功能：转向电机初始化   
* 入口参数：i  2为速度模式
							3为位置模式
                            
* 出口参数：  
*******************************************************************/
void steeringServoInit(int i)
{
	// 转向电机控制失能
	setSteeringServoControlEnable(0x0001, 0);
	setSteeringServoControlEnable(0x0002, 0);
	setSteeringServoControlEnable(0x0003, 0);
	setSteeringServoControlEnable(0x0004, 0);
	//设置转向电机控制信号来源为上位机控制
	setSteeringServoMotoCtrlSign(0x0001, 1);
	setSteeringServoMotoCtrlSign(0x0002, 1);
	setSteeringServoMotoCtrlSign(0x0003, 1);
	setSteeringServoMotoCtrlSign(0x0004, 1);
	// 转向电机控制使能
	setSteeringServoControlEnable(0x0001, 1);
	setSteeringServoControlEnable(0x0002, 1);
	setSteeringServoControlEnable(0x0003, 1);
	setSteeringServoControlEnable(0x0004, 1);
	if(i==2)									//设置转向电机模式为速度模式
	{
	setSteeringServoMode(0x0001, 2);
	setSteeringServoMode(0x0002, 2);
	setSteeringServoMode(0x0003, 2);
	setSteeringServoMode(0x0004, 2);	
	}
	else if(i==3)							//设置转向电机模式为位置模式
	{
	setSteeringServoMode(0x0001, 3);
	setSteeringServoMode(0x0002, 3);
	setSteeringServoMode(0x0003, 3);
	setSteeringServoMode(0x0004, 3);		
	}
//设置转向电机最大速度
//	setSteeringServoMaxSpeed(0x0001, 6000);
//	setSteeringServoMaxSpeed(0x0001, 50);
//	setSteeringServoMaxSpeed(0x0001, 50);
//	setSteeringServoMaxSpeed(0x0001, 50);											
}

/******************************************************************** 
* 名称hubMotorInit       
* 功能：轮毂电机初始化  
* 入口参数：int i:  i=1时 初始化为速度模式
									 i=0时 初始化位位置模式
									i=2时 外部脉冲控制方式
                            
* 出口参数：  
*******************************************************************/
void hubMotorInit(int  i)
{
	if(i==1)
	{
		setHubMotorEnable(0x0005,1);           				//打开轮毂电机5	
		setHubMotorEnable(0x0006,1);           				//打开轮毂电机6		
		setHubMotorEnable(0x0007,1);           				//打开轮毂电机7
		setHubMotorEnable(0x0008,1);           				//打开轮毂电机8
		setHubMotorMode(1);   												//设置为速度模式
		setHubMotorPlusSubSpeed(1);                   //设置速度模式加减速时间  默认值				
	}
	else if (i==0)
	{
		setHubMotorEnable(0x0005,1);           				//打开轮毂电机5
		setHubMotorEnable(0x0006,1);           				//打开轮毂电机6																
		setHubMotorEnable(0x0007,1);           				//打开轮毂电机7
		setHubMotorEnable(0x0008,1);           				//打开轮毂电机8
		setHubMotorMode(0);														//设置为位置模式
		setHubMotorPlusSubSpeed(0);                   //设置位置模式加减速时间  默认值
		setHubMotorPositionMaxSpeed(0x00,20);         //设置电机允许运行的最高速度为20PRM  最大设置为1000PRM  //稍后在速度函数中限制不能大于1000
		setHubMotorPositionModeControlWord(0);				//设置位置控制字为相对位置	
	}	
	else if (i==2)
	{
		//开启四个定时器发送脉冲
		TIM2_PWM_Init(1,71);   					//0x0006   1us
		TIM3_PWM_Init(1,71);   					//0x0007
		TIM4_PWM_Init(1,71);   					//0x0008
		TIM5_PWM_Init(1,71);   					//0x0005	
		HUB_PIN_Init();           			//初始化轮毂连接引脚
	}
	
}
