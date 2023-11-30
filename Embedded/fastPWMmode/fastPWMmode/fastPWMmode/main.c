/* fastPWMmode.c
 * Created: 11/27/2023 9:36:09 PM
 * Author : Anojan_ET/2019/005*/

#define F_CPU 20000000UL
#include <avr/io.h>
#include <util/delay.h> 

void pwm_init(){ 
	TCCR0A |= (1<<WGM00) | (1<<WGM01) | (1<<COM0A1);
	TCCR0B |= (1<<CS02);
	DDRD |= (1<<PORTD6);
}

int main(void){
	pwm_init(); 
	
	while(1){
		OCR0A = 64;
		_delay_ms(1000);
		OCR0A = 128;
		_delay_ms(1000);
	}
}



