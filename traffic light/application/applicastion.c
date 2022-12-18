/*
 * applicastion.c
 *
 * Created: 11/15/2022 3:49:56 PM
 *  Author: YousefElsayed
 */ 
#include "application.h"

#define  LED_CAR_PORT PORT_A
#define  LED_PED_PORT PORT_C
#define  BUTTON_1_PORT PORT_D
#define  BUTTON_1_PIN 2
#define  LED_CAR_G_PIN 2
#define  LED_CAR_Y_PIN 1
#define  LED_CAR_R_PIN 0
#define  LED_PED_G_PIN 2
#define  LED_PED_Y_PIN 1
#define  LED_PED_R_PIN 0


uint8_t carLED=0; 
uint8_t prevcarLED=1;
uint8_t normalmode = 1; 
void app_init(void){
	
	
	led_init(LED_CAR_PORT,LED_CAR_G_PIN);
	led_init(LED_CAR_PORT,LED_CAR_Y_PIN);
	led_init(LED_CAR_PORT,LED_CAR_R_PIN);
	
	
	led_init(LED_PED_PORT,LED_PED_G_PIN);
	led_init(LED_PED_PORT,LED_PED_Y_PIN);
	led_init(LED_PED_PORT,LED_PED_R_PIN);
	
	
	button_init(BUTTON_1_PORT,BUTTON_1_PIN);
	
	
	timer_init();
	
	
	sei();
	RISING_EDGE_SETUP();
	SETUP_INT0();
}
void app_start(void){
	
	uint8_t i;
	
	
	if(normalmode || carLED==0 || carLED==1){
		if(!normalmode){
			carLED=1;
		}
		
		led_off(LED_PED_PORT,LED_PED_G_PIN);
		led_off(LED_PED_PORT,LED_PED_Y_PIN);
		
		
		switch(carLED){
			
			case 0:
			led_on(LED_CAR_PORT,LED_CAR_G_PIN);
			led_off(LED_CAR_PORT,LED_CAR_Y_PIN);
			led_off(LED_CAR_PORT,LED_CAR_R_PIN);
			
			for(i=0;i<50;i++){
				timer_delay(68);
				if(!normalmode)break;
			}
			carLED=1;
			prevcarLED=0;
			break;
			
			case 1:
			
			
			if(!normalmode){
				if(prevcarLED!=2){
					led_on(LED_PED_PORT,LED_PED_R_PIN);
					
					for(i=0;i<5;i++){
						led_on(LED_CAR_PORT,LED_CAR_Y_PIN);
						led_on(LED_PED_PORT,LED_PED_Y_PIN);
						timer_delay(390);
						led_off(LED_CAR_PORT,LED_CAR_Y_PIN);
						led_off(LED_PED_PORT,LED_PED_Y_PIN);
						timer_delay(190);
						led_on(LED_CAR_PORT,LED_CAR_Y_PIN);
						led_on(LED_PED_PORT,LED_PED_Y_PIN);
						timer_delay(390);
					}
				}
				prevcarLED=1;
				carLED=2;
				led_on(LED_CAR_PORT,LED_CAR_R_PIN);
				}else{
				
				for(i=0;i<5;i++){
					led_on(LED_CAR_PORT,LED_CAR_Y_PIN);
					timer_delay(380);
					led_off(LED_CAR_PORT,LED_CAR_Y_PIN);
					timer_delay(180);
					led_on(LED_CAR_PORT,LED_CAR_Y_PIN);
					timer_delay(380);
					if(!normalmode){
						prevcarLED=1;
						break;
					}
				}
			}
			led_off(LED_CAR_PORT,LED_CAR_Y_PIN);
			led_off(LED_PED_PORT,LED_PED_Y_PIN);
			
			if(prevcarLED==0){
				carLED=2;
				prevcarLED=1;
				}else if(prevcarLED==2){
				carLED=0;
				prevcarLED=1;
			}
			break;
			
			case 2:
			led_off(LED_CAR_PORT,LED_CAR_G_PIN);
			led_off(LED_CAR_PORT,LED_CAR_Y_PIN);
			led_on(LED_CAR_PORT,LED_CAR_R_PIN);
			for(i=0;i<50;i++){
				timer_delay(68);
				if(!normalmode)break;
			}
			prevcarLED=2;
			carLED=1;
			break;
			default:
			carLED=2;
			prevcarLED=1;
			break;
		}
		
		}else{
		
		led_on(LED_PED_PORT,LED_PED_G_PIN);
		led_off(LED_PED_PORT,LED_PED_Y_PIN);
		led_off(LED_PED_PORT,LED_PED_R_PIN);
		
		
		led_off(LED_CAR_PORT,LED_CAR_G_PIN);
		led_off(LED_CAR_PORT,LED_CAR_Y_PIN);
		led_on(LED_CAR_PORT,LED_CAR_R_PIN);
		timer_delay(5000);
		
		
		led_off(LED_CAR_PORT,LED_CAR_R_PIN);
		
		
		for(i=0;i<5;i++){
			led_on(LED_CAR_PORT,LED_CAR_Y_PIN);
			led_on(LED_PED_PORT,LED_PED_Y_PIN);
			timer_delay(390);
			led_off(LED_CAR_PORT,LED_CAR_Y_PIN);
			led_off(LED_PED_PORT,LED_PED_Y_PIN);
			timer_delay(190);
			led_on(LED_CAR_PORT,LED_CAR_Y_PIN);
			led_on(LED_PED_PORT,LED_PED_Y_PIN);
			timer_delay(390);
		}
		
		led_off(LED_CAR_PORT,LED_CAR_Y_PIN);
		led_off(LED_PED_PORT,LED_PED_Y_PIN);
		
		led_on(LED_PED_PORT,LED_PED_R_PIN);
		
		normalmode=1;
		
		carLED=0;
		prevcarLED=1;
	}
	
}

ISR(EXT_INT_0){
	normalmode=0;
}