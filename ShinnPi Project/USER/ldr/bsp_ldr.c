#include "./ldr/bsp_ldr.h" 
#include "./led/bsp_led.h"

/**
  配置光敏用到的I/O口
  */
void LDR_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*开启端口的时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);
	
	//选择输入的引脚
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15; 
	// 设置光敏输入的引脚为下拉输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(GPIOF, &GPIO_InitStructure);
}

 /*
 * 函数名：光敏电阻测试
 * 描述  ：检测光敏电阻的状态
 * 输入  ：GPIOx：x 可以是 A，B，C，D或者 E
 *		     GPIO_Pin：待读取的端口位 	
 * 输出  ：LDR_ON：有光   LDR_OFF：无光
 */
uint8_t LDR_Test(void)
{			
	/*检测光敏输入状态 */
	if(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_15) == 1 )  
	{	  
		return LDR_OFF;    // 无光
	}
	else
		return LDR_ON;    // 有光
}
/*********************************************END OF FILE**********************/
