# AGV



<!-- 2018.7.26   写了驱动器状态读取 轮毂电价 转速 距离 电流  是否异常    具体函数在dealDate.h/.c中
							  转向电机 距离 速度 是否异常
			重新写了归零函数  用宏定义配置归零梯度 
			宏定义了最大转角位置 最小转角位置 
			
2.18.8.1   任务：添加原地自转  添加归零按键    以及在归零途中怎么打断归零任务
				添加转角  
			方法1: 用定时器改变角度		
			方法2: 


8月29   加入脉冲调节轮毂电机速度
        写转向电机的控制速度 位置函数


2018/9/3    添加脉冲方式控制轮毂电机(四个定时器)  timer_hub.c  timer_hub.h
			添加include.h            用来包含所用到的头文件
			添加config.h             用来保存配置设置
			添加extern_variable.h    用来保存全局变量
			添加custom_structure.h   用来保存自定义结构体
			添加variable.h           用来定义用到的全颈淞恐

2018/9/4    添加转向电机速度 位置两个参数控制函数 sterringmotor.h 中
			void setSteeringRotationAndSpeed(u16 DevID,double rotation,u32 speed);			//设置转向电机旋转角度和转向速度
			添加轮毂电机速度  位置两个参数控制函数 hubmotor.h中
 -->

