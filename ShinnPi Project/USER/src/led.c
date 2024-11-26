#include "led.h"

/*
函数名    ：LED_INIT
函数功能  : 对led初始化
函数返回值：void
函数形参  ：void

  
*/

void LED_INIT(void)
{
	//结构体
	GPIO_InitTypeDef GPIO_InitStruct;	
	//开启时钟总线
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;//输出模式
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_12 | GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;//输出模式
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOF, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;//输出模式
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	LED5_OFF;
	LED6_OFF;
	LED7_OFF;
	LED8_OFF;
	LED9_OFF;
	
}







