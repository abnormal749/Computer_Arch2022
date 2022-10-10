.data
input: .word 1,7,3,6,5,6   #Input array
len:   .word 6             #Length
str:   .string "The answer is "
.text


main:
    lw   s1, len
    add 


finishP:
    la a0, str             #string
    li a7, 4               #print string
    ecall
    add a0, s2, zero       #load answer
    li a7, 1               #print max
    ecall
    li a7, 10              #end program
    ecall
