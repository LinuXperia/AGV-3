#include "main.h"

void LCDShowInit(void)
{
	POINT_COLOR=BLUE;    					//��������Ϊ��ɫ

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
	POINT_COLOR=BLACK;			       //����������ɫΪ��ɫ				

}

void hardwareInit(void)
{
	delay_init();	
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);															//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 																												//���ڳ�ʼ��Ϊ115200
	//LED_Init();	//�����г�ͻ	  																														//��ʼ����LED���ӵ�Ӳ���ӿ�	
	LCD_Init();			   																													//��ʼ��LCD 
	BEEP_Init();																																//BEEP��ʼ��
	CAN_Mode_Init(CAN_SJW_1tq,CAN_BS2_8tq,CAN_BS1_9tq,4,CAN_Mode_Normal);				//CAN��ʼ����ͨ,������500Kbps    
	RS485_Init(115200);																													//��ʼ��RS485
	PS2_Init();																																	//��ʼ��ң��
	LCDShowInit();																															//��ʼ����Ļ��ʾ  
	TIM6_Int_Init(1000,7199);																										//10Khz�ļ���Ƶ�ʣ�������2000Ϊ200ms
	TIM7_Int_Init(80,7199);																										//10Khz�ļ���Ƶ�ʣ�������500Ϊ50ms
	IWDG_Init(4,625);    																												//���Ƶ��Ϊ64,����ֵΪ625,���ʱ��Ϊ1s	
	LCD_ShowString(10,100,100,16,16,"initok");
}



/******************************************************************** 
* ���ƣssteeringServoInit         
* ���ܣ�ת������ʼ��   
* ��ڲ�����i  2Ϊ�ٶ�ģʽ
							3Ϊλ��ģʽ
                            
* ���ڲ�����  
*******************************************************************/
void steeringServoInit(int i)
{
	// ת��������ʧ��
	setSteeringServoControlEnable(0x0001, 0);
	setSteeringServoControlEnable(0x0002, 0);
	setSteeringServoControlEnable(0x0003, 0);
	setSteeringServoControlEnable(0x0004, 0);
	//����ת���������ź���ԴΪ��λ������
	setSteeringServoMotoCtrlSign(0x0001, 1);
	setSteeringServoMotoCtrlSign(0x0002, 1);
	setSteeringServoMotoCtrlSign(0x0003, 1);
	setSteeringServoMotoCtrlSign(0x0004, 1);
	// ת��������ʹ��
	setSteeringServoControlEnable(0x0001, 1);
	setSteeringServoControlEnable(0x0002, 1);
	setSteeringServoControlEnable(0x0003, 1);
	setSteeringServoControlEnable(0x0004, 1);
	if(i==2)									//����ת����ģʽΪ�ٶ�ģʽ
	{
	setSteeringServoMode(0x0001, 2);
	setSteeringServoMode(0x0002, 2);
	setSteeringServoMode(0x0003, 2);
	setSteeringServoMode(0x0004, 2);	
	}
	else if(i==3)							//����ת����ģʽΪλ��ģʽ
	{
	setSteeringServoMode(0x0001, 3);
	setSteeringServoMode(0x0002, 3);
	setSteeringServoMode(0x0003, 3);
	setSteeringServoMode(0x0004, 3);		
	}
//����ת��������ٶ�
//	setSteeringServoMaxSpeed(0x0001, 6000);
//	setSteeringServoMaxSpeed(0x0001, 50);
//	setSteeringServoMaxSpeed(0x0001, 50);
//	setSteeringServoMaxSpeed(0x0001, 50);											
}

/******************************************************************** 
* ���ƣshubMotorInit       
* ���ܣ���챵����ʼ��  
* ��ڲ�����int i:  i=1ʱ ��ʼ��Ϊ�ٶ�ģʽ
									 i=0ʱ ��ʼ��λλ��ģʽ
									i=2ʱ �ⲿ������Ʒ�ʽ
                            
* ���ڲ�����  
*******************************************************************/
void hubMotorInit(int  i)
{
	if(i==1)
	{
		setHubMotorEnable(0x0005,1);           				//����챵��5	
		setHubMotorEnable(0x0006,1);           				//����챵��6		
		setHubMotorEnable(0x0007,1);           				//����챵��7
		setHubMotorEnable(0x0008,1);           				//����챵��8
		setHubMotorMode(1);   												//����Ϊ�ٶ�ģʽ
		setHubMotorPlusSubSpeed(1);                   //�����ٶ�ģʽ�Ӽ���ʱ��  Ĭ��ֵ				
	}
	else if (i==0)
	{
		setHubMotorEnable(0x0005,1);           				//����챵��5
		setHubMotorEnable(0x0006,1);           				//����챵��6																
		setHubMotorEnable(0x0007,1);           				//����챵��7
		setHubMotorEnable(0x0008,1);           				//����챵��8
		setHubMotorMode(0);														//����Ϊλ��ģʽ
		setHubMotorPlusSubSpeed(0);                   //����λ��ģʽ�Ӽ���ʱ��  Ĭ��ֵ
		setHubMotorPositionMaxSpeed(0x00,20);         //���õ���������е�����ٶ�Ϊ20PRM  �������Ϊ1000PRM  //�Ժ����ٶȺ��������Ʋ��ܴ���1000
		setHubMotorPositionModeControlWord(0);				//����λ�ÿ�����Ϊ���λ��	
	}	
	else if (i==2)
	{
		//�����ĸ���ʱ����������
		TIM2_PWM_Init(1,71);   					//0x0006   1us
		TIM3_PWM_Init(1,71);   					//0x0007
		TIM4_PWM_Init(1,71);   					//0x0008
		TIM5_PWM_Init(1,71);   					//0x0005	
		HUB_PIN_Init();           			//��ʼ�������������
	}
	
}
