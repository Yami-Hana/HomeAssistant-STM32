#ifndef _LED_H_
#define _LED_H_
/**********包含的头文件***************/
#include "stm32f10x.h"


/**********全局变量、结构体、宏***************/

#define LED5_OFF GPIO_ResetBits(GPIOB, GPIO_Pin_8)
#define LED5_ON GPIO_SetBits(GPIOB, GPIO_Pin_8)

#define LED6_OFF GPIO_ResetBits(GPIOB, GPIO_Pin_9)
#define LED6_ON GPIO_SetBits(GPIOB, GPIO_Pin_9)

#define LED7_OFF GPIO_ResetBits(GPIOF, GPIO_Pin_12)
#define LED7_ON GPIO_SetBits(GPIOF, GPIO_Pin_12)

#define LED8_OFF GPIO_ResetBits(GPIOF, GPIO_Pin_13)
#define LED8_ON GPIO_SetBits(GPIOF, GPIO_Pin_13)

#define LED9_OFF GPIO_ResetBits(GPIOC, GPIO_Pin_7)
#define LED9_ON GPIO_SetBits(GPIOC, GPIO_Pin_7)


/**********函数声明部分***************/
void LED_INIT(void);



#endif
