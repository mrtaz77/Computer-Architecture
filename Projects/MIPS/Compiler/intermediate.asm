sw $t3, 0($sp)
subi $sp, $sp, 1
addi $sp, $sp, 1
lw $t3, 0($sp)
lw $t5, 3($t3)
sw $t5, 0($sp)
subi $sp, $sp, 1
end: