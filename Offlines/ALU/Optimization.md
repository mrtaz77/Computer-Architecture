# IC Ckt Optimization

## 2nd Optimization
The first optimization was done while implementing C.
Here is the _second_ optimization:

Although we have 
$$C_\text{in} = \overline{D_\text{4} \cdot D_\text{3} }$$

After much speculation and analysis done by me, I found that extra ICs would be needed to implement the above operation. So, I decided to use **De Morgan's law** and got

$$C_\text{in} = \overline{D_\text{4}} + \overline{D_\text{3} }$$

This could be done by the vacant slots in the remaining ICs. Thus , optimizing the circuit.

# 3rd Optimization
I originally decided to use a hex inverter for getting Ai' and use a MUX to select between Ai and Ai'.

But I am dumb :sob:

Why use a multiplexer and inverter when you can just use a `XOR` gate ?

So in the new circuit, I xored Ai with a selection bit(S3) such that I get Ai when the other input is 0 and Ai' when the other input is 1.

For this , the new equation of S3 :

$$S_\text{3} = \overline{D_\text{3}}$$

which we already obtained from one slot of a not gate gate.
With that we don't need one MUX anymore.

Also, we orginally used that `hex inverter` for complemeting 2 bits of Bi. After previous optimization, we had 2 slots left in one of the two not gates.

So, we can use those slots and save an IC for NOT gate.

So, new gate count = 13 - 2 = 11.

Here is the [latest](/Offlines/ALU/Gates.md) IC table.