#include "nvic.h"

/*
��������  TIM3_INIT 
�������ܣ�tim��ʱ����Ԫ����
�����βΣ�int x ms
��������ֵ��void
��ע��
    TIM10 --- APB2  84MHZ
*/
void TIM3_INIT(int x)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	TIM_TimeBaseInitStruct.TIM_ClockDivision     = TIM_CKD_DIV1;//ϵͳ��Ƶ
	TIM_TimeBaseInitStruct.TIM_CounterMode       = TIM_CKD_DIV1;//ϵͳ��Ƶ
	TIM_TimeBaseInitStruct.TIM_Period            = 10*x-1;//��װ��ֵ
	TIM_TimeBaseInitStruct.TIM_Prescaler         = 7200-1;//Ԥ��Ƶֵ
	
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruct);
	
	TIM_GenerateEvent(TIM3, TIM_FLAG_Update);//���������¼�
	TIM_ClearFlag(TIM3, TIM_FLAG_Update);//������λ	
	TIM_SetCounter(TIM3, 0);//����������
	TIM_Cmd(TIM3, ENABLE);


}	

/*******************************************************************/
/*
�������� TIM3_ITSource
�������ܣ�TIM3�ж�Դ����
�����βΣ�u8 pre ,u8 sub
��������ֵ��void
��ע��

*/
void TIM3_ITSource(void)
{
	NVIC_InitTypeDef TIM3nvic_InitStruct;
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//���ȼ�����
	
	TIM3nvic_InitStruct.NVIC_IRQChannel = TIM3_IRQn;
	TIM3nvic_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	TIM3nvic_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	TIM3nvic_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&TIM3nvic_InitStruct);
}

/*
�������� TIM3_IRQHandler
�������ܣ�TIM3�жϷ�����
�����βΣ�u8 pre ,u8 sub
��������ֵ��void
��ע��

*/
void TIM3_IRQHandler(void)
{
	if(SET == TIM_GetITStatus(TIM3, TIM_IT_Update))
	{	

		USART3_SendString(SD.message);	
		
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);		
	}
	
}
