#include "steering.h"
int Window_Flag = 0;

/*
�������ƣ�	Steering_Engine_INIT
�������ܣ�	����豸��ʼ��
����������	void
��������ֵ��	void
��ע��	
PA1����TIM5_CH2
����������ǹ̶��ģ�20ms
*/
void Steering_Engine_INIT(void)
{
	//����ṹ����
	GPIO_InitTypeDef gpio_InitStruct;
	TIM_TimeBaseInitTypeDef tim_TimeBaseInitStruct;
	TIM_OCInitTypeDef tim_OCInitStruct;
	
	//ʹ��ʱ��Դ
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd (RCC_APB1Periph_TIM5, ENABLE);
	
	//GPIO�ĳ�ʼ����������Ϊ����ģʽ
	gpio_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio_InitStruct.GPIO_Pin = GPIO_Pin_1;
	gpio_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &gpio_InitStruct);
	
	//����ΪTIM5
	GPIO_PinRemapConfig(GPIO_Remap_TIM5CH4_LSI,ENABLE);
	
	//����TIM5��ʱ����Ԫ
	tim_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	tim_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	tim_TimeBaseInitStruct.TIM_Period = 200 - 1;
	tim_TimeBaseInitStruct.TIM_Prescaler = 7200 - 1;
	TIM_TimeBaseInit(TIM5, &tim_TimeBaseInitStruct);
	
	//��������¼�
	TIM_GenerateEvent(TIM5, TIM_EventSource_Update);
	
	//����������
	TIM_SetCounter(TIM5, 0);
	
	//����¼���־λ
	TIM_ClearFlag(TIM5, TIM_FLAG_Update);
	
	//ʹ�ܶ�ʱ��
	TIM_Cmd(TIM5, ENABLE);
	
	//TIM���ͨ����ʼ��
	tim_OCInitStruct.TIM_OCIdleState = TIM_OCIdleState_Reset;
	tim_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	tim_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
	tim_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	tim_OCInitStruct.TIM_Pulse = 0;
	TIM_OC2Init (TIM5, &tim_OCInitStruct);
	
	//ʹ�ܶ�ʱ�����ͨ��
	TIM_CCxCmd(TIM5, TIM_Channel_1, TIM_CCx_Enable);
	
}



/*
�������ƣ�	Open_Window
�������ܣ�	���ģ�⿪������
����������	void
��������ֵ��	void
��ע��	

*/
void Open_Window(void)
{
	TIM_SetCompare2(TIM5,25);
	Window_Flag = 1;
}



/*
�������ƣ�	Close_Window
�������ܣ�	���ģ��ش�����
����������	void
��������ֵ��	void
��ע��	

*/
void Close_Window(void)
{
	TIM_SetCompare2(TIM5,5);
	Window_Flag = 0;
}

