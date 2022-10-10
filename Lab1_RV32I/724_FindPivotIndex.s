.data
input: .word 1,7,3,6,5,6   #Input array
len:   .word 6             #Length
str:   .string "The answer is "
.text


main:
    lw   s1, len
    la   s2, input
    add  t0, zero,zero     #i=0
    add  t1, zero,zero     #Left sum
    add  t2, zero,s3       #Right sum
    add  s3, zero,s2       
sumLoop:
    lw   t3, 0(s3)         #nums[i]
    add  t2, t2,t3         #rightSum += nums[i]
    addi s3, s3, 4         #Pointer sheft
    addi t0, t0, 1         #i++
    blt  t0, s1, sumLoop

    add  t0, zero,zero     #i=0
    add  s3, zero,s2
findLoop:
    lw   t3, 0(s3)         #nums[i]
    sub  t2, t2, t3        #rightSum -= nums[i]
    beq  t1, t2, foundPI   #leftSum == rightSum
    add  t1, t2, t3        #leftSum += nums[i]
    addi t0, t0, 1         #i++
    blt  t0, s1, findLoop

    addi s4, zero, -1      #Not found
printAns:
    la a0, str             #String
    li a7, 4               #Print string
    ecall
    add a0, s4, zero       #Load answer
    li a7, 1               #Print answer
    ecall
    li a7, 10              #End program
    ecall

foundPI:
    add  s4, t0, zero
    j printAns
