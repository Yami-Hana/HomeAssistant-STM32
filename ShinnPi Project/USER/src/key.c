#include "key.h"

/*
函数名    ：KEY_INIT
函数功能  : 对key初始化
函数返回值：void
函数形参  ：void
备注      ：RGB由三个LED小灯构成
						LED1 --- PB5 --- RCC_APB2Periph_GPIOB
						LED2 --- PB0 --- RCC_APB2Periph_GPIOB
						LED3 --- PB1 --- RCC_APB2Periph_GPIOB
  
*/

void KEY_INIT(void)
{
	//结构体
	GPIO_InitTypeDef GPIO_InitStruct;	
	//开启时钟总线
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN_FLOATING;//输入模式
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN_FLOATING;//输入模式
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	
}

//按键扫描
KEY_ZT KEY_SCAN(void)
{
	if(KEY1_PRESS)
	{
		TIM2_delayms(10);
		if(KEY1_PRESS)
		{
			while(KEY1_PRESS);
			return KEY1;
		}
	}
	
	if(KEY2_PRESS)
	{
		TIM2_delayms(10);
		if(KEY2_PRESS)
		{
			while(KEY2_PRESS);
			return KEY2;
		}
	}
	
	return KEY_NO;
	
}






