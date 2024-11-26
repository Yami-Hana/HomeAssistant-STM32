#include "fire.h"

/**
  配置火焰传感器用到的I/O口
  */
void FIRE_INIT(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*开启端口的时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG,ENABLE);
	
	//选择输入的引脚
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1; 
	// 设置火焰传感器输入的引脚为下拉输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(GPIOG, &GPIO_InitStructure);
}


uint8_t FIRE_Test(void)
{			
	/*检测火焰传感器输入状态 */
	if(GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_1) == 1 )  
	{	  
		return FIRE_OFF;    // 无火
	}
	else
		return FIRE_ON;    // 有火
}
/*********************************************END OF FILE**********************/
