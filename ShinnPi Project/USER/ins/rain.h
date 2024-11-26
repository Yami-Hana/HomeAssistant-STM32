#ifndef _RAIN_H_
#define	_RAIN_H_

#include "stm32f10x.h"
#include "stm32f10x_rcc.h"

 /** �������±��ú�
	*  ��������Ϊ�ߵ�ƽ������ KEY_ON=1�� KEY_OFF=0
	*  ����������Ϊ�͵�ƽ���Ѻ����ó�KEY_ON=0 ��KEY_OFF=1 ����
	*/
#define RAIN_ON	1     // �й�
#define RAIN_OFF	0     // �޹�

void RAIN_INIT(void);
uint8_t RAIN_Test(void);


#endif /* _RAIN_H_ */

