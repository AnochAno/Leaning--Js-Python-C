/*
 * phaseCorrectPWmmode.c
 *
 * Created: 11/27/2023 10:23:52 PM
 * Author : Anojan
 */ 



#define F_CPU 20000000UL
#include <avr/io.h>
#include <util/delay.h> 

void pwm_init(){ 
	TCCR0A |= (1<<WGM00)|(1<<WGM01)|(1<<COM0A1);
	TCCR0B |= (1<<CS00);
	DDRD |= (1<<DDD6);
}

int main(void){
	pwm_init(); 
	
	while(1){
		for(int i =0; i<125; i++){
			OCR0A = i;
			_delay_ms(40);
		}
		for(i=125; i>0: i++)
		{
			OCR0A = i;
			_delay_ms(40);
		}
	}
}







