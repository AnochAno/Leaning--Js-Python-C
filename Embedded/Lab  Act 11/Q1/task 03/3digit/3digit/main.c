#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


#define SSD1_CATHODE_PIN PD0
#define SSD2_CATHODE_PIN PD1
#define SSD3_CATHODE_PIN PD2

#define SSD_SEGMENT_PORT PORTC
#define SSD_SEGMENT_DDR DDRC

void init_ssd() {
	
	SSD_SEGMENT_DDR = 0xFF;
	DDRD |= (1 << SSD1_CATHODE_PIN) | (1 << SSD2_CATHODE_PIN) | (1 << SSD3_CATHODE_PIN);
}

void displayDigit(unsigned int digit, uint8_t ssd_cathode) {
	
	char seg[] = {0b0111111, 0b00000110, 0b1011011, 0b1001111, 0b1100110, 0b1101101, 0b1111101, 0b0000111, 0b1111111, 0b1101111};

	
	PORTD &= ~((1 << SSD1_CATHODE_PIN) | (1 << SSD2_CATHODE_PIN) | (1 << SSD3_CATHODE_PIN));

	
	PORTD |= (1 << ssd_cathode);

	SSD_SEGMENT_PORT = seg[digit];
}

int main(void) {
	init_ssd(); 

	while (1) {
		unsigned int number = 945;

		
		displayDigit(number % 10, SSD1_CATHODE_PIN);
		_delay_ms(5);

		displayDigit((number / 10) % 10, SSD2_CATHODE_PIN);
		_delay_ms(5);

		displayDigit(number / 100, SSD3_CATHODE_PIN);
		_delay_ms(5);
	}

	return 0;
}
