/*
 * RegisterFile.c
 */ 

#define D4 eS_PORTD4
#define D5 eS_PORTD5
#define D6 eS_PORTD6
#define D7 eS_PORTD7
#define RS eS_PORTC1
#define EN eS_PORTC0

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>
#include "lcd.h"
#include <stdlib.h>

unsigned char registers[16];
// $zero, $t0, $t1, $t2, $t3, $t4, $t5, $sp


int main(void)
{
    MCUCSR |= (1 << JTD);
	MCUCSR |= (1 << JTD);
	
	DDRA = 0xff;
	DDRB = 0x00;
	DDRC = 0x03;
	DDRD = 0xf0;
	
	for(int i = 0; i < 16; i++) {
		registers[i] = i;
	}
	registers[7] = 0x0f; // initialize stack pointer
	
	int current_clock = 0;
	int prev_clock = 0;
 	int register_write;
	 char result[8];
//	int show_reg;
//	int reset;
	
	Lcd4_Init();
	Lcd4_Set_Cursor(1, 1);
	// Lcd4_Write_String("hello");
	
    while (1) 
    {
		
		Lcd4_Set_Cursor(1, 1);
		int input_b = PINB;
		int read_address2 = (input_b >> 4); // b's upper nibble -> read_address2
		int reg_dest = (input_b & 0x0f);
		
		int input_d = PIND;
		int read_address1 = (input_d & 0x0f);
		
		int flag = PINC;
		prev_clock = current_clock;
		current_clock = ((flag & 0x04) >> 2);

		register_write = ((flag & 0x08) >> 3);

		int write_data = (flag >> 4);

		
		PORTA = (((registers[read_address2] & 0x0f) << 4) | (registers[read_address1] & 0x0f)) %256;
		if(prev_clock == 1 && current_clock == 0 && register_write) {
			
			registers[reg_dest] = write_data;
		}
		
		itoa(registers[0], result, 10);
		Lcd4_Write_String(result);
		Lcd4_Write_String(" ");
		itoa(registers[1], result, 10);
		Lcd4_Write_String(result);
		Lcd4_Write_String(" ");
		itoa(registers[2], result, 10);
		Lcd4_Write_String(result);
		Lcd4_Write_String(" ");
		itoa(registers[3], result, 10);
		Lcd4_Write_String(result);
		Lcd4_Write_String(" ");
		
		Lcd4_Set_Cursor(2, 1);
		itoa(registers[4], result, 10);
		Lcd4_Write_String(result);
		Lcd4_Write_String(" ");
		itoa(registers[5], result, 10);
		Lcd4_Write_String(result);
		Lcd4_Write_String(" ");
		itoa(registers[6], result, 10);
		Lcd4_Write_String(result);
		Lcd4_Write_String(" ");
		itoa(registers[7], result, 10);
		Lcd4_Write_String(result);
		Lcd4_Write_String(" ");

    }
}

