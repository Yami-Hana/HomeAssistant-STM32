#ifndef _NVIC_H_
#define _NVIC_H_
/*********************ͷ�ļ�����***************************/
#include "stm32f10x.h" 
#include "tim.h"
#include "./usart/bsp_esp8266.h"
#include "main.h"

/*********************�ꡢȫ�ֱ������ṹ��***************************/


/*********************��������***************************/

void TIM3_INIT(int x);
void TIM3_ITSource(void);


#endif
