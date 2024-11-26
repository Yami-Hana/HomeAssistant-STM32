#ifndef __BEEP_H
#define	__BEEP_H


#include "stm32f10x.h"


/* ������������ӵ�GPIO�˿�, �û�ֻ��Ҫ�޸�����Ĵ��뼴�ɸı���Ƶķ��������� */
#define BEEP_GPIO_PORT    	GPIOC			              /* GPIO�˿� */
#define BEEP_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO�˿�ʱ�� */
#define BEEP_GPIO_PIN		  GPIO_Pin_0			        /* ���ӵ���������GPIO */

/* �ߵ�ƽʱ���������� */

#define		BEEP_ON		  GPIO_SetBits ( BEEP_GPIO_PORT ,  GPIO_Pin_0 )
#define		BEEP_OFF		GPIO_ResetBits ( BEEP_GPIO_PORT ,  GPIO_Pin_0 )

void BEEP_GPIO_Config(void);
					
#endif /* __BEEP_H */
