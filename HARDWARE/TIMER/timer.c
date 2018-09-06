#include "main.h"


int cnt=0;
float cnt_temp=0;

void TIM2_PWM_Init(u16 arr,u16 psc)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA  | RCC_APB2Periph_AFIO, ENABLE); 
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = arr; 
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);  
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);  
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable); 
	TIM_Cmd(TIM2, ENABLE);  
}


void TIM3_PWM_Init(u16 arr,u16 psc)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB |RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3, ENABLE); 
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = arr; 
	TIM_TimeBaseStructure.TIM_Prescaler =psc;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);  
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_Pulse = 0; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);  
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable); 
	TIM_Cmd(TIM3, ENABLE);
}


void TIM4_PWM_Init(u16 arr,u16 psc)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB| RCC_APB2Periph_AFIO, ENABLE); 

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	TIM_TimeBaseStructure.TIM_Period = arr; 
	TIM_TimeBaseStructure.TIM_Prescaler =psc;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); 

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_Pulse = 0; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);  
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable); 
	TIM_Cmd(TIM4, ENABLE); 
}
void TIM5_PWM_Init(u16 arr,u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA| RCC_APB2Periph_AFIO, ENABLE); 

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	TIM_TimeBaseStructure.TIM_Period = arr; 
	TIM_TimeBaseStructure.TIM_Prescaler =psc;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure); 

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_Pulse = 0; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OC1Init(TIM5, &TIM_OCInitStructure);  
	TIM_OC1PreloadConfig(TIM5, TIM_OCPreload_Enable); 
	TIM_Cmd(TIM5, ENABLE); 
}

void TIM1_Int_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); //ʱ��ʹ��
	
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 
	TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE ); 

	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;  //TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���

	TIM_Cmd(TIM1, ENABLE);  //ʹ��TIMx
}

void TIM1_UP_IRQHandler(void)   
{
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET)  
	{
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update  );  //���TIMx�����жϱ�־ 
		IWDG_Feed();
		getAbEncoderVaule();	                  //��ȡ���Ա�������ֵ
		xianwei();						      						//���ݾ��Ա�������ֵ��λ
//		//--------------���Ա�����ͨ��-----------------------// 
//		if(cnt>500)
//		{ stop();
//			LCD_ShowString(50,30,200,16,16,"Tongxin");
//		}
//		else
//		{
//		cnt++;  //��ֹcnt���
//		}
//		//----------------------------------------------------//
//		if(hub_5_!=zero){	
//			if(hub_5_!=hub_5_temp){ 
//				hub_5_temp=hub_5_;
//				setCyc(0x0005,hub_5_);}}	
//		else if(hub_5_==zero){
//			EMB(0x0005);}
//		
//		if(hub_6_!=zero){	
//			if(hub_6_!=hub_6_temp){ 
//				hub_6_temp=hub_6_;
//				setCyc(0x0006,hub_6_);}}	
//		else if(hub_6_==zero){
//			EMB(0x0006);}
//		
//		if(hub_7_!=zero){	
//			if(hub_7_!=hub_7_temp){ 
//				hub_7_temp=hub_7_;
//				setCyc(0x0007,hub_7_);}}	
//		else if(hub_7_==zero){
//			EMB(0x0007);}
//		
//		if(hub_8_!=zero){	
//			if(hub_8_!=hub_8_temp){ 
//				hub_8_temp=hub_8_;
//				setCyc(0x0008,hub_8_);}}	
//		else if(hub_8_==zero){
//			EMB(0x0008);}
	
	}
}

void TIM2_Int_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //ʱ��ʹ��
	//��ʱ��TIM2��ʼ��
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM3�ж�,��������ж�

	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  //TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  //�����ȼ�2��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���
	
	TIM_Cmd(TIM2, ENABLE);  //ʹ��TIMx					 
}
//��ʱ��2�жϷ������
void TIM2_IRQHandler(void)   //TIM3�ж�
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)  //���TIM2�����жϷ������
	{
			
		IWDG_Feed();			
		cnt++;

		spstate=PS2_RedLight(); 																								  //�жϵ�ǰ��ƻ����̵�
		if(spstate==0&&InSituRotation_Flag==0&&returnToZero_Flag==0) 		          //���ģʽ���Ҳ����ڹ���״̬����������ת�Ƕ�����״̬
		key=PS2_DataKey();

		if(cnt>10)
		{
			stop();
			LCD_ShowString(50,30,200,16,16,"Tongxin");
		}
//		if(workState==Normal_Control)
//		{
//			
//			sendHubControlCMD();
//		}
//		else if(workState==InSituRo_Control)
//		{
//			if(hubmotor_speed==0)
//			{
//				setHubMotorTargetSpeed(0x0005,0);
//				setHubMotorTargetSpeed(0x0006,0);
//				setHubMotorTargetSpeed(0x0007,0);
//				setHubMotorTargetSpeed(0x0008,0);
//			}
//			else
//			{
//				setHubMotorTargetSpeed(0x0005,hubmotor_speed);
//				setHubMotorTargetSpeed(0x0006,hubmotor_speed);
//				setHubMotorTargetSpeed(0x0007,hubmotor_speed);
//				setHubMotorTargetSpeed(0x0008,hubmotor_speed);
//			}	
//		}
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update  );  //���TIMx�����жϱ�־
	}
}

