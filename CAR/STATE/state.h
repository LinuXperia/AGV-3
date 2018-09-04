#include "sys.h"

typedef unsigned char State;
typedef State(*Procedure)(void*);  //�������Է���Ķ���һ������ָ������

Procedure Steps[]={step_init,step_count,step_done,step_default};
//step_init,step_count���Ǻ��������ٶ���״̬;
enum states{s_init,s_count,s_done,s_default};
//ö�ٶ�Ӧ��{0,1,2,3}

void BestStateMachine(void* invar)
{
	static State NS = s_init;		//������һ��״̬
	NS = Steps[NS](invar);
}

//static�ı���NS��ÿ��BestStateMachine���û�õ�ά��������ֻ����ûSteps������һ��״̬�����浽NS�п���ʵ��״̬�ı�����л�
//ΪʲôҪ�Ӹ�void*�Ĳ�����״̬��һ���кܶ����������ά�������Ҷ���mealy״̬��������������жϣ���Ϊ�������÷����ǲ������ֲ�������
//��ô����Ҫ������������ʵ�ָ����ĺͱ��棬֮����ֻ����һ��void*��������Ϊ�������Ҫ����ܴ��ݵı����ֱܶ࣬�Ӵ��ݻ��ڵ��ú���ʱ�˷Ѵ�����ջ
//ջ�ռ䣬��Ч�ʵ��£���������ŷʽ�����Խ�������һ���ṹ���װ��Ȼ�󽫽ṹ��ָ�봫�ݸ�void*�βΣ��ں����ڲ���ǿ��ת������ʹ�ýṹ���ڲ�������


