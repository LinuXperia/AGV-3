 #include "state.h"
 //״̬��ʵ��һ���򵥵ļ�����
 #include <stdio.h>
typedef unsigned char State;
typedef State(*Procedure)(void*);  //�������Է���Ķ���һ������ָ������

enum states{s_init,s_count,s_done,s_default};//ö�ٶ�Ӧ��{0,1,2,3}
typedef struct _SM_VAR//��״̬��������װ
{
	int cnt;
}SM_VAR;

State step_init(void*arg) //��ʼ��
{
	SM_VAR *p=(SM_VAR*)arg;
	p->cnt=0;
	printf("CS:init;cnt=%d;NS:count\n",p->cnt);
	return s_count;
}
State step_count(void*arg) //����
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

State step_done(void *arg)  //�������
{
	SM_VAR *p=(SM_VAR*)arg;
	printf("CS:count;cnt=%d;NS:done\n",p->cnt);
	return s_init;
}

State step_default(void *arg)  //�������
{
	SM_VAR *p=(SM_VAR*)arg;
	printf("WRONG State\n");
	return s_init;
}

Procedure Steps[]={step_init,step_count,step_done,step_default};

void BestStateMachine(void * invar)
{
	static State NS = s_init;    //������һ״̬
	NS=Steps[NS](invar);
}

int main(void)
{
	SM_VAR var;
	int i;
	for(i=0;i<8;i++)    //��״̬��8�����ڵ�ʱ������
	{
		BestStateMachine(&var);
	}
	return 0;
}
