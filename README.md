# Computer-Architecture
A collection of the projects done under the computer architecture course of undergrad.

## Contents
* [Tools](#tools)
* [Contents](#contents)
* [Projects](#projects)

## Tools
1. Logisim(2.7.1), download [EXE](https://sourceforge.net/projects/circuit/files/2.7.x/2.7.1/) (Requires JRE 1.5.0) or [JAR](https://sourceforge.net/projects/circuit/files/2.7.x/2.7.1/logisim-generic-2.7.1.jar/download) (Works for JRE >= 1.5.0).
2. Atmel Studio 7.0 . Download [link](https://www.microchip.com/en-us/tools-resources/archives/avr-sam-mcus)
3. Proteus Version 8.15. Download [link](https://engineeringsoftware.net/electronics/proteus-8-15-full-crack/).

### Issue with 7400-lib.circ Logisim Library 
The originally downloaded [7400-lib.circ](/Projects/ALU/Circuits/7400-lib.circ) had a bug related to the IC-7483. The $C_{out}$ pin was an input pin instead of the desired output pin.This issue was solved using this [.circ](./Circuits/IC%207483.circ) file. Also some changes were made to the 7400-lib.circ file for the design.

## Contents
|Folder|[ALU](/Projects/ALU/)|[FPA](/Projects/FPA/)|[MIPS](/Projects/MIPS/)|
|-|-|-|-|
|Specification|[..](/Projects/ALU/CSE-306-Assignment-1-V1.pdf)|[..](/Projects/FPA/306_FP_Adder.pdf)|[..](/Projects/MIPS/CSE306_MIPS_July23.pdf)|
|Report|[..](/Projects/ALU/Report/A1_Group6.pdf)|[..](/Projects/FPA/Report/main.pdf)|[..](/Projects/MIPS/Report/MIPSreport.pdf)|
|Logisim Circuit|[..](/Projects/ALU/Circuits/final%20ALU.circ)|[..](/Projects/FPA/Circuits/FloatingPointAdder.circ)|[..](/Projects/MIPS/Circuits/MIPS.circ)|


## Projects
- [Arithmetic Logic Unit : ALU](#alu)
- [Floating Point Adder : FPA](#fpa)
- [Microprocessor without Interlocked Pipelined Stages : MIPS](#mips)

# ALU
![ALU img](/Projects/ALU/Images/hardware.jpg)

## Content
- [Circuit Design](#circuit-design)
- [Software Simulation using LOGISIM](#software-simulation-using-logisim)
- [Usefool Tools](#useful-tools)
	- Wire Counter
	- Tester (Credit to [aaniksahaa](https://github.com/aaniksahaa) for this amazing tester, I modified it to support file output)
- [ICs and symbols used](#ics-and-symbols-used)

## Circuit Design 
The original circuit had a bug which were fixed using this [file](/Projects/ALU/Fix.md). \
Also for the intuitions behind the design check [optimization](/Projects/ALU/Optimization.md)

### Software Simulation using LOGISIM

1. Make sure that the modified [7400-lib.circ](/Projects/ALU/Circuits/7400-lib.circ), the fixed [IC-7483](/Projects/ALU/Circuits/IC%207483.circ) and the [ALU](/Projects/ALU/Circuits/final%20ALU.circ) are in the same directory.
2. Open the [final ALU.circ](/Projects/ALU/Circuits/final%20ALU.circ) in logisim. A circuit similar to the following should open :-

![logisim_ALU](/Projects/ALU/Report/Util/main.png)

### Useful Tools
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
### Software Simulation using LOGISIM

1. Make sure all the files of this [folder](/Projects/FPA/Circuits/) are in the same directory.
2. Open the [FloatingPointAdder.circ](/Projects/FPA/Circuits/FloatingPointAdder.circ) in logisim. A circuit similar to the following should open :-

![logisim_FPA](/Projects/FPA/Report/Util/FPA.png)

