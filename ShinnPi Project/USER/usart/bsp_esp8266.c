#include "./usart/bsp_esp8266.h"

USART3_TypeDef WiFi_Rev;


/**
  * @brief  ESP8266初始化函数
  * @param  无
  * @retval 无
  */
void ESP8266_Init ( void )
{
	ESP8266_GPIO_Config();
	
	macESP8266_RST_HIGH_LEVEL();

	macESP8266_CH_DISABLE();
	
	UART3_INIT(115200);
	
}


/**
  * @brief  初始化ESP8266用到的GPIO引脚
  * @param  无
  * @retval 无
  */
void ESP8266_GPIO_Config(void)
{
	/*定义一个GPIO_InitTypeDef类型的结构体*/
	GPIO_InitTypeDef GPIO_InitStructure;


	/* 配置 CH_PD 引脚*/
	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOG, ENABLE ); 
											   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;	

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	GPIO_Init ( GPIOG, & GPIO_InitStructure );	 

	
	/* 配置 RST 引脚*/
	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOG, ENABLE ); 
											   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;	

	GPIO_Init ( GPIOG, & GPIO_InitStructure );	 


}


/*
函数名： UART3_INIT
函数功能：UART3模块初始化
函数形参：U32 baud 波特率
函数返回值：void
备注：
TX： 发送数据输出引脚。
RX： 接收数据输入引脚。
PA9  USART3_TX
PA10 USART3_RX
APB2

*/
void UART3_INIT(u32 baud)
{
	//结构体
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	// 将USART Tx的GPIO配置为推挽复用模式
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	// 将USART Rx的GPIO配置为浮空输入模式
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_11;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	

	// 配置USART初始化
	USART_InitStruct.USART_BaudRate            = baud;//设置波特率
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//硬件流控
	USART_InitStruct.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx;//发送器和接收器使能
	USART_InitStruct.USART_Parity              = USART_Parity_No;//无校验位
	USART_InitStruct.USART_StopBits            = USART_StopBits_1;//停止位
	USART_InitStruct.USART_WordLength          = USART_WordLength_8b;//8字节长度
	USART_Init(USART3, &USART_InitStruct);
	
	/* 中断配置 */
	USART_ITConfig ( USART3, USART_IT_RXNE, ENABLE ); //使能串口接收中断 
	USART_ITConfig ( USART3, USART_IT_IDLE, ENABLE ); //使能串口总线空闲中断 
	
	UART3_ITSource();
	
	USART_Cmd(USART3, ENABLE);
	
}


/*
函数名： UART3_ITSource
函数功能：UART3中断源配置
函数形参：u8 pre ,u8 sub
函数返回值：void
备注：
PA9 发送引脚
PA10 接收引脚

*/
void UART3_ITSource(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//优先级分组
	
	NVIC_InitStruct.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStruct);
	
}


/*********************************************************************************************************
* 函 数 名 : USART3_IRQHandler
* 功能说明 : USART3中断服务函数
* 形    参 : 无
* 返 回 值 : 无
* 备    注 : 接收中断+空闲中断, 每接收到一个字节，就会执行一次
*********************************************************************************************************/ 
void USART3_IRQHandler(void)									
{
	u8 data;
	if(SET == USART_GetITStatus(USART3,USART_IT_RXNE))
	{
		data=USART_ReceiveData(USART3);
		if(data==0)
		{
			WiFi_Rev.Rev_Buff[WiFi_Rev.Rev_Cnt++]=' ';
		}
		else
		{
			WiFi_Rev.Rev_Buff[WiFi_Rev.Rev_Cnt++]=data;
		}
		USART_ClearITPendingBit(USART3,USART_IT_RXNE);
	}
	else if(USART_GetITStatus(USART3,USART_IT_IDLE))
	{
		USART3->SR;
		USART3->DR;
		WiFi_Rev.Rev_Buff[WiFi_Rev.Rev_Cnt]='\0';
		printf("%s\r\n",WiFi_Rev.Rev_Buff);
		WiFi_Rev.Rev_Cnt=0;
		WiFi_Rev.Rev_Flag=1;
		USART_ClearITPendingBit(USART3,USART_IT_IDLE);
	}
}


/*********************************************************************************************************
* 函 数 名 : USART3_SendString
* 功能说明 : USART3发送字符串函数
* 形    参 : str：需要发送的字符串
* 返 回 值 : 无
* 备    注 : 无
*********************************************************************************************************/ 
void USART3_SendString(char * str)
{
	while(*str != 0)		
	{
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC) == RESET);	//等待上一个字节发送完成
		USART_SendData(USART3,*str++);								//发送一个字节
	}
}


/*********************************************************************************************************
* 函 数 名 : USART3_SendPackage
* 功能说明 : USART3数据包发送函数
* 形    参 : data：需要发送的数据，len：发送的数据的长度
* 返 回 值 : 无
* 备    注 : 数据包中间可能会包含‘\0’, 所以需要依赖长度进行发送
*********************************************************************************************************/ 
void USART3_SendPackage(unsigned char *data,unsigned short len)	//发送数据包，中间包含‘\0’,所以需要依赖长度进行发送
{
	while(len--)
	{
		while(!USART_GetFlagStatus(USART3,USART_FLAG_TC));
		USART_SendData(USART3,*data++);
	}
}






