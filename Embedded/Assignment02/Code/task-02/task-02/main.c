/*
 * Activity03 Task02.c
 *
 * 
 * Author : Anojan.T (ET/2019/005)
 */ 

#define F_CPU 2000000UL
#include <avr/io.h>
#include <util/delay.h>

void pwm_init(){
	TCCR0A |= (1<<WGM00) | (1<<WGM01) | (1<<COM0A1);
	TCCR0B |= (1<<CS02);
	DDRD |= (1<<DDD6);
}

int main (void){
	pwm_init();
	while(1){
		OCR0A = 77;
		_delay_ms(1000);
	}
}

