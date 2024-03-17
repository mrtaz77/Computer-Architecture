addi $t0, $zero, 13
subi $t1, $zero, -5
ori $t2, $t1, 6
andi $t4, $t2, 2
add $t3, $t2, $t4
sub $t4, $t1, $t3
nor $t2, $t1, $t3
or $t0, $t3, $t4
and $t1, $t1, $t2
srl $t2, $t3, 2
sll $t3, $t2, 2
end: