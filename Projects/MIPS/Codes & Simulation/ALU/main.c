/*
 * Alu.cpp
 *
 * Created: 2/9/2024 12:10:44 AM
 * Author : USER
 */ 
#define F_CPU 1000000
#include "inttypes.h"
#include <avr/io.h>
#include <util//delay.h>

unsigned char operation(unsigned char p, unsigned char q, char code) {
	unsigned char result;
	switch(code) {
		case 0: result = p + q; break;
		case 1: result = p - q; break;
		case 2: result = p | q; break;
		case 3: result = p & q; break;
		case 4: result = ~(p | q); break;
		case 5: result = p << q; break;
		case 6: result = p >> q; break;
		
		default:
		result = 0;
	}
	return result;
}


int main(void)
{
    /* Replace with your application code */
	
    volatile char opcode =0;
	volatile char zero_flag =0;
    volatile unsigned char  input1;
    volatile unsigned char input2;
	volatile unsigned char Branch ;
	volatile unsigned char Bneq  = 0x0; 
	volatile unsigned char result = 0x0;
	volatile unsigned char ben = 0x00;

	MCUCSR = (1<<JTD);
	MCUCSR = (1<<JTD);
	
	DDRA = 0b00000000;
	DDRC = 0b00000000;
	DDRB = 0b11111111;
	DDRD = 0b00000000;
	
	PORTB =  0x00;
	PORTD  = 0x00;
	
	//D3 -> Branch 
	//D4 -> BNEq
	
	//B4 -> BEN 
    while (1) 
    {   
		input1 = PINA ;
		input2 = PINC ;
		opcode = (PIND) & 7 ; //D2D1D0
		Branch = (PIND) & 0b00001000;// D3
		Bneq = (PIND) & 0b00010000;//D4
		result = operation(input1,input2,opcode);
		//PORTB = operation(input1,input2,opcode);
		
		if(result == 0){
			zero_flag = 1 ; 
		}
		else zero_flag =0;
		
		ben = (Branch>>3) &((Bneq>>4) ^ zero_flag); //B4
		
		result = result & 0b11101111;
		result |= (ben << 4);
		PORTB = result; 
    }
}