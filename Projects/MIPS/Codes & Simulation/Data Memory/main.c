/*
 * DataMemory.c
 *
 * Created: 2/7/2024 11:52:34 PM
 * Author : LENOVO
 */ 

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>

#define memRead 0b00010000
#define memWrite 0b00100000
#define memToReg 0b01000000
#define clk 0b10000000


int main(void)
{
	DDRA=0x00;
	//A3-A0->ALU_output, A7-A4->RegData
	DDRB=0b00001111;
	DDRD=0b11111111;
	 
    uint8_t Mem_Element[16];
	//zero->0000,t0->0001,t1->0010,t2->0011,t3->0100,t4->0101,t5->0110,sp->1111
	//uint8_t test=0b00001111;
	uint8_t current_data=0b00000000;
	uint8_t previous_data=0b00000000;
	
	uint8_t current_code=0b00000000;
	uint8_t previous_code=0b00000000;
	
	//uint8_t temp=0b00000000;
	
	
	
    while (1) 
    {
		current_code=PINB & 0b11110000;
		current_data=PINA;
		if(!(current_code & clk) && (previous_code & clk)){
			if(previous_code & memWrite){
				Mem_Element[previous_data & 0b00001111]=(previous_data >>4);
			}		
			_delay_ms(10);
		}
		if(current_code & memRead){
			PORTB=Mem_Element[current_data & 0b00001111];
		}
		/*if(!(current_code & memToReg)){
			PORTB=current_data & 0b00001111;
		}*/
		
		previous_data=current_data;
		previous_code=current_code;
    }
}


