#include "main.h"
SensorDate SD;
DHT11_Data_TypeDef DHT11_Data;

extern void jpgDisplay(char *pic_name);
extern int Window_Flag;

FATFS fs;											/* FatFs文件系统对象 */
FRESULT res_sd;               /* 文件操作结果 */

int Flag = 0;
int PIC = 0;

int main ( void )
{
	
	ILI9341_Init ();         //LCD 初始化
	
	USART_Config();		
	LED_GPIO_Config();//RGB
	LED_INIT();//LED
	DHT11_Init ();
	KEY_INIT();
	Steering_Engine_INIT();
	
	EXTI_SR501_Config();
	LDR_GPIO_Config();
	FIRE_INIT();
	RAIN_INIT();
	SHAKE_INIT();
	BEEP_GPIO_Config();
	
	//WIFI初始化
	MQTT_INIT();
	TIM3_INIT(2000);
	TIM3_ITSource();
	
	ILI9341_OpenWindow(0,0,320,240);
	LCD_SetFont(&Font8x16);
	LCD_SetColors(RED,BLACK);
  ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	/* 清屏，显示全黑 */
	ILI9341_GramScan (3);//横屏显示
	
	res_sd = f_mount(&fs,"0:",1);
	if(res_sd != FR_OK)
	{
		printf("\r\n请给开发板插入已格式化成fat格式的SD卡。\r\n");
	}
	
	
	jpgDisplay("0:/Home320X240.jpg");
	//jpgDisplay("0:/UI_1.jpg");
	//jpgDisplay("0:/UI_2.jpg");
	
	while(1)
	{	
		ILI9341_DispString_EN_CH (44, 210, "主页");
		ILI9341_DispString_EN_CH (144, 210, "环境");
		ILI9341_DispString_EN_CH (244, 210, "安全");
		
		if(KEY1_PRESS)
		{
			if(Flag < 3) Flag++;
			else Flag = 0;
		}
		else if(KEY2_PRESS)
		{
			Flag = 0;
		}
		if(Flag == 0)
		{
			if(PIC != 0)
			{
				jpgDisplay("0:/Home320X240.jpg");
				PIC = 0;
			}
			UI_1();
		}
		else if(Flag == 1)
		{
			if(PIC != 1)
			{
				jpgDisplay("0:/UI_1.jpg");
				PIC = 1;
			}
			UI_2();
		}
		else if(Flag == 2)
		{
			if(PIC != 2)
			{
				jpgDisplay("0:/UI_2.jpg");
				PIC = 2;
			}
			UI_3();
		}
		
		Data_Treat();
		Event();
		
		TIM2_delayms(500);
		
	}
	
}

void Data_Treat(void)
{
	//温湿度传感器
	if( DHT11_Read_TempAndHumidity ( & DHT11_Data ) == SUCCESS)
	{			
		//数据存储
		SD.T = (float)DHT11_Data.temp_int+(float)DHT11_Data.temp_deci/10;
			
		//数据存储
		SD.H = (float)DHT11_Data.humi_int+(float)DHT11_Data.humi_deci/10;		
	}
	//光敏
	if (LDR_Test() == LDR_ON)
	{
		LED5_OFF;    // 有光灯灭
	}
	else
	{
		LED5_ON;   // 无光灯亮
	} 
  //火焰
	if (FIRE_Test() == FIRE_ON)
	{
		LED9_ON;
		BEEP_ON;
		sprintf(SD.fire,"\\\"Fire warning\\\"");
	}
	else
	{
		LED9_OFF;
		BEEP_OFF;
		sprintf(SD.fire,"\\\"Fire safety\\\"");
	}
	//雨滴
	if (RAIN_Test() == RAIN_ON)
	{
		if(Window_Flag == 1)
		{
			Close_Window();
		}
		sprintf(SD.rain,"\\\"Raining\\\"");
	}
	else
	{
		//Open_Window();
		sprintf(SD.rain,"\\\"No Rain\\\"");
	}
	//震动
	if (SHAKE_Test() == SHAKE_ON)
	{
		sprintf(SD.shake,"\\\"Shakeing\\\"");
	}
	else
	{
		sprintf(SD.shake,"\\\"No Shake\\\"");
	}
	//人体红外
	if(GPIO_ReadInputDataBit(SR501_INT_GPIO_PORT,SR501_INT_GPIO_PIN)  == 0)
	{
		sprintf(SD.human,"\\\"Nobody\\\"");
	}
	else
	{
		sprintf(SD.human,"\\\"Someone\\\"");
	}
	
	sprintf(SD.message,"AT+MQTTPUB=0,\"/k08feePiGKj/TKSTM32/user/stm32\",\"{\\\"Human\\\": %s\\,\\\"Fire\\\": %s\\,\\\"Rain\\\": %s\\,\\\"Shake\\\": %s\\,\\\"T\\\": %.1f\\,\\\"H\\\": %.1f}\",0,0\r\n",
	SD.human, SD.fire, SD.rain, SD.shake, SD.T, SD.H);

}

