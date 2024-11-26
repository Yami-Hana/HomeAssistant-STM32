#include "shake.h"

/**
  配置光敏用到的I/O口
  */
void SHAKE_INIT(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*开启端口的时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);
	
	//选择输入的引脚
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14; 
	// 设置光敏输入的引脚为下拉输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}


uint8_t SHAKE_Test(void)
{			
	/*检测输入状态 */
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_14) == 0 )  
	{	  
		return SHAKE_OFF;
	}
	else
		return SHAKE_ON;
}
/*********************************************END OF FILE**********************/
