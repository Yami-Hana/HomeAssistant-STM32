#ifndef __BEEP_H
#define	__BEEP_H


#include "stm32f10x.h"


/* 定义蜂鸣器连接的GPIO端口, 用户只需要修改下面的代码即可改变控制的蜂鸣器引脚 */
#define BEEP_GPIO_PORT    	GPIOC			              /* GPIO端口 */
#define BEEP_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO端口时钟 */
#define BEEP_GPIO_PIN		  GPIO_Pin_0			        /* 连接到蜂鸣器的GPIO */

/* 高电平时，蜂鸣器响 */

#define		BEEP_ON		  GPIO_SetBits ( BEEP_GPIO_PORT ,  GPIO_Pin_0 )
#define		BEEP_OFF		GPIO_ResetBits ( BEEP_GPIO_PORT ,  GPIO_Pin_0 )

void BEEP_GPIO_Config(void);
					
#endif /* __BEEP_H */
