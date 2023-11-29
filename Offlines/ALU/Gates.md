# Gates
|IC|Function|Number OF ICs|Slots Used|Cost Explanation|
|-|-|-|-|-|
|74138|3 to 8 Decoder|1|Full|For mappings VF selection bits|
|7483|4 bit parallel adder|1|Full|For arithmetic operations|
|74157|Quad 2 to 1 MUX|3|Full|Multiplexing for (Bi'/C), (AND/OR), (Arithmetic/Logic)|
|7432|OR|1|4|3(ZF) + 1(Cin)|
|7486|XOR|2|8|4(A XOR B) + 3(VF) + 1(Complementing for ZF)|
|7404|NOT|1|6|4(NOT B) + 2(Cin)|
|7408|AND|2|8|4(A AND B) + 1(S2) + 2(S0) + 1(C)|
||__Total__|__11__|||

## Symbols
1. C -> Intermediate input needed for arithmetic operations
2. ZF -> Zero flag
3. Cin -> Input carry calculated from control bits
4. VF -> Overflow flag
5. S2 -> Selection bit for choosing Bi' or C in arithmetic operation
6. S0 -> Selection bit for choosing arithmetic or logical operations

## N.B.
The following symbols did not need any extra gates for implementation

1. S3 -> Selection bit for Ai or Ai'
2. S1 -> Selection bit for AND or XOR operation
3. SF -> Sign flag
4. CF -> Carry flag