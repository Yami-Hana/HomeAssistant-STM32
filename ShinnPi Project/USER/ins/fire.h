#ifndef _FIRE_H_
#define	_FIRE_H_

#include "stm32f10x.h"
#include "stm32f10x_rcc.h"

 /** �������±��ú�
	*  ��������Ϊ�ߵ�ƽ������ KEY_ON=1�� KEY_OFF=0
	*  ����������Ϊ�͵�ƽ���Ѻ����ó�KEY_ON=0 ��KEY_OFF=1 ����
	*/
#define FIRE_ON	1     // �й�
#define FIRE_OFF	0     // �޹�

void FIRE_INIT(void);
uint8_t FIRE_Test(void);


#endif /* _FIRE_H_ */

