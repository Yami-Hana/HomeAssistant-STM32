#include "tim.h"

/*
函 数 名：TIM2_INIT
函数功能：TIM的初始化
参    数：int x ms
返 回 值：viod
备    注：
TIM2  PAB1  72MHZ  72 000 000 次/s   72 000 次/ms
重装在值/计数频率
计数时间 == 重装载值/（计数频率/预分频值）
定时器频率 72MHZ 1ms 72000
*/

void TIM2_INIT(int x)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_TimeBaseInitStruct.TIM_ClockDivision     = TIM_CKD_DIV1;//系统分频
	TIM_TimeBaseInitStruct.TIM_CounterMode       = TIM_CKD_DIV1;//系统分频
	TIM_TimeBaseInitStruct.TIM_Period            = 10*x-1;//重装载值
	TIM_TimeBaseInitStruct.TIM_Prescaler         = 7200-1;//预分频值
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
	
	TIM_GenerateEvent(TIM2, TIM_FLAG_Update);//产生更新事件
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);//清除标记位	
	TIM_SetCounter(TIM2, 0);//计数器清零
	TIM_Cmd(TIM2, ENABLE);
	
}

/*
函 数 名：TIM2_delayms
函数功能：TIM的初始化
参    数：int x ms
返 回 值：viod
备    注：
TIM2  PAB1  72MHZ  72 000 000 次/s   72 000 次/ms
重装在值/计数频率
计数时间 == 重装载值/（计数频率/预分频值）
定时器频率 72MHZ 1ms 72000
*/

void TIM2_delayms(int x)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_TimeBaseInitStruct.TIM_ClockDivision     = TIM_CKD_DIV1;//系统分频
	TIM_TimeBaseInitStruct.TIM_CounterMode       = TIM_CKD_DIV1;//系统分频
	TIM_TimeBaseInitStruct.TIM_Period            = 10*x-1;//重装载值
	TIM_TimeBaseInitStruct.TIM_Prescaler         = 7200-1;//预分频值
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
	
	TIM_GenerateEvent(TIM2, TIM_FLAG_Update);//产生更新事件
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);//清除标记位	
	TIM_SetCounter(TIM2, 0);//计数器清零
	TIM_Cmd(TIM2, ENABLE);
	
	//等待计数完成标志位变化
	while(TIM_GetFlagStatus(TIM2, TIM_FLAG_Update) == RESET);
	
}

/*
函 数 名：TIM2_delayus
函数功能：TIM的初始化
参    数：int x ms
返 回 值：viod
备    注：
TIM2  PAB1  72MHZ  72 000 000 次/s   72 000 次/ms
重装在值/计数频率
计数时间 == 重装载值/（计数频率/预分频值）
定时器频率 72MHZ 1ms 72000
*/

void TIM2_delayus(int x)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_TimeBaseInitStruct.TIM_ClockDivision     = TIM_CKD_DIV1;//系统分频
	TIM_TimeBaseInitStruct.TIM_CounterMode       = TIM_CKD_DIV1;//系统分频
	TIM_TimeBaseInitStruct.TIM_Period            = 1*x-1;//重装载值
	TIM_TimeBaseInitStruct.TIM_Prescaler         = 72-1;//预分频值
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
	
	TIM_GenerateEvent(TIM2, TIM_FLAG_Update);//产生更新事件
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);//清除标记位	
	TIM_SetCounter(TIM2, 0);//计数器清零
	TIM_Cmd(TIM2, ENABLE);
	
	//等待计数完成标志位变化
	while(TIM_GetFlagStatus(TIM2, TIM_FLAG_Update) == RESET);
	
}
