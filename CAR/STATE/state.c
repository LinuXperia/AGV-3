 #include "state.h"
 //状态机实现一个简单的计数器
 #include <stdio.h>
typedef unsigned char State;
typedef State(*Procedure)(void*);  //这样可以方便的定义一个函数指针数组

enum states{s_init,s_count,s_done,s_default};//枚举对应着{0,1,2,3}
typedef struct _SM_VAR//对状态机参数封装
{
	int cnt;
}SM_VAR;

State step_init(void*arg) //初始化
{
	SM_VAR *p=(SM_VAR*)arg;
	p->cnt=0;
	printf("CS:init;cnt=%d;NS:count\n",p->cnt);
	return s_count;
}
State step_count(void*arg) //计数
{
	SM_VAR *p=(SM_VAR*)arg;
	if(p->cnt<3)
	{
		p->cnt+=1;
		printf("CS:count;cnt=%d;NS:count\n",p->cnt);
		return s_count;
	}
	else
	{
		printf("CS:count;cnt=%d;NS:done\n",p->cnt);
		return s_done;
	}
}

State step_done(void *arg)  //计数完成
{
	SM_VAR *p=(SM_VAR*)arg;
	printf("CS:count;cnt=%d;NS:done\n",p->cnt);
	return s_init;
}

State step_default(void *arg)  //计数完成
{
	SM_VAR *p=(SM_VAR*)arg;
	printf("WRONG State\n");
	return s_init;
}

Procedure Steps[]={step_init,step_count,step_done,step_default};

void BestStateMachine(void * invar)
{
	static State NS = s_init;    //定义下一状态
	NS=Steps[NS](invar);
}

int main(void)
{
	SM_VAR var;
	int i;
	for(i=0;i<8;i++)    //给状态机8个周期的时钟驱动
	{
		BestStateMachine(&var);
	}
	return 0;
}
