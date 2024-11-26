#ifndef _NVIC_H_
#define _NVIC_H_
/*********************头文件包含***************************/
#include "stm32f10x.h" 
#include "tim.h"
#include "./usart/bsp_esp8266.h"
#include "main.h"

/*********************宏、全局变量、结构体***************************/


/*********************函数声明***************************/

void TIM3_INIT(int x);
void TIM3_ITSource(void);


#endif
