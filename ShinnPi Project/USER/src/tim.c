#include "tim.h"

/*
�� �� ����TIM2_INIT
�������ܣ�TIM�ĳ�ʼ��
��    ����int x ms
�� �� ֵ��viod
��    ע��
TIM2  PAB1  72MHZ  72 000 000 ��/s   72 000 ��/ms
��װ��ֵ/����Ƶ��
����ʱ�� == ��װ��ֵ/������Ƶ��/Ԥ��Ƶֵ��
��ʱ��Ƶ�� 72MHZ 1ms 72000
*/

void TIM2_INIT(int x)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_TimeBaseInitStruct.TIM_ClockDivision     = TIM_CKD_DIV1;//ϵͳ��Ƶ
	TIM_TimeBaseInitStruct.TIM_CounterMode       = TIM_CKD_DIV1;//ϵͳ��Ƶ
	TIM_TimeBaseInitStruct.TIM_Period            = 10*x-1;//��װ��ֵ
	TIM_TimeBaseInitStruct.TIM_Prescaler         = 7200-1;//Ԥ��Ƶֵ
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
	
	TIM_GenerateEvent(TIM2, TIM_FLAG_Update);//���������¼�
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);//������λ	
	TIM_SetCounter(TIM2, 0);//����������
	TIM_Cmd(TIM2, ENABLE);
	
}

/*
�� �� ����TIM2_delayms
�������ܣ�TIM�ĳ�ʼ��
��    ����int x ms
�� �� ֵ��viod
��    ע��
TIM2  PAB1  72MHZ  72 000 000 ��/s   72 000 ��/ms
��װ��ֵ/����Ƶ��
����ʱ�� == ��װ��ֵ/������Ƶ��/Ԥ��Ƶֵ��
��ʱ��Ƶ�� 72MHZ 1ms 72000
*/

void TIM2_delayms(int x)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_TimeBaseInitStruct.TIM_ClockDivision     = TIM_CKD_DIV1;//ϵͳ��Ƶ
	TIM_TimeBaseInitStruct.TIM_CounterMode       = TIM_CKD_DIV1;//ϵͳ��Ƶ
	TIM_TimeBaseInitStruct.TIM_Period            = 10*x-1;//��װ��ֵ
	TIM_TimeBaseInitStruct.TIM_Prescaler         = 7200-1;//Ԥ��Ƶֵ
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
	
	TIM_GenerateEvent(TIM2, TIM_FLAG_Update);//���������¼�
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);//������λ	
	TIM_SetCounter(TIM2, 0);//����������
	TIM_Cmd(TIM2, ENABLE);
	
	//�ȴ�������ɱ�־λ�仯
	while(TIM_GetFlagStatus(TIM2, TIM_FLAG_Update) == RESET);
	
}

/*
�� �� ����TIM2_delayus
�������ܣ�TIM�ĳ�ʼ��
��    ����int x ms
�� �� ֵ��viod
��    ע��
TIM2  PAB1  72MHZ  72 000 000 ��/s   72 000 ��/ms
��װ��ֵ/����Ƶ��
����ʱ�� == ��װ��ֵ/������Ƶ��/Ԥ��Ƶֵ��
��ʱ��Ƶ�� 72MHZ 1ms 72000
*/

void TIM2_delayus(int x)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_TimeBaseInitStruct.TIM_ClockDivision     = TIM_CKD_DIV1;//ϵͳ��Ƶ
	TIM_TimeBaseInitStruct.TIM_CounterMode       = TIM_CKD_DIV1;//ϵͳ��Ƶ
	TIM_TimeBaseInitStruct.TIM_Period            = 1*x-1;//��װ��ֵ
	TIM_TimeBaseInitStruct.TIM_Prescaler         = 72-1;//Ԥ��Ƶֵ
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
	
	TIM_GenerateEvent(TIM2, TIM_FLAG_Update);//���������¼�
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);//������λ	
	TIM_SetCounter(TIM2, 0);//����������
	TIM_Cmd(TIM2, ENABLE);
	
	//�ȴ�������ɱ�־λ�仯
	while(TIM_GetFlagStatus(TIM2, TIM_FLAG_Update) == RESET);
	
}
