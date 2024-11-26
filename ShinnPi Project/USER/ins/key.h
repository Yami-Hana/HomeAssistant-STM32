#ifndef _KEY_H_
#define _KEY_H_
/**********������ͷ�ļ�***************/
#include "stm32f10x.h"
#include "tim.h"

/**********ȫ�ֱ������ṹ�塢��***************/
#define KEY1_PRESS Bit_SET == GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)

#define KEY2_PRESS Bit_SET == GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13)

typedef enum key_zt{KEY_NO,KEY1,KEY2} KEY_ZT;
/**********������������***************/
void KEY_INIT(void);
KEY_ZT KEY_SCAN(void);


#endif