void TIM3_Int_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //ʱ��ʹ��	
	//��ʱ��TIM3��ʼ��
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM3�ж�,��������ж�
	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���
	TIM_Cmd(TIM3, ENABLE);  //ʹ��TIMx					 
}
//��ʱ��3�жϷ������
void TIM3_IRQHandler(void)   //TIM3�ж�
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //���TIM3�����жϷ������
	{
		IWDG_Feed();
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //���TIMx�����жϱ�?	
		getAbEncoderVaule();	
		xianwei();
		
		
	}
}


void TIM6_Int_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE); //ʱ��ʹ��
	//��ʱ��TIM2��ʼ��
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM3�ж�,��������ж�

	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn;  //TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  //�����ȼ�2��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���
	
	TIM_Cmd(TIM6, ENABLE);  //ʹ��TIMx					 
}
//��ʱ��2�жϷ������
void TIM6_IRQHandler(void)   //TIM3�ж�
{

	if (TIM_GetITStatus(TIM6, TIM_IT_Update) != RESET)  //���TIM2�����жϷ������
	{
			
		IWDG_Feed();			
		cnt++;
		spstate=PS2_RedLight(); 																								  //�жϵ�ǰ��ƻ����̵�
		if(spstate==0&&InSituRotation_Flag==0&&returnToZero_Flag==0) 		          //���ģʽ���Ҳ����ڹ���״̬����������ת�Ƕ�����״̬
		key=PS2_DataKey();


		if(cnt>1000)
		{
			stop();
			LCD_ShowString(50,30,200,16,16,"Tongxin");
		}
		if(speed_cnt_5!=0&&speed_cnt_5<=HubMotorPlusSubSpeed)
		{
			if(hub_5_speed==0)
			{
				hub_5_speed_last=0;
				speed_cnt_5=0;
				EMB(0x0005); //ɲ��
			}
			else
			{
				speed_cnt_5++;
				speed_temp_5=hub_5_speed_last_last+speed_cnt_5*Hub_Delta5;
				if(speed_temp_5>0){
					setDir(0x0005,P_);}
				else {
					speed_temp_5=-speed_temp_5;
					setDir(0x0005,N_);}
				cnt_temp = 149568/speed_temp_5;
				hub_5_cnt = (u16)(cnt_temp);
				setCyc(0x0005,hub_5_cnt);			
			}

		}
		else 
		{
			speed_cnt_5=0;
		}
		
		if(speed_cnt_6!=0&&speed_cnt_6<=HubMotorPlusSubSpeed)
		{
			if(hub_6_speed==0)
			{
				hub_6_speed_last=0;
				speed_cnt_6=0;
				EMB(0x0006); //ɲ��
			}
			else
			{
			speed_cnt_6++;
			speed_temp_6=hub_6_speed_last_last+speed_cnt_6*Hub_Delta6;
			if(speed_temp_6>0){
				setDir(0x0006,P_);}
			else {
				speed_temp_6=-speed_temp_6;
				setDir(0x0006,N_);}
			cnt_temp = 149568/speed_temp_6;
			hub_6_cnt = (u16)(cnt_temp);
			setCyc(0x0006,hub_6_cnt);
			}
		}
		else
		{speed_cnt_6=0;}
		
	  if(speed_cnt_7!=0&&speed_cnt_7<=HubMotorPlusSubSpeed)
		{
			if(hub_7_speed==0)
			{
				hub_7_speed_last=0;
				speed_cnt_7=0;
				EMB(0x0007); //ɲ��
			}
			else
			{
			speed_cnt_7++;
			speed_temp_7=hub_7_speed_last_last+speed_cnt_7*Hub_Delta7;
			if(speed_temp_7>0){
				setDir(0x0007,P_);}
			else {
				speed_temp_7=-speed_temp_7;
				setDir(0x0007,N_);}
			cnt_temp = 149568/speed_temp_7;
			hub_7_cnt = (u16)(cnt_temp);
			setCyc(0x0007,hub_7_cnt);
			}
		}
		else
		{speed_cnt_7=0;}
		
		if(speed_cnt_8!=0&&speed_cnt_8<=HubMotorPlusSubSpeed)
		{
			if(hub_8_speed==0)
			{
				hub_8_speed_last=0;
				speed_cnt_8=0;
				EMB(0x0008); //ɲ��
			}
			else
			{
			speed_cnt_8++;
			speed_temp_8=hub_8_speed_last_last+speed_cnt_8*Hub_Delta8;
			if(speed_temp_8>0){
				setDir(0x0008,P_);}
			else {
				speed_temp_8=-speed_temp_8;
				setDir(0x0008,N_);}
			cnt_temp = 149568/speed_temp_8;
			hub_8_cnt = (u16)(cnt_temp);
			setCyc(0x0008,hub_8_cnt);
			}
		}		
		else
		{speed_cnt_8=0;}
	TIM_ClearITPendingBit(TIM6, TIM_IT_Update  ); 
	}
}

void TIM7_Int_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE); //ʱ��ʹ��	

	TIM_TimeBaseStructure.TIM_Period = arr; 
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseInit(TIM7, &TIM_TimeBaseStructure); 
	TIM_ITConfig(TIM7,TIM_IT_Update,ENABLE ); 
	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3; 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure); 
	TIM_Cmd(TIM7, ENABLE);  		 
}

void TIM7_IRQHandler(void) 
{
	if (TIM_GetITStatus(TIM7, TIM_IT_Update) != RESET) 
	{
		IWDG_Feed();
		TIM_ClearITPendingBit(TIM7, TIM_IT_Update  );  	
		getAbEncoderVaule();	
		xianwei();
		
		
	}
}

