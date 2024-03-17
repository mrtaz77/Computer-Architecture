add $t1, $zero, $zero
addi $t2, $zero, 4
L1: addi $t1, $t1, 1
beq $t1, $t2, L2
j L1
L2: srl $t3, $t2, 2
sll $t1, $t1, 1
L3: subi $t1, $t1, 1
bneq $t1, $zero, L3
add $t3, $t2, $t2
end: