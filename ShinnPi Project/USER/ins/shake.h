#ifndef _SHAKE_H_
#define	_SHAKE_H_

#include "stm32f10x.h"
#include "stm32f10x_rcc.h"

 /** �������±��ú�
	*  ��������Ϊ�ߵ�ƽ������ KEY_ON=1�� KEY_OFF=0
	*  ����������Ϊ�͵�ƽ���Ѻ����ó�KEY_ON=0 ��KEY_OFF=1 ����
	*/
#define SHAKE_ON	1     // �й�
#define SHAKE_OFF	0     // �޹�

void SHAKE_INIT(void);
uint8_t SHAKE_Test(void);


#endif /* _SHAKE_H_ */

