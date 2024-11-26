#include "led.h"

/*
������    ��LED_INIT
��������  : ��led��ʼ��
��������ֵ��void
�����β�  ��void

  
*/

void LED_INIT(void)
{
	//�ṹ��
	GPIO_InitTypeDef GPIO_InitStruct;	
	//����ʱ������
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;//���ģʽ
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_12 | GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;//���ģʽ
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOF, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;//���ģʽ
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	LED5_OFF;
	LED6_OFF;
	LED7_OFF;
	LED8_OFF;
	LED9_OFF;
	
}







