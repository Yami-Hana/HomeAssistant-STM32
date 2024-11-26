#include "mqtt.h"

void MQTT_INIT(void)
{
	//ESP8266的初始化
	ESP8266_Init();
	//使能 ESP8266
	macESP8266_CH_ENABLE();
	//延迟两秒等待esp8266初始化
	TIM2_delayms(2000);
	
	//测试指令AT
	USART3_SendString("AT\r\n");
	TIM2_delayms(1000);
	//选择客户端模式
	USART3_SendString("AT+CWMODE=1\r\n");
	TIM2_delayms(1000);
	//连接WIFI
	USART3_SendString("AT+CWJAP=\"TP-LINK_7DA6\",\"15216216216\"\r\n");
	TIM2_delayms(5000);
	
	//连接MQTT
	//USART3_SendString("AT+CIPSNTPCFG=1,8,\"iot.console.aliyun.com\"\r\n");
	
	USART3_SendString("AT+MQTTUSERCFG=0,1,\"k08feePiGKj.TKSTM32|securemode=2\\,signmethod=hmacsha256\\,timestamp=1711006516632|\",\"TKSTM32&k08feePiGKj\",\"c840927a73749ecde4c2168b57b48d1e7e03227cae06740cde06e9d86bfaeace\",0,0,\"\"\r\n");
	TIM2_delayms(1000);
	
	USART3_SendString("AT+MQTTCONN=0,\"iot-06z00c92d8d4io8.mqtt.iothub.aliyuncs.com\",1883,1\r\n");
  TIM2_delayms(3000);
	
	USART3_SendString("AT+MQTTSUB=0,\"/k08feePiGKj/TKSTM32/user/button\",1\r\n");
	TIM2_delayms(1000);
	
}



