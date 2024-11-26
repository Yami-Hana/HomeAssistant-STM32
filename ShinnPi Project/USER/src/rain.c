#include "rain.h"

/**
  配置光敏用到的I/O口
  */
void RAIN_INIT(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*开启端口的时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG,ENABLE);
	
	//选择输入的引脚
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	// 设置光敏输入的引脚为下拉输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(GPIOG, &GPIO_InitStructure);
}


uint8_t RAIN_Test(void)
{			
	/*检测输入状态 */
	if(GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_0) == 1 )  
	{	  
		return RAIN_OFF;    // 无光
	}
	else
		return RAIN_ON;    // 有光
}
/*********************************************END OF FILE**********************/
