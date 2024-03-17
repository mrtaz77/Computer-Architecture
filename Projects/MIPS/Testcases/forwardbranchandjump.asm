add $t1, $zero, $zero
addi $t2, $zero, 4
addi $t1, $t1, 4
beq $t1, $t2, L1
addi $t5, $zero, 12
L2: srl $t3, $t1, 1
sll $t5, $t3, 2
j end
L1: ori $t3, $zero, 15
j L2
addi $t3, $zero, 15 
end: