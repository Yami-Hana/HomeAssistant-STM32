#include "rain.h"

/**
  ���ù����õ���I/O��
  */
void RAIN_INIT(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*�����˿ڵ�ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG,ENABLE);
	
	//ѡ�����������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	// ���ù������������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(GPIOG, &GPIO_InitStructure);
}


uint8_t RAIN_Test(void)
{			
	/*�������״̬ */
	if(GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_0) == 1 )  
	{	  
		return RAIN_OFF;    // �޹�
	}
	else
		return RAIN_ON;    // �й�
}
/*********************************************END OF FILE**********************/
