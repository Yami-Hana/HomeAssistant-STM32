#ifndef _RAIN_H_
#define	_RAIN_H_

#include "stm32f10x.h"
#include "stm32f10x_rcc.h"

 /** 按键按下标置宏
	*  按键按下为高电平，设置 KEY_ON=1， KEY_OFF=0
	*  若按键按下为低电平，把宏设置成KEY_ON=0 ，KEY_OFF=1 即可
	*/
#define RAIN_ON	1     // 有光
#define RAIN_OFF	0     // 无光

void RAIN_INIT(void);
uint8_t RAIN_Test(void);


#endif /* _RAIN_H_ */

