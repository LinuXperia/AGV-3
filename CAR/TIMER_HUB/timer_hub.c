#include "main.h"



//P_=0   N_=1
void setDir(u8 ID,int dir)
{
	switch(ID)
	{
		case 0x0005:
			if(dir==0)
			 GPIO_ResetBits(DIR_1_P_PORT,DIR_1_P_PIN); 
			else if(dir==1)
			 GPIO_SetBits(DIR_1_P_PORT,DIR_1_P_PIN); 
			break;
		case 0x0006:
			if(dir==0)
			 GPIO_SetBits(DIR_2_P_PORT,DIR_2_P_PIN); 
			else if(dir==1)
			 GPIO_ResetBits(DIR_2_P_PORT,DIR_2_P_PIN); 
			break;
		case 0x0007:
			if(dir==0)
			 GPIO_ResetBits(DIR_3_P_PORT,DIR_3_P_PIN); 
			else if(dir==1)
			 GPIO_SetBits(DIR_3_P_PORT,DIR_3_P_PIN); 
			break;
		case 0x0008:
			if(dir==0)
			 GPIO_SetBits(DIR_4_P_PORT,DIR_4_P_PIN); 
			else if(dir==1)
			 GPIO_ResetBits(DIR_4_P_PORT,DIR_4_P_PIN); 
			break;
		default:
			break;	
	}	
}

