# Given a DNA strand, return its RNA complement (per RNA transcription).
#
# Test transcribe_rna with some examples
#
# a0 - pointer to input string, for callee
# a1 - pointer to output string, for callee
# s0 - num of tests left to run
# s1 - address of input string
# s2 - address of expected output string
# s3 - char byte of input
# s4 - char byte of output
# s5 - counter for clearing output
#
# transcribe_rna must:
# - be named transcribe_rna and declared as global
# - read input address of string from a0
# - follow the convention of using the t0-9 registers for temporary storage
# - (if it uses s0-7 then it is responsible for pushing existing values to the stack then popping them back off before returning)
# - write a zero-terminated string representing the return value to address given in a1

.data

# number of test cases
n: .word 5
# input values and expected output values (all null terminated)
ins:  .asciiz "C", "G", "T", "A", "ACGTGGTCTTAA"
outs: .asciiz "G", "C", "A", "U", "UGCACCAGAAUU"

failmsg: .asciiz "failed for test input: "
expectedmsg: .asciiz ". expected "
tobemsg: .asciiz " to be "
okmsg: .asciiz "all tests passed"


.text

runner:
        lw      $s0, n
        la      $s1, ins
        la      $s2, outs

        li      $v0, 9                  # code for allocating heap memory
        li      $a0, 16                 # specify 16 bytes - length of longest expected output
        syscall
        move    $a1, $v0                # location of allocated memory is where callee writes result

run_test:
        jal     clear_output            # zero out output location
        move    $a0, $s1                # move address of input str to a0
        jal     transcribe_rna          # call subroutine under test
        move    $v1, $a1                # retain a copy of response from callee

scan:
        lb      $s3, 0($s2)             # load one byte of the expectation
        lb      $s4, 0($v1)             # load one byte of the actual
        bne     $s3, $s4, exit_fail     # if the two differ, the test has failed
        addi    $s2, $s2, 1             # point to next expectation byte
        addi    $v1, $v1, 1             # point to next actual byte
        addi    $s1, $s1, 1             # point to next input byte
        bne     $s3, $zero, scan        # if one char (and therefore the other) was not null, loop

done_scan:
        sub     $s0, $s0, 1             # decrement num of tests left to run
        bgt     $s0, $zero, run_test    # if more than zero tests to run, jump to run_test

exit_ok:
        la      $a0, okmsg              # put address of okmsg into a0
        li      $v0, 4                  # 4 is print string
        syscall

        li      $v0, 10                 # 10 is exit with zero status (clean exit)
        syscall

exit_fail:
        la      $a0, failmsg            # put address of failmsg into a0
        li      $v0, 4                  # 4 is print string
        syscall

        move    $a0, $s1                # print input that failed on
        li      $v0, 4
        syscall

        la      $a0, expectedmsg
        li      $v0, 4
        syscall

        move    $a0, $v1                # print actual that failed on
        li      $v0, 4
        syscall

        la      $a0, tobemsg
        li      $v0, 4
        syscall

        move    $a0, $s2                # print expected value that failed on
        li      $v0, 4
        syscall

        li      $a0, 1                  # set error code to 1
        li      $v0, 17                 # 17 is exit with error
        syscall

clear_output:
        sw      $zero, 0($a1)           # zero out output by storing 4 words (16 bytes) of zeros
        sw      $zero, 4($a1)
        sw      $zero, 8($a1)
        sw      $zero, 12($a1)
        jr      $ra

# # Include your implementation here if you wish to run this from the MARS GUI.

.text
.globl transcribe_rna
transcribe_rna:
    li $t0, 0
    li $t1, 0
    li $t2, 0
    li $t3, 0

    la $t3, ($a1)
    la $t1, ($a0)
    move $t2, $zero
    move $v0, $zero

loop:
    lbu $t0, ($a0)            # get character
    beq $t0, 'G', add_c
    beq $t0, 'C', add_g
    beq $t0, 'T', add_a
    beq $t0, 'A', add_u

jump:
    la $a0, ($t1)
    add $t1, $t1, 1           # increment $a0

    sb $t2, ($a1)

    #lb $a0, ($a1)
    #li $v0 11
    #syscall
    add $a1, $a1, 1
    bne $t0, $zero, loop

    la $a1, ($t3)
    la $v0, ($a1)
    jr $ra

# append to starting addr of $a1
add_c:
    li $t2, 'C'
    j jump
add_g:
    li $t2, 'G'
    j jump
add_a:
    li $t2, 'A'
    j jump
add_u:
    li $t2, 'U'
    j jump

