#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>


int main(void)
{
	DDRA=0XFF;
	DDRB=0x00;
	DDRC=0xFF;
	DDRD=0x00;
	
	MCUCSR|=(1<<JTD);
	MCUCSR|=(1<<JTD);
	
	unsigned char pc;
	int prevclk = 0;
	int currclk = 0;
	int reset =0;
	
	/* Replace with your application code */
	while (1) {
		prevclk = currclk;
		char b = PIND;
		currclk = ( b & 0b00000001);
		reset =    ( b & 0b00000010)>>1;
		
		
		if(reset==1){
			PORTA = 0x00;
		}
		else{
			if(prevclk==1 && currclk==0){
				pc = PINB;
				PORTA = pc;
			}
		}
	}
}
//PC Register