void HUB_PIN_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOF|RCC_APB2Periph_GPIOG| RCC_APB2Periph_AFIO, ENABLE);	 //使能PA,PC,PE,PF端口时钟 和AFIO复用功能模块时钟
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);  //禁用PA15 PB3仿真 用来当做普通IO口
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,ENABLE);			 //禁用PA14仿真 用来当做普通IO口	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	//初始化5号轮毂  
	GPIO_InitStructure.GPIO_Pin = PLU_1_N_PIN; 
	GPIO_Init(PLU_1_N_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = DIR_1_P_PIN; 
	GPIO_Init(DIR_1_P_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = DIR_1_N_PIN; 
	GPIO_Init(DIR_1_N_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = ERC_1_P_PIN; 
	GPIO_Init(ERC_1_P_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = ERC_1_N_PIN; 
	GPIO_Init(ERC_1_N_PORT, &GPIO_InitStructure);
	//----------------------------------------//
	GPIO_ResetBits(PLU_1_N_PORT,PLU_1_N_PIN);
	GPIO_ResetBits(DIR_1_N_PORT,DIR_1_N_PIN);
	GPIO_ResetBits(ERC_1_N_PORT,ERC_1_N_PIN);
	
	//初始化6号轮毂	
	GPIO_InitStructure.GPIO_Pin = PLU_2_N_PIN; 
	GPIO_Init(PLU_2_N_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = DIR_2_P_PIN; 
	GPIO_Init(DIR_2_P_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = DIR_2_N_PIN; 
	GPIO_Init(DIR_2_N_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = ERC_2_P_PIN; 
	GPIO_Init(ERC_2_P_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = ERC_2_N_PIN; 
	GPIO_Init(ERC_2_N_PORT, &GPIO_InitStructure);
	//----------------------------------------//
	GPIO_ResetBits(PLU_2_N_PORT,PLU_2_N_PIN);
	GPIO_ResetBits(DIR_2_N_PORT,DIR_2_N_PIN);
	GPIO_ResetBits(ERC_2_N_PORT,ERC_2_N_PIN);
	
	//初始化7号轮毂     
	GPIO_InitStructure.GPIO_Pin = PLU_3_N_PIN; 
	GPIO_Init(PLU_3_N_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = DIR_3_P_PIN; 
	GPIO_Init(DIR_3_P_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = DIR_3_N_PIN; 
	GPIO_Init(DIR_3_N_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = ERC_3_P_PIN; 
	GPIO_Init(ERC_3_P_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = ERC_3_N_PIN; 
	GPIO_Init(ERC_3_N_PORT, &GPIO_InitStructure);
	//----------------------------------------//
	GPIO_ResetBits(PLU_3_N_PORT,PLU_3_N_PIN);
	GPIO_ResetBits(DIR_3_N_PORT,DIR_3_N_PIN);
	GPIO_ResetBits(ERC_3_N_PORT,ERC_3_N_PIN);	
	
	//初始化8号轮毂
	GPIO_InitStructure.GPIO_Pin = PLU_4_N_PIN; 
	GPIO_Init(PLU_4_N_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = DIR_4_P_PIN; 
	GPIO_Init(DIR_4_P_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = DIR_4_N_PIN; 
	GPIO_Init(DIR_4_N_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = ERC_4_P_PIN; 
	GPIO_Init(ERC_4_P_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = ERC_4_N_PIN; 
	GPIO_Init(ERC_4_N_PORT, &GPIO_InitStructure);
	//----------------------------------------//
	GPIO_ResetBits(PLU_4_N_PORT,PLU_4_N_PIN);
	GPIO_ResetBits(DIR_4_N_PORT,DIR_4_N_PIN);
	GPIO_ResetBits(ERC_4_N_PORT,ERC_4_N_PIN);
	//初始化轮毂方向  朝前走
	setDir(0x0005,P_);
	setDir(0x0006,P_);
	setDir(0x0007,P_);
	setDir(0x0008,P_);	
}

void enableHub(u8 ID)
{
	switch(ID)
	{
		case 0x0005:
			GPIO_ResetBits(ERC_1_P_PORT,ERC_1_P_PIN);
			break;
		case 0x0006:
			GPIO_ResetBits(ERC_2_P_PORT,ERC_2_P_PIN);
			break;
		case 0x0007:
			GPIO_ResetBits(ERC_3_P_PORT,ERC_3_P_PIN);
			break;
		case 0x0008:
			GPIO_ResetBits(ERC_4_P_PORT,ERC_4_P_PIN);
			break;
		default:
			break;	
	}
}
void disableHub(u8 ID)
{
	switch(ID)
	{
		case 0x0005:
			GPIO_SetBits(ERC_1_P_PORT,ERC_1_P_PIN);
			break;
		case 0x0006:
			GPIO_SetBits(ERC_2_P_PORT,ERC_2_P_PIN);
			break;
		case 0x0007:
			GPIO_SetBits(ERC_3_P_PORT,ERC_3_P_PIN);
			break;
		case 0x0008:
			GPIO_SetBits(ERC_4_P_PORT,ERC_4_P_PIN);
			break;
		default:
			break;	
	}
}

void setCyc(u8 ID,u16 cyc)   //设置cyc 20  飞快   先从800开始设置调整
{
	switch(ID)
	{	
		case 0x0005:
			TIM_SetCompare1(TIM5,20);
			TIM_SetAutoreload(TIM5,cyc);
			TIM5->EGR = 1;
			break;		
		case 0x0006:
			TIM_SetCompare2(TIM2,20);
			TIM_SetAutoreload(TIM2,cyc);
		  TIM2->EGR = 1;  //产生更新时间 立即重载数值
			break;
		case 0x0007:
			TIM_SetCompare2(TIM3,20);
		  TIM_SetAutoreload(TIM3,cyc);
		  TIM3->EGR = 1;
			break;
		case 0x0008:
			TIM_SetCompare4(TIM4,20);
			TIM_SetAutoreload(TIM4,cyc);
			TIM4->EGR = 1;
			break;


		default:
			break;	
	}
}


//Emergency brake紧急制动
void EMB(u8 ID)
{
	switch(ID)
	{	
		case 0x0005:
			TIM_SetCompare1(TIM5,0);
			TIM_SetAutoreload(TIM5,0);
			TIM5->EGR = 1;		
			break;
		case 0x0006:
			TIM_SetCompare2(TIM2,0);
			TIM_SetAutoreload(TIM2,0);
			TIM2->EGR = 1;
			break;
		case 0x0007:
			TIM_SetCompare2(TIM3,0);
			TIM_SetAutoreload(TIM3,0);
			TIM3->EGR = 1;
			break;
		case 0x0008:
			TIM_SetCompare4(TIM4,0);
			TIM_SetAutoreload(TIM4,0);
			TIM4->EGR = 1;
			break;


		default:
			break;	
	}
}

