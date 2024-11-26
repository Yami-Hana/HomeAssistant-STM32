#include "./usart/bsp_esp8266.h"

USART3_TypeDef WiFi_Rev;


/**
  * @brief  ESP8266��ʼ������
  * @param  ��
  * @retval ��
  */
void ESP8266_Init ( void )
{
	ESP8266_GPIO_Config();
	
	macESP8266_RST_HIGH_LEVEL();

	macESP8266_CH_DISABLE();
	
	UART3_INIT(115200);
	
}


/**
  * @brief  ��ʼ��ESP8266�õ���GPIO����
  * @param  ��
  * @retval ��
  */
void ESP8266_GPIO_Config(void)
{
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;


	/* ���� CH_PD ����*/
	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOG, ENABLE ); 
											   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;	

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	GPIO_Init ( GPIOG, & GPIO_InitStructure );	 

	
	/* ���� RST ����*/
	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOG, ENABLE ); 
											   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;	

	GPIO_Init ( GPIOG, & GPIO_InitStructure );	 


}


/*
�������� UART3_INIT
�������ܣ�UART3ģ���ʼ��
�����βΣ�U32 baud ������
��������ֵ��void
��ע��
TX�� ��������������š�
RX�� ���������������š�
PA9  USART3_TX
PA10 USART3_RX
APB2

*/
void UART3_INIT(u32 baud)
{
	//�ṹ��
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	// ��USART Tx��GPIO����Ϊ���츴��ģʽ
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	// ��USART Rx��GPIO����Ϊ��������ģʽ
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_11;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	

	// ����USART��ʼ��
	USART_InitStruct.USART_BaudRate            = baud;//���ò�����
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//Ӳ������
	USART_InitStruct.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx;//�������ͽ�����ʹ��
	USART_InitStruct.USART_Parity              = USART_Parity_No;//��У��λ
	USART_InitStruct.USART_StopBits            = USART_StopBits_1;//ֹͣλ
	USART_InitStruct.USART_WordLength          = USART_WordLength_8b;//8�ֽڳ���
	USART_Init(USART3, &USART_InitStruct);
	
	/* �ж����� */
	USART_ITConfig ( USART3, USART_IT_RXNE, ENABLE ); //ʹ�ܴ��ڽ����ж� 
	USART_ITConfig ( USART3, USART_IT_IDLE, ENABLE ); //ʹ�ܴ������߿����ж� 
	
	UART3_ITSource();
	
	USART_Cmd(USART3, ENABLE);
	
}


/*
�������� UART3_ITSource
�������ܣ�UART3�ж�Դ����
�����βΣ�u8 pre ,u8 sub
��������ֵ��void
��ע��
PA9 ��������
PA10 ��������

*/
void UART3_ITSource(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//���ȼ�����
	
	NVIC_InitStruct.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStruct);
	
}


/*********************************************************************************************************
* �� �� �� : USART3_IRQHandler
* ����˵�� : USART3�жϷ�����
* ��    �� : ��
* �� �� ֵ : ��
* ��    ע : �����ж�+�����ж�, ÿ���յ�һ���ֽڣ��ͻ�ִ��һ��
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
* �� �� �� : USART3_SendString
* ����˵�� : USART3�����ַ�������
* ��    �� : str����Ҫ���͵��ַ���
* �� �� ֵ : ��
* ��    ע : ��
*********************************************************************************************************/ 
void USART3_SendString(char * str)
{
	while(*str != 0)		
	{
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC) == RESET);	//�ȴ���һ���ֽڷ������
		USART_SendData(USART3,*str++);								//����һ���ֽ�
	}
}


/*********************************************************************************************************
* �� �� �� : USART3_SendPackage
* ����˵�� : USART3���ݰ����ͺ���
* ��    �� : data����Ҫ���͵����ݣ�len�����͵����ݵĳ���
* �� �� ֵ : ��
* ��    ע : ���ݰ��м���ܻ������\0��, ������Ҫ�������Ƚ��з���
*********************************************************************************************************/ 
void USART3_SendPackage(unsigned char *data,unsigned short len)	//�������ݰ����м������\0��,������Ҫ�������Ƚ��з���
{
	while(len--)
	{
		while(!USART_GetFlagStatus(USART3,USART_FLAG_TC));
		USART_SendData(USART3,*data++);
	}
}






