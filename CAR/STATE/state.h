#include "sys.h"

typedef unsigned char State;
typedef State(*Procedure)(void*);  //这样可以方便的定义一个函数指针数组

Procedure Steps[]={step_init,step_count,step_done,step_default};
//step_init,step_count等是函数名，再定义状态;
enum states{s_init,s_count,s_done,s_default};
//枚举对应着{0,1,2,3}

void BestStateMachine(void* invar)
{
	static State NS = s_init;		//定义下一个状态
	NS = Steps[NS](invar);
}

//static的变量NS在每次BestStateMachine调用会得到维护，我们只需再没Steps返回下一个状态并保存到NS中可以实现状态的保存和切换
//为什么要加个void*的参数，状态机一般有很多自身变量的维护，而且对于mealy状态机还需根据输入判断，因为函数调用返回是不保留局部变量的
//那么久需要将变量传递来实现个更改和保存，之所以只用了一个void*参数是因为，如果需要保存很传递的变量很多，直接传递会在调用函数时浪费大量的栈
//栈空间，且效率低下，采用这种欧式，可以将变量用一个结构体封装，然后将结构体指针传递给void*形参，在函数内部再强制转换即可使用结构体内部变量。