void UI_1(void)
{

	
}



void UI_2(void)
{
	char dispBuff[100];
	
	/* 显示温度 */
	sprintf(dispBuff,"温度 : %.1f℃",SD.T);
	ILI9341_DispStringLine_EN_CH(LINE(0),dispBuff);
		
	/* 显示湿度 */
	sprintf(dispBuff,"湿度 : %.1f%%",SD.H);
	
	ILI9341_DispStringLine_EN_CH(LINE(1),dispBuff);

	if (LDR_Test() == LDR_ON)
	{
		ILI9341_DispStringLine_EN_CH(LINE(2),"室外灯：关");
	}
	else
	{
		ILI9341_DispStringLine_EN_CH(LINE(2),"室外灯：开");
	} 
	
	if (strcmp(SD.rain,"\\\"Raining\\\"") == 0)
	{
		ILI9341_DispStringLine_EN_CH(LINE(3),"当前下雨");
	}
	else
	{
		ILI9341_DispStringLine_EN_CH(LINE(3),"当前无雨");
	}
	
}

void UI_3(void)
{
	if (strcmp(SD.fire,"\\\"Fire warning\\\"") == 0)
	{
		ILI9341_DispStringLine_EN_CH(LINE(0),"火灾警告：开");
		LED9_ON;
		BEEP_ON;
	}
	else
	{
		ILI9341_DispStringLine_EN_CH(LINE(0),"火灾警告：关");
		LED9_OFF;
		BEEP_OFF;
	}
	
	if (strcmp(SD.shake,"\\\"Shakeing\\\"") == 0)
	{
		ILI9341_DispStringLine_EN_CH(LINE(1),"有人敲门");	
	}
	else
	{
		ILI9341_DispStringLine_EN_CH(LINE(1),"无人敲门");
	}
	
	if(strcmp(SD.human,"\\\"Nobody\\\"") == 0)
	{
		ILI9341_DispStringLine_EN_CH(LINE(2),"门口无人");
	}
	else
	{
		ILI9341_DispStringLine_EN_CH(LINE(2),"门口有人");
	}
	
}


void Event(void)
{
	if( strstr(WiFi_Rev.Rev_Buff ,"LED_1_ON") != NULL)
	{
		LED6_ON;
	}
	else if( strstr(WiFi_Rev.Rev_Buff ,"LED_1_OFF") != NULL)
	{
		LED6_OFF;
	}
	else if( strstr(WiFi_Rev.Rev_Buff ,"LED_2_ON") != NULL)
	{
		LED7_ON;
	}
	else if( strstr(WiFi_Rev.Rev_Buff ,"LED_2_OFF") != NULL)
	{
		LED7_OFF;
	}
	else if( strstr(WiFi_Rev.Rev_Buff ,"LED_3_ON") != NULL)
	{
		LED8_ON;
	}
	else if( strstr(WiFi_Rev.Rev_Buff ,"LED_3_OFF") != NULL)
	{
		LED8_OFF;
	}
	else if( strstr(WiFi_Rev.Rev_Buff ,"Window_ON") != NULL)
	{
		Open_Window();
	}
	else if( strstr(WiFi_Rev.Rev_Buff ,"Window_OFF") != NULL)
	{
		Close_Window();
	}
		
}



/* ------------------------------------------end of file---------------------------------------- */

