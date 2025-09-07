#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

void delay_ms(uint32_t time){
  uint32_t i,j;
	for(i=0; i < time; i++){
	    for( j=0; j < 8000 ; j++){
		}
	}
}
int main(void){
      GPIO_InitTypeDef GPIO_Config ;
	     // Bat xung clock cho port A và Port C 
	    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	    // Cau hinh cho cac PORT A và PORT C chân , kieu chan , toc do
	    // PORT A
	    GPIO_Config.GPIO_Pin = GPIO_Pin_0;
	    GPIO_Config.GPIO_Mode = GPIO_Mode_Out_PP;
	    GPIO_Config.GPIO_Speed = GPIO_Speed_2MHz;
	    GPIO_Init(GPIOA,&GPIO_Config);
      //PORT C	
      GPIO_Config.GPIO_Pin = GPIO_Pin_14 ;
      GPIO_Config.GPIO_Mode = GPIO_Mode_IPU;
      GPIO_Init(GPIOC,&GPIO_Config);
	    uint8_t LED = 0 ;
while(1)
{
		if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14 )== 0 ){
			// chông dôi phim
			delay_ms(20);
			if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14) == 0){
				LED =!LED;
				if(LED)
					GPIO_SetBits(GPIOA,GPIO_Pin_0);
				else
					GPIO_ResetBits(GPIOA,GPIO_Pin_0);
				// cho nha nut tranh bi doc lien tuc
				while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14) == 0 );
			}
		}
  }
}
