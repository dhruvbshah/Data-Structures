    .data
        endl:    .asciiz  "\n"   # used for cout << endl;
        albl:    .asciiz  "Value of a: " # label for a
        blbl:    .asciiz  "Value of b: " # label for b
        clbl:    .asciiz  "Value of c: " # label for c
        dlbl:    .asciiz  "Value of d: " # label for d
    .text

# a --> $s0
# b --> $s1
# c --> $s2
# d --> $s3
main:    

    li $s0, 5     #s0 = 5
    li $s1, 6     #s1 = 6
    li $s2, 7     #s2 = 7
    li $s3, -1    #s3 = -1

    bgt $s0, 10, test0  #if ( a < 10)
    addi $s0, $s0, 1    #a++
    j ifesle
test0:
    addi $s0, $s0, -1 # a--

ifesle:
    add $s3, $s0, $s2 # d = a + c
    add $s2, $s0, $s3 #c = a + d

    bgt $s1, 10, test1 #if ( b < 10)
    addi $s1, $s1, 1   #b++
    addi $s2, $s2, -1  #c--
    j ifelse0
test1:
    addi $s1, $s1, -1 # b--
    addi $s2, $s2, 1 # c++

ifelse0:
    add $s0, $s2, $s1 # a = c + b
    add $s1, $s2, $s3 # b = c + d

    bgt $s1, $s2, test3 #if ( b < c)
    blt $s1, $s0, test3 #if ( b > a)
    add $s3, $s0, $s1   # d = a + b
    j exit
test3:
    bgt $s1, $s2, test4 #if ( b > c)
    bgt $s2, $s0, exit #if ( c < a)
test4:
    add $s3, $s1, $s2 # d = b + c

	

exit:
    la   $a0, albl      # puts albl into arg0 (a0 register) for cout
    addi $v0, $0, 4     # puts 4 in v0 which denotes we are printing a string
    syscall             # make a syscall to system
    
    move $a0, $s0       # puts a into arg0 (a0 register) for cout
    addi $v0, $0, 1     # puts 1 in v0 to denote we are printing an int 
    syscall             # make a syscall to system

    la   $a0, endl      # puts the address of the string endl into a0
    addi $v0, $0, 4     # puts 4 into v0 saying we are printing a string
    syscall

    la   $a0, blbl      # puts blbl into arg0 (a0 register) for cout
    addi $v0, $0, 4     # puts 4 in v0 which denotes we are printing an string
    syscall             # make a syscall to system
    
    move $a0, $s1       # puts b into arg0 (a0 register) for cout
    addi $v0, $0, 1     # puts 1 in v0 to denote we are printing an int 
    syscall             # make a syscall to system

    la   $a0, endl      # puts the address of the string endl into a0
    addi $v0, $0, 4     # puts 4 into v0 saying we are printing a string
    syscall

    la   $a0, clbl      # puts clbl into arg0 (a0 register) for cout
    addi $v0, $0, 4     # puts 4 in v0 which denotes we are printing a string
    syscall             # make a syscall to system
    
    move $a0, $s2       # puts c into arg0 (a0 register) for cout
    addi $v0, $0, 1     # puts 1 in v0 to denote we are printing an int 
    syscall             # make a syscall to system

    la   $a0, endl      # puts the address of the string endl into a0
    addi $v0, $0, 4     # puts 4 into v0 saying we are printing a string
    syscall

    la   $a0, dlbl      # puts dlbl into arg0 (a0 register) for cout
    addi $v0, $0, 4     # puts 4 in v0 which denotes we are printing a string
    syscall             # make a syscall to system
    
    move $a0, $s3       # puts d into arg0 (a0 register) for cout
    addi $v0, $0, 1     # puts 1 in v0 to denote we are printing an int 
    syscall             # make a syscall to system

    la   $a0, endl      # puts the address of the string endl into a0
    addi $v0, $0, 4     # puts 4 into v0 saying we are printing a string
    syscall
   
    addi $v0,$0, 10
    syscall
