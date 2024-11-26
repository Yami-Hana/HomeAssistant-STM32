#include "./ldr/bsp_ldr.h" 
#include "./led/bsp_led.h"

/**
  ���ù����õ���I/O��
  */
void LDR_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*�����˿ڵ�ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);
	
	//ѡ�����������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15; 
	// ���ù������������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(GPIOF, &GPIO_InitStructure);
}

 /*
 * �������������������
 * ����  �������������״̬
 * ����  ��GPIOx��x ������ A��B��C��D���� E
 *		     GPIO_Pin������ȡ�Ķ˿�λ 	
 * ���  ��LDR_ON���й�   LDR_OFF���޹�
 */
uint8_t LDR_Test(void)
{			
	/*����������״̬ */
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_15) == 1 )  
	{	  
		return LDR_OFF;    // �޹�
	}
	else
		return LDR_ON;    // �й�
}
/*********************************************END OF FILE**********************/
