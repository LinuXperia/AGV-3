#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"
 
//四个定时器用来发脉冲
void TIM2_PWM_Init(u16 arr,u16 psc); //0x0005
void TIM3_PWM_Init(u16 arr,u16 psc); //0x0006
void TIM4_PWM_Init(u16 arr,u16 psc); //0x0007
void TIM5_PWM_Init(u16 arr,u16 psc); //0x0008

//用来发控制指令
void TIM1_Int_Init(u16 arr,u16 psc);
void TIM2_Int_Init(u16 arr,u16 psc);
void TIM3_Int_Init(u16 arr,u16 psc);
void TIM5_Int_Init(u16 arr,u16 psc);
void TIM6_Int_Init(u16 arr,u16 psc);
void TIM7_Int_Init(u16 arr,u16 psc);
//void TIM3_Int_Init(u16 arr,u16 psc);
//void TIM2_Int_Init(u16 arr,u16 psc);
#endif

