addi $t1, $zero, 3		
addi $t2, $zero, 5		
add $t0, $t1, $t2 	
add $t3, $t0, $t2 		
addi $t4, $t3, 2		
sw $t1, 3($t2)			
sll $t1, $t1, 2			
subi $t3, $t3, 1       
beq $t1, $t3, label1	
j end                   
label1:
srl $t3, $t3, 1			
lw $t1, 2($t3)		
and $t0, $t1, $t3		
or $t2, $t0, $t4 		
j label2				
label3:
sw $t0, 0($sp)
subi $sp, $sp, 1
sw $t2, 0($sp)
subi $sp, $sp, 1
ori $t0, $t0, 5			
addi $sp, $sp, 1
lw $t0, 0($sp)
andi $t2, $t2, 6	
lw $t5, 2($t2)
sw $t5, 0($sp)
subi $sp, $sp, 1
addi $sp, $sp, 1
lw $t2, 0($sp)
nor $t2, $t2, $t2 		
addi $sp, $sp, 1
lw $t2, 0($sp)
j end					
label2:
bneq $t0, $t2, label4
subi $t0, $t0, 3       
label4:
j label3              
end: