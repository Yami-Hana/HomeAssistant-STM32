#include "sram.h"

/**
  * @brief  ��ʼ������SRAM��IO
  * @param  ��
  * @retval ��
  */
static void SRAM_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 
  /* ʹ��SRAM��ص�GPIOʱ�� */

                         /*��ַ�ź���*/
  RCC_APB2PeriphClockCmd(FSMC_A0_GPIO_CLK | FSMC_A1_GPIO_CLK | FSMC_A2_GPIO_CLK | 
                         FSMC_A3_GPIO_CLK | FSMC_A4_GPIO_CLK | FSMC_A5_GPIO_CLK |
                         FSMC_A6_GPIO_CLK | FSMC_A7_GPIO_CLK | FSMC_A8_GPIO_CLK |
                         FSMC_A9_GPIO_CLK | FSMC_A10_GPIO_CLK| FSMC_A11_GPIO_CLK| 
												 FSMC_A12_GPIO_CLK| FSMC_A13_GPIO_CLK| FSMC_A14_GPIO_CLK|
												 FSMC_A15_GPIO_CLK| FSMC_A16_GPIO_CLK| FSMC_A17_GPIO_CLK|
												 FSMC_A18_GPIO_CLK|
                         /*�����ź���*/
                         FSMC_D0_GPIO_CLK | FSMC_D1_GPIO_CLK | FSMC_D2_GPIO_CLK | 
                         FSMC_D3_GPIO_CLK | FSMC_D4_GPIO_CLK | FSMC_D5_GPIO_CLK |
                         FSMC_D6_GPIO_CLK | FSMC_D7_GPIO_CLK | FSMC_D8_GPIO_CLK |
                         FSMC_D9_GPIO_CLK | FSMC_D10_GPIO_CLK| FSMC_D11_GPIO_CLK|
                         FSMC_D12_GPIO_CLK| FSMC_D13_GPIO_CLK| FSMC_D14_GPIO_CLK|
                         FSMC_D15_GPIO_CLK|  
                         /*�����ź���*/
                         FSMC_CS_GPIO_CLK  | FSMC_WE_GPIO_CLK | FSMC_OE_GPIO_CLK |
                         FSMC_UDQM_GPIO_CLK|FSMC_LDQM_GPIO_CLK, ENABLE);
												 


	 /*-- GPIO ���� -----------------------------------------------------*/

  /* ͨ�� GPIO ���� */
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;       //����Ϊ���ù���
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     
  
  /*A��ַ�ź��� �����������*/
  GPIO_InitStructure.GPIO_Pin = FSMC_A0_GPIO_PIN; 
  GPIO_Init(FSMC_A0_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_A1_GPIO_PIN; 
  GPIO_Init(FSMC_A1_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_A2_GPIO_PIN; 
  GPIO_Init(FSMC_A2_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_A3_GPIO_PIN; 
  GPIO_Init(FSMC_A3_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_A4_GPIO_PIN; 
  GPIO_Init(FSMC_A4_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_A5_GPIO_PIN; 
  GPIO_Init(FSMC_A5_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_A6_GPIO_PIN; 
  GPIO_Init(FSMC_A6_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_A7_GPIO_PIN; 
  GPIO_Init(FSMC_A7_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_A8_GPIO_PIN; 
  GPIO_Init(FSMC_A8_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_A9_GPIO_PIN; 
  GPIO_Init(FSMC_A9_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_A10_GPIO_PIN; 
  GPIO_Init(FSMC_A10_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_A11_GPIO_PIN; 
  GPIO_Init(FSMC_A11_GPIO_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = FSMC_A12_GPIO_PIN; 
  GPIO_Init(FSMC_A12_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_A13_GPIO_PIN; 
  GPIO_Init(FSMC_A13_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_A14_GPIO_PIN; 
  GPIO_Init(FSMC_A14_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_A15_GPIO_PIN; 
  GPIO_Init(FSMC_A15_GPIO_PORT, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = FSMC_A16_GPIO_PIN; 
  GPIO_Init(FSMC_A16_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_A17_GPIO_PIN; 
  GPIO_Init(FSMC_A17_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_A18_GPIO_PIN; 
  GPIO_Init(FSMC_A18_GPIO_PORT, &GPIO_InitStructure);
    
  /*DQ�����ź��� �����������*/
  GPIO_InitStructure.GPIO_Pin = FSMC_D0_GPIO_PIN; 
  GPIO_Init(FSMC_D0_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_D1_GPIO_PIN; 
  GPIO_Init(FSMC_D1_GPIO_PORT, &GPIO_InitStructure);
    
  GPIO_InitStructure.GPIO_Pin = FSMC_D2_GPIO_PIN; 
  GPIO_Init(FSMC_D2_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_D3_GPIO_PIN; 
  GPIO_Init(FSMC_D3_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_D4_GPIO_PIN; 
  GPIO_Init(FSMC_D4_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_D5_GPIO_PIN; 
  GPIO_Init(FSMC_D5_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_D6_GPIO_PIN; 
  GPIO_Init(FSMC_D6_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_D7_GPIO_PIN; 
  GPIO_Init(FSMC_D7_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_D8_GPIO_PIN; 
  GPIO_Init(FSMC_D8_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_D9_GPIO_PIN; 
  GPIO_Init(FSMC_D9_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_D10_GPIO_PIN; 
  GPIO_Init(FSMC_D10_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_D11_GPIO_PIN; 
  GPIO_Init(FSMC_D11_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_D12_GPIO_PIN; 
  GPIO_Init(FSMC_D12_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_D13_GPIO_PIN; 
  GPIO_Init(FSMC_D13_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_D14_GPIO_PIN; 
  GPIO_Init(FSMC_D14_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_D15_GPIO_PIN; 
  GPIO_Init(FSMC_D15_GPIO_PORT, &GPIO_InitStructure);
  
  /*�����ź���*/
  GPIO_InitStructure.GPIO_Pin = FSMC_CS_GPIO_PIN; 
  GPIO_Init(FSMC_CS_GPIO_PORT, &GPIO_InitStructure);
    
  GPIO_InitStructure.GPIO_Pin = FSMC_WE_GPIO_PIN; 
  GPIO_Init(FSMC_WE_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_OE_GPIO_PIN; 
  GPIO_Init(FSMC_OE_GPIO_PORT, &GPIO_InitStructure);    
  
  GPIO_InitStructure.GPIO_Pin = FSMC_UDQM_GPIO_PIN; 
  GPIO_Init(FSMC_UDQM_GPIO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = FSMC_LDQM_GPIO_PIN; 
  GPIO_Init(FSMC_LDQM_GPIO_PORT, &GPIO_InitStructure);	
}

/**
  * @brief  ��ʼ��FSMC����
  * @param  None. 
  * @retval None.
 */

static void FSMC_ModeConfig(void)
{
	FSMC_NORSRAMTimingInitTypeDef  readTiming;
	FSMC_NORSRAMTimingInitTypeDef  writeTiming;
	FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
	
	//ʹ��FSMCʱ��
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);
	
	//��
	readTiming.FSMC_AccessMode = FSMC_AccessMode_A;//ѡ��ƥ��SRAM��ģʽ
	readTiming.FSMC_AddressSetupTime = 0;//��ַ����ʱ�䣨ADDSET��Ϊ1��HCLK 1/72M=14ns
	readTiming.FSMC_AddressHoldTime = 0;//��ַ����ʱ�䣨ADDHLD��ģʽAδ�õ�	 
	readTiming.FSMC_DataSetupTime = 2;//���ݱ���ʱ�䣨DATAST��+ 1��HCLK = 3/72M=42ns(��EM��SRAMоƬ)			  
	readTiming.FSMC_BusTurnAroundDuration = 0;//��������ת�����ڣ������ڸ���ģʽ��NOR����
	readTiming.FSMC_CLKDivision = 0;//����ʱ�ӷ�Ƶ��������ͬ�����͵Ĵ洢��
	readTiming.FSMC_DataLatency = 0;//���ݱ���ʱ�䣬������ͬ���͵�NOR		
	
	//д
	writeTiming.FSMC_AccessMode = FSMC_AccessMode_A;//ѡ��ƥ��SRAM��ģʽ
	writeTiming.FSMC_AddressSetupTime = 0;//��ַ����ʱ�䣨ADDSET��Ϊ1��HCLK 1/72M=14ns
	writeTiming.FSMC_AddressHoldTime = 0;//��ַ����ʱ�䣨ADDHLD��ģʽAδ�õ�	 
	writeTiming.FSMC_DataSetupTime = 2;//���ݱ���ʱ�䣨DATAST��+ 1��HCLK = 3/72M=42ns(��EM��SRAMоƬ)			  
	writeTiming.FSMC_BusTurnAroundDuration = 0;//��������ת�����ڣ������ڸ���ģʽ��NOR����
	writeTiming.FSMC_CLKDivision = 0;//����ʱ�ӷ�Ƶ��������ͬ�����͵Ĵ洢��
	writeTiming.FSMC_DataLatency = 0;//���ݱ���ʱ�䣬������ͬ���͵�NOR	
	
	FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM3;// ѡ��FSMCӳ��Ĵ洢���� Bank1 sram3
	FSMC_NORSRAMInitStructure.FSMC_MemoryType =FSMC_MemoryType_SRAM;//����Ҫ���ƵĴ洢�����ͣ�SRAM����   
	FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;//�洢�����ݿ�ȣ�16λ 
	FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Enable;//��ʹ����չģʽ����дʹ����ͬ��ʱ�� 
	
	//SRAMδʹ�ò���
	FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;//���õȴ��źŵ���Ч���ԣ�������ͬ�����͵Ĵ洢��
	FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;//���õȴ��źŲ����ʱ�䣬������ͬ�����͵Ĵ洢��
	FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;//�洢��дʹ��  
	FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;//���õ�ַ���������������Ƿ��ã�������NOR 
	FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;//�����Ƿ�֧�ְѷǶ����ͻ��������������ͬ�����͵Ĵ洢��
	FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode =FSMC_BurstAccessMode_Disable;//�����Ƿ�ʹ��ͻ������ģʽ��������ͬ�����͵Ĵ洢��
	FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait=FSMC_AsynchronousWait_Disable;//�����Ƿ�ʹ�ܵȴ��źţ�������ͬ�����͵Ĵ洢��
	FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;//��ʹ�õȴ��ź�  		
	FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;//ͻ��д���� 
	
	//��ʱ������
	FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &readTiming;
	//��дͬ��ʱ��ʹ����չģʽʱ������ò���Ч
	FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &writeTiming; 

	FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);  //��ʼ��FSMC����
	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM3, ENABLE);  // ʹ��BANK		
	
}

void SRAM_Init(void)
{
	SRAM_GPIO_Config();
	FSMC_ModeConfig();
}


