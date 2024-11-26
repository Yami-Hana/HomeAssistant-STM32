#ifndef  __BSP_ESP8266_H
#define	 __BSP_ESP8266_H



#include "stm32f10x.h"
#include "./usart/bsp_usart.h" 
#include <stdbool.h>
#include <stdio.h>  
#include <string.h>  
#include <stdbool.h>
#include "tim.h"



#if defined ( __CC_ARM   )
#pragma anon_unions
#endif


/******************************* ESP8266 外部全局变量声明 ***************************/
typedef struct
{
	char Rev_Buff[1024];
	char Rev_Flag;
	short Rev_Cnt;	
}USART3_TypeDef;

extern USART3_TypeDef WiFi_Rev;


/*********************************************** ESP8266 函数宏定义 *******************************************/

#define macESP8266_RST_HIGH_LEVEL() GPIO_SetBits(GPIOG, GPIO_Pin_14)
#define macESP8266_RST_LOW_LEVEL()  GPIO_ResetBits(GPIOG, GPIO_Pin_14)

#define macESP8266_CH_ENABLE()  GPIO_SetBits(GPIOG, GPIO_Pin_13)
#define macESP8266_CH_DISABLE() GPIO_ResetBits(GPIOG, GPIO_Pin_13)


/****************************************** ESP8266 函数声明 ***********************************************/
void ESP8266_Init(void);
void ESP8266_GPIO_Config(void);

void UART3_INIT(u32 baud);
void USART3_IRQHandler(void);
void UART3_ITSource(void);


void USART3_SendString(char *str);
void USART3_SendPackage(unsigned char *data,unsigned short len);




#endif


