#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
void delay_ms(uint32_t time){
	uint32_t i,j;
	for( i = 0; i < time ;i++){
		for ( j=0; j < 8000;j++){
		}
}
	}
int main (void){
	GPIO_InitTypeDef GPIO_Config ;
	// Bat clock cho Port A và Port B
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	// Cau hinh cho cac chan port A, A1,A2,A3 chân, kieu chan, toc do 
	GPIO_Config.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_Config.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Config.GPIO_Speed= GPIO_Speed_2MHz;
	GPIO_Init(GPIOA,&GPIO_Config);
	// Cau hinh cho chan port B, chan, kieu chan , toc do
	GPIO_Config.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_10;
	GPIO_Config.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Config.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB,&GPIO_Config);
	while(1){
		GPIO_SetBits(GPIOA,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 );
		GPIO_ResetBits(GPIOB,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_10);
		delay_ms(500);
		GPIO_ResetBits(GPIOA,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 );
		GPIO_SetBits(GPIOB,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_10);
		delay_ms(500);
	}
}