#include "shake.h"

/**
  ���ù����õ���I/O��
  */
void SHAKE_INIT(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*�����˿ڵ�ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);
	
	//ѡ�����������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14; 
	// ���ù������������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}


uint8_t SHAKE_Test(void)
{			
	/*�������״̬ */
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_14) == 0 )  
	{	  
		return SHAKE_OFF;
	}
	else
		return SHAKE_ON;
}
/*********************************************END OF FILE**********************/
