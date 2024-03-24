# Computer-Architecture
A collection of the projects done under the computer architecture course of undergrad.

## Navigation
* [Tools](#tools)
* [Projects](#projects)
* [Contents](#contents)

## Tools
1. Logisim(2.7.1), download [EXE](https://sourceforge.net/projects/circuit/files/2.7.x/2.7.1/) (Requires JRE 1.5.0) or [JAR](https://sourceforge.net/projects/circuit/files/2.7.x/2.7.1/logisim-generic-2.7.1.jar/download) (Works for JRE >= 1.5.0).  _Open .circ files using this._
2. Atmel Studio 7.0 . Download [link](https://www.microchip.com/en-us/tools-resources/archives/avr-sam-mcus)
3. Proteus Version 8.15. Download [link](https://engineeringsoftware.net/electronics/proteus-8-15-full-crack/). _Open .pdsprj files using this._
4. Extreme burner. Download [link](https://extreme-burner-avr.software.informer.com/1.4/). _For burning hex files into atmega32 for hardware simulation_

### Issue with 7400-lib.circ Logisim Library 
The originally downloaded [7400-lib.circ](/Projects/ALU/Circuits/7400-lib.circ) had a bug related to the IC-7483. The $C_{out}$ pin was an input pin instead of the desired output pin.This issue was solved using this [.circ](./Circuits/IC%207483.circ) file. Also some changes were made to the 7400-lib.circ file for the design.

## Projects
- [Arithmetic Logic Unit : ALU](#alu)
- [Floating Point Adder : FPA](#fpa)
- [Microprocessor without Interlocked Pipelined Stages : MIPS](#mips)

## Contents
|Folder|[ALU](/Projects/ALU/)|[FPA](/Projects/FPA/)|[MIPS](/Projects/MIPS/)|
|-|-|-|-|
|Specification|[..](/Projects/ALU/CSE-306-Assignment-1-V1.pdf)|[..](/Projects/FPA/306_FP_Adder.pdf)|[..](/Projects/MIPS/CSE306_MIPS_July23.pdf)|
|Report|[..](/Projects/ALU/Report/A1_Group6.pdf)|[..](/Projects/FPA/Report/main.pdf)|[..](/Projects/MIPS/Report/MIPSreport.pdf)|
|Logisim Circuit|[..](/Projects/ALU/Circuits/final%20ALU.circ)|[..](/Projects/FPA/Circuits/FloatingPointAdder.circ)|[..](/Projects/MIPS/Circuits/MIPS.circ)|

# ALU
![ALU img](/Projects/ALU/Images/hardware.jpg)

## Content
- [Circuit Design](#circuit-design)
- [Software Simulation](#software-simulation-alu)
- [Usefool Tools](#useful-tools)
	- Wire Counter
	- Tester (Credit to [aaniksahaa](https://github.com/aaniksahaa) for this amazing tester, I modified it to support file output)
- [ICs and symbols used](#ics-and-symbols-used)

## Circuit Design 
The original circuit had a bug which were fixed using this [file](/Projects/ALU/Fix.md). \
Also for the intuitions behind the design check [optimization](/Projects/ALU/Optimization.md)

## Software Simulation ALU
![logisim_ALU](/Projects/ALU/Report/Util/main.png)

## Useful Tools
- [Wire Counter](/Projects/ALU/wireCount.py) calculates the number of wires used in a .circ file. 
	- Make sure that your.circ file(whose wire is to be counted) and the wireCount.py are in the same directory.
	- Replace the file_path with the name of `your.circ` and run the .py.
	- An estimate will be given.

- [Tester](/Projects/ALU/Tester/check_ALU.py) checks whether the truth table generated from the ALU.circ is correct or not.
	* Open the circuit in Logisim
	* Go to the `Project` tab and click `Analyze Circuit`
	* A warning dialog box may appear, click `OK`
	* The truth table is shown.
	* Press `Ctrl`+`A`. Copy.
	* Paste the output here in `truth_table.txt`
	* **Most importantly, in the code, change the check_row function's following fragment as per your specifications.**
	```cpp
	if(control == 0):
        Y = A + 2**n_bits - 1
    if(control == 1):
        Y = A + 2**n_bits - B - 1
    if(control == 2):
        Y = A + 2**n_bits - 1
    if(control == 3):
        Y = 2**n_bits - A // negation
    if(control == 4):
        Y = A + 2**n_bits - B
    if(control == 5):
        Y = A & B
    if(control == 6):
        Y = A ^ B
    if(control == 7):
        Y = A ^ B
	```
	* Run `check_ALU.py`
	* For the entire report, check the generated `report.txt`.


	The followed naming convention:

		Control bits = cs0, cs1, cs2
		A            = A0, A1 etc
		B            = B0, B1 etc
		S            = S0, S1 etc
		Cout         = Cout
		C, V, S and Z are the status flags

### ICs and symbols used
[Here](/Projects/ALU/Gates.md) is a list of ICs, symbols and their meanings used in the ALU.

# FPA
### Software Simulation FPA

![logisim_FPA](/Projects/FPA/Report/Util/FPA.png)

# MIPS

![mips_hardware](/Projects/MIPS/Report/Images/hardware.jpg)

- [Software Simulation](#software-simulation-mips)
- [Asm Compiler](/Projects/MIPS/Compiler/asm_compiler.py)
- [How to run](#how-to-run)

## Software Simulation MIPS
### Logisim
![logisim_MIPS](/Projects/MIPS/Report/Images/Main%20circuit.png)
### Proteus
![proteus_MIPS](/Projects/MIPS/Report/Images/mips_proteus.png)

## How to run
1. Go to the [Compiler](/Projects/MIPS/Compiler/) directory and open a .asm file with the desired mips assembly code.
2. Run the [asm_compiler.py](/Projects/MIPS/Compiler/asm_compiler.py).
```
python asm_compiler.py <input>.asm
```
3. The following files will be formed. \
	**intermediate.asm** - Asm file with intermediate code for push and pop instructions.\
	**log.txt** - Log file for the resulting hex code of all instructions and any error if found. \
	**instruction.hex** - Hex code for instruction memory for logisim simulation. \
	**atmega32_instruction.txt** - Hex code for instruction memory for atmega32 simulations used in proteus and hardware design.
4. **Proteus and hardware simulation**
	- Copy the `atmega32_instruction.txt`.
	- Open the [main.c](/Projects/MIPS/Codes%20&%20Simulation/Instruction%20Memory/main.c) in atmel studio and navigate to the **unsigned int instruction[256]** array. This is the instruction memory of our mips. Paste the instructions copied as R.H.S of this array.
	- Build the solution and a new hex file will be formed.
		- For hardware simulation, burn this hex file into the atmega32 simulating the instruction memory using extreme burner.
		- For proteus simulation, open the [circuit](/Projects/MIPS/Codes%20&%20Simulation/MIPS%20circuit.pdsprj) using proteus. Go to the atmega32 with the name **Instruction Memory** and load the hex file formed into it.
	- **Clock is negative edge triggered**. Execute next instruction via clock. Also, supports a reset switch for reseting program counter.
5. **Logisim simulation**
	- Open the [circuit](/Projects/MIPS/Circuits/MIPS.circ) in logisim and follow the video to load the instruction.hex into intruction memory.\
	https://github.com/mrtaz77/Computer-Architecture/assets/113765142/7c402a1f-811e-405a-8117-ec8926907b31
	