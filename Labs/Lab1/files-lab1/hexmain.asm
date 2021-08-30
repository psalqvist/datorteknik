  # hexmain.asm
  # Written 2015-09-04 by F Lundevall
  # Copyright abandonded - this file is in the public domain.

	.text
main:
	li	$a0, 17	# change this to test different values
	
	jal	hexasc		# call hexasc
	nop			# delay slot filler (just in case)	

	move	$a0,$v0		# copy return value to argument register

	li	$v0,11		# syscall with v0 = 11 will print out
	syscall			# one byte from a0 to the Run I/O window
	
stop:	j	stop		# stop after one run
	nop			# delay slot filler (just in case)

  # You can write your own code for hexasc here
  #
hexasc:
	li	$t0, 9		# loads 9 into register t0
	
	andi	$a0, $a0, 0xF	# masks everything but the 4 least significant bits
	
	bgt	$a0, $t0, large	# branches of to label large if the argument is bigger than 9
	
	addi	$v0, $a0, 0x30	# if we don't fo to large, add 0x30 to the argument register. Gives correct ASCII 0-9
	
	j	hexend		# jump to hexend
	
large:
	addi	$v0, $a0, 0x37	# adds 0x37 to argument register. Gives correct ASCII 10-15
	
hexend:
	jr	$ra		# jump to return adress
	

