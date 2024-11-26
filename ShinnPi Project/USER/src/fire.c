#include "fire.h"

/**
  ���û��洫�����õ���I/O��
  */
void FIRE_INIT(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*�����˿ڵ�ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG,ENABLE);
	
	//ѡ�����������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1; 
	// ���û��洫�������������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(GPIOG, &GPIO_InitStructure);
}


uint8_t FIRE_Test(void)
{			
	/*�����洫��������״̬ */
	if(GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_1) == 1 )  
	{	  
		return FIRE_OFF;    // �޻�
	}
	else
		return FIRE_ON;    // �л�
}
/*********************************************END OF FILE**********************/
