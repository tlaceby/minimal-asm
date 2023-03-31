.data
message: 
        .asciz "Sum of (%d + %d) = %d\n"  @ create label for message str
        .align 2
numbers:
        .word 61, 40                     @ create space for 2 numbers

.data
.globl main

main:
  stmfd sp!, {lr}
  ldr r1, =numbers     @ load first  number into r1
  ldr r2, [r1, #4]     @ load second number into r2
  add, r1, r1, r2

  ldr r0, =message     @ load result message string
  bl printf

exit:
  ldmfd sp!, {lr}
  mov r0, #0
  mov pc, lr
  .end