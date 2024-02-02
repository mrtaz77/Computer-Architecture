/*
 * Control Unit.c
 */ 

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>

inline void setALUOp(char aluOp) {
	// A7, A6 and A5
	PORTA &= ~(7 << 5) ; 
	PORTA |= (aluOp << 5);
}

inline void setBranch(char branch) {
	// A4
	PORTA &= ~(1 << 4) ;
	PORTA |= (branch << 4);
}

inline void setJump(char jump) {
	// A3
	PORTA &= ~(1 << 3) ;
	PORTA |= (jump << 3);
}

inline void setBneq(char bneq) {
	// A2
	PORTA &= ~(1 << 2) ;
	PORTA |= (bneq << 2);
}

inline void setMemtoReg(char memtoReg) {
	// A1
	PORTA &= ~(1 << 1) ;
	PORTA |= (memtoReg << 1);
}

inline void setMemRead(char memRead) {
	// A0
	PORTA &= ~(1) ;
	PORTA |= memRead;
}

inline void setMemWrite(char memWrite) {
	// D7
	PORTD &= ~(1 << 7) ;
	PORTD |= (memWrite << 7);
}

inline void setRegWrite(char regWrite) {
	// D6
	PORTD &= ~(1 << 6) ;
	PORTD |= (regWrite << 6);
}

inline void setRegDst(char regDst) {
	// D5
	PORTD &= ~(1 << 5) ;
	PORTD |= (regDst << 5);
}

inline void setALUSrc(char aluSrc) {
	// D4
	PORTD &= ~(1 << 4) ;
	PORTD |= (aluSrc << 4);
}

void assignControlToPorts(unsigned short control) {
	setALUSrc(control & 1);
	setRegDst((control >> 1) & 1);
	setRegWrite((control >> 2) & 1);
	setMemWrite((control >> 3) & 1);
	setMemRead((control >> 4) & 1);
	setMemtoReg((control >> 5) & 1);
	setBneq((control >> 6) & 1);
	setJump((control >> 7) & 1);
	setBranch((control >> 8) & 1);
	setALUOp((control >> 9) & 7);
}

void processOpcode() {
	uint8_t opcode = PIND & 0x0f;
	/*
	control is the bit mask consisting of all the control bits
	ALUOp(3 bits), 
	Branch , Jump , Bneq, 
	MemtoReg, MemRead, MemWrite, 
	RegWrite, RegDst, ALUSrc.
	It is used to set the output of the atmega32
	*/
	unsigned short control = 0;
	switch(opcode){
		case 0b0000:
			control = 0b011000000110; // and
		break;
		case 0b0001:
			control = 0b011000000101; // andi
		break;
		case 0b0010:
			control = 0b001100000000; // beq
		break;
		case 0b0011:
			control = 0b111010000000; // j
		break;
		case 0b0100:
			control = 0b001101000000; // bneq
		break;
		case 0b0101:
			control = 0b001000000110; // sub
		break;
		case 0b0110:
			control = 0b001000000101; // subi
		break;
		case 0b0111:
			control = 0b000000000101; // addi
		break;
		case 0b1000:
			control = 0b101000000101; // sll
		break;
		case 0b1001:
			control = 0b010000000110; // or
		break;
		case 0b1010:
			control = 0b000000000110; // add
		break;
		case 0b1011:
			control = 0b010000000101; // ori
		break;
		case 0b1100:
			control = 0b000000110101; // lw
		break;
		case 0b1101:
			control = 0b110000000101; // srl
		break;
		case 0b1110:
			control = 0b100000000110; // nor
		break;
		case 0b1111:
			control = 0b000000001001; // sw
		break;
	}
	assignControlToPorts(control);
}


int main(void)
{
    /* 
	configuring PORTD lower 4 bits for input,
	upper 4 bits and the entire PORTA as output
	*/
	DDRD = 0xf0;
	DDRA = 0xff;
    while (1) {
		processOpcode();
    }
}

