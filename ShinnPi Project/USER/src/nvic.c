#include "nvic.h"

/*
函数名：  TIM3_INIT 
函数功能：tim的时基单元配置
函数形参：int x ms
函数返回值：void
备注：
    TIM10 --- APB2  84MHZ
*/
void TIM3_INIT(int x)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	TIM_TimeBaseInitStruct.TIM_ClockDivision     = TIM_CKD_DIV1;//系统分频
	TIM_TimeBaseInitStruct.TIM_CounterMode       = TIM_CKD_DIV1;//系统分频
	TIM_TimeBaseInitStruct.TIM_Period            = 10*x-1;//重装载值
	TIM_TimeBaseInitStruct.TIM_Prescaler         = 7200-1;//预分频值
	
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruct);
	
	TIM_GenerateEvent(TIM3, TIM_FLAG_Update);//产生更新事件
	TIM_ClearFlag(TIM3, TIM_FLAG_Update);//清除标记位	
	TIM_SetCounter(TIM3, 0);//计数器清零
	TIM_Cmd(TIM3, ENABLE);


}	

/*******************************************************************/
/*
函数名： TIM3_ITSource
函数功能：TIM3中断源配置
函数形参：u8 pre ,u8 sub
函数返回值：void
备注：

*/
void TIM3_ITSource(void)
{
	NVIC_InitTypeDef TIM3nvic_InitStruct;
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//优先级分组
	
	TIM3nvic_InitStruct.NVIC_IRQChannel = TIM3_IRQn;
	TIM3nvic_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	TIM3nvic_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	TIM3nvic_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&TIM3nvic_InitStruct);
}

/*
函数名： TIM3_IRQHandler
函数功能：TIM3中断服务函数
函数形参：u8 pre ,u8 sub
函数返回值：void
备注：

*/
void TIM3_IRQHandler(void)
{
	if(SET == TIM_GetITStatus(TIM3, TIM_IT_Update))
	{	

		USART3_SendString(SD.message);	
		
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);		
	}
	
}
