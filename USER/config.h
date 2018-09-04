#ifndef __CONFIG_H_
#define __CONFIG_H_


//小车尺寸  610mm*386mm
#define			P_ 0   //正向
#define			N_ 1   //反向
#define			PI 3.1415926
//屏幕显示状态及数据
#define			LCDSHOWN							1   //LCD显示为1   不显示为0

/*********************************宏定义**************************************************/
//修改限位值
#define			max_encode1_value				9397
#define			max_encode2_value				9632
#define			max_encode3_value				9558
#define			max_encode4_value				9248
#define			min_encode1_value				2997
#define			min_encode2_value				3232
#define			min_encode3_value				4900
#define			min_encode4_value				2824
//零位值
#define			zero_encode1_value			6165    //最新修改  /2018/9/3 
#define			zero_encode2_value			6326
#define			zero_encode3_value			6340
#define			zero_encode4_value			6110

//自转角度
#define			rotation_encode1_value	4147       //6197-2050
#define			rotation_encode2_value	8482			//6432+2050
#define			rotation_encode3_value	8408
#define			rotation_encode4_value	3998

//归零梯度
#define			GRADIENT_1							10
#define			GRADIENT_2							300
#define			GRADIENT_3							2300
#define			GRADIENT_4							3300


//设置连接轮毂电机引脚
#define			PLU_1_P_PORT						GPIOA            //   Positive 
#define			PLU_1_P_PIN							GPIO_Pin_0
#define			PLU_1_N_PORT						GPIOC           //  Negative
#define			PLU_1_N_PIN							GPIO_Pin_3 
#define			DIR_1_P_PORT						GPIOC
#define			DIR_1_P_PIN							GPIO_Pin_1
#define			DIR_1_N_PORT						GPIOA
#define			DIR_1_N_PIN							GPIO_Pin_5
#define			ERC_1_P_PORT						GPIOF
#define			ERC_1_P_PIN							GPIO_Pin_8
#define			ERC_1_N_PORT						GPIOF
#define			ERC_1_N_PIN							GPIO_Pin_6
//-------------------------------//
#define			PLU_2_P_PORT						GPIOA
#define			PLU_2_P_PIN							GPIO_Pin_1
#define			PLU_2_N_PORT						GPIOC
#define			PLU_2_N_PIN							GPIO_Pin_2
#define			DIR_2_P_PORT						GPIOC
#define			DIR_2_P_PIN							GPIO_Pin_0
#define			DIR_2_N_PORT						GPIOF
#define			DIR_2_N_PIN							GPIO_Pin_9
#define			ERC_2_P_PORT						GPIOF
#define			ERC_2_P_PIN							GPIO_Pin_7
#define			ERC_2_N_PORT						GPIOF
#define			ERC_2_N_PIN							GPIO_Pin_5
//------------------------------//
#define			PLU_3_P_PORT						GPIOC
#define			PLU_3_P_PIN							GPIO_Pin_7
#define			PLU_3_N_PORT						GPIOC
#define			PLU_3_N_PIN							GPIO_Pin_9
#define			DIR_3_P_PORT						GPIOA
#define			DIR_3_P_PIN							GPIO_Pin_13
#define			DIR_3_N_PORT						GPIOA
#define			DIR_3_N_PIN							GPIO_Pin_15
#define			ERC_3_P_PORT						GPIOC
#define			ERC_3_P_PIN							GPIO_Pin_11
#define			ERC_3_N_PORT						GPIOD
#define			ERC_3_N_PIN							GPIO_Pin_2
//-------------------------------//
#define			PLU_4_P_PORT						GPIOB
#define			PLU_4_P_PIN							GPIO_Pin_9
#define			PLU_4_N_PORT						GPIOB
#define			PLU_4_N_PIN							GPIO_Pin_7
#define			DIR_4_P_PORT						GPIOB
#define			DIR_4_P_PIN							GPIO_Pin_5
#define			DIR_4_N_PORT						GPIOB
#define			DIR_4_N_PIN							GPIO_Pin_3
#define			ERC_4_P_PORT						GPIOG
#define			ERC_4_P_PIN							GPIO_Pin_14
#define			ERC_4_N_PORT						GPIOG
#define			ERC_4_N_PIN							GPIO_Pin_15

#endif

