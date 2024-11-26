#include "steering.h"
int Window_Flag = 0;

/*
函数名称：	Steering_Engine_INIT
函数功能：	舵机设备初始化
函数参数：	void
函数返回值：	void
备注：	
PA1——TIM5_CH2
舵机的周期是固定的，20ms
*/
void Steering_Engine_INIT(void)
{
	//定义结构体句柄
	GPIO_InitTypeDef gpio_InitStruct;
	TIM_TimeBaseInitTypeDef tim_TimeBaseInitStruct;
	TIM_OCInitTypeDef tim_OCInitStruct;
	
	//使能时钟源
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd (RCC_APB1Periph_TIM5, ENABLE);
	
	//GPIO的初始化，并配置为复用模式
	gpio_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio_InitStruct.GPIO_Pin = GPIO_Pin_1;
	gpio_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &gpio_InitStruct);
	
	//复用为TIM5
	GPIO_PinRemapConfig(GPIO_Remap_TIM5CH4_LSI,ENABLE);
	
	//配置TIM5的时基单元
	tim_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	tim_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	tim_TimeBaseInitStruct.TIM_Period = 200 - 1;
	tim_TimeBaseInitStruct.TIM_Prescaler = 7200 - 1;
	TIM_TimeBaseInit(TIM5, &tim_TimeBaseInitStruct);
	
	//软件产生事件
	TIM_GenerateEvent(TIM5, TIM_EventSource_Update);
	
	//计数器清零
	TIM_SetCounter(TIM5, 0);
	
	//清除事件标志位
	TIM_ClearFlag(TIM5, TIM_FLAG_Update);
	
	//使能定时器
	TIM_Cmd(TIM5, ENABLE);
	
	//TIM输出通道初始化
	tim_OCInitStruct.TIM_OCIdleState = TIM_OCIdleState_Reset;
	tim_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	tim_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
	tim_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	tim_OCInitStruct.TIM_Pulse = 0;
	TIM_OC2Init (TIM5, &tim_OCInitStruct);
	
	//使能定时器输出通道
	TIM_CCxCmd(TIM5, TIM_Channel_1, TIM_CCx_Enable);
	
}



/*
函数名称：	Open_Window
函数功能：	舵机模拟开窗函数
函数参数：	void
函数返回值：	void
备注：	

*/
void Open_Window(void)
{
	TIM_SetCompare2(TIM5,25);
	Window_Flag = 1;
}



/*
函数名称：	Close_Window
函数功能：	舵机模拟关窗函数
函数参数：	void
函数返回值：	void
备注：	

*/
void Close_Window(void)
{
	TIM_SetCompare2(TIM5,5);
	Window_Flag = 0;
}

