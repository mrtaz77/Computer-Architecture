addi $t1, $zero, 3		; t1 = 3
addi $t2, $zero, 5		; t2 = 5
add $t0, $t1, $t2 		; t0 = 8
add $t3, $t0, $t2 		; t3 = 13
addi $t4, $t3, 2		; t4 = 15
sw $t1, 3($t2)			; mem[$t2+3] = mem[8] = 3
sll $t1, $t1, 2			; t1 = 12
subi $t3, $t3, 1        ; t3 = 12
beq $t1, $t3, label1	; t1 == t3, jump to label1... In case of relative addressing, you can use `beq $t1, $t3, 1`; i.e. (PC+2) + 1*(2)
j end                   ; jump to end; `j 29`
label1:
srl $t3, $t3, 1			; t3 = 6
lw $t1, 2($t3)			; t1 = mem[8] = 3
and $t0, $t1, $t3		; t0 = 3 AND 6 = 2
or $t2, $t0, $t4 		; t2 = 2 OR 15 = 15
j label2				; jump to label2; `j 26`
label3:
push $t0				; push 2
push $t2				; push 15 
ori $t0, $t0, 5			; t0 = 2 OR 5 = 7
pop $t0 				; t0 = 15
andi $t2, $t2, 6		; t2 = 15 AND 6 = 6
push 2($t2)             ; push mem[8] = 3
pop $t2					; t2 = 3
nor $t2, $t2, $t2 		; t2 = ~(3 OR 3) = 12
pop $t2                 ; t2 = 2
j end					; jump to end; `j 29`
label2:
bneq $t0, $t2, label4	; t0 = 2 != t2 = 15, jump to label4; `bneq $t0, $t2, 1`
subi $t0, $t0, 3        ; never gets executed
label4:
j label3                ; jump to label3; `j 16`
end: