## TODO
Components we need as of now:\
[ ] 12 bit adder (25)\
[ ] 12 bit 1's complementer (25)\
[x] 1,2,4,8,16,arbitrary right shifter bit 32 bit inputs.(20->R)\
[ ] 1,2,4,8,16,arbitrary left shifter with 32 bit inputs. (30->L)\
[x] 20 to 32 bit extender and set 21st bit to 1. (27)\
[ ] 12 bit Comparator ? C Z ?(30)\
[ ] Input Processing
	- Select smaller and larger exponent
	- Select corresponding mantissa(32 bit)(30)\
[ ] Mantissa Processing(Input ExpDiff , ExpDiffFlag, 2 mantissa)(27)\
[ ] Sign Bit computation, 32 bit ALU ?(20)\
[ ] Normalizer
- add: carry check
	- 1 -> (shift right) + (exponent+1)
	- 0 -> (shift left)
- subtract: Find MSB left-shift + exponent-shift

8 ckt remaining.