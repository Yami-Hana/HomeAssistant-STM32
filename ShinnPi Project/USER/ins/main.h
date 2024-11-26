#ifndef _MAIN_H_
#define _MAIN_H_
/**********包含的头文件***************/
#include "stm32f10x.h"
#include "./lcd/bsp_ili9341_lcd.h"
#include "./lcd/bsp_xpt2046_lcd.h"
#include "./usart/bsp_usart.h"
#include "./usart/bsp_esp8266.h"
#include "./led/bsp_led.h"
#include "./beep/bsp_beep.h" 
#include "fire.h"
#include "rain.h"
#include "shake.h"
#include "steering.h"
#include "led.h"
#include "nvic.h"
#include "mqtt.h"
#include "key.h"

#include "ff.h"
#include <stdio.h>
#include "tim.h"


#include "./sr501/bsp_exti.h"
#include "./dht11/bsp_dht11.h"
#include "./ldr/bsp_ldr.h" 

/**********全局变量、结构体、宏***************/
typedef struct{  
	char human[50];
	char fire[50];
	char rain[50];
	char shake[50];	
	char window[50];
	float T;
	float H;
	char message[500];
	
}SensorDate;


extern SensorDate SD;




/**********函数声明部分***************/
void UI_1(void);

void UI_2(void);

void UI_3(void);

void Data_Treat(void);

void Event(void);



#endif
