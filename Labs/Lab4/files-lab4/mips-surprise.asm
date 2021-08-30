.text
	addi	$a0, $0, 5	# sätt $a0 till fakultetvärde
	beq	$a0, $0, zero	# ifall $a0 är 0 sätter vi $v0 = 1 och avslutar
	nop
	add	$v0, $0, $a0	# initiera $v0 till $a0
	addi	$a0, $a0, -1	# dekrementera $a0 med 1 varje iteration i outer loop
outer_loop:
	beq	$a0, $0, stop_loop	# när $a0 når 0, terminera
	nop
	mul	$v0, $v0, $a0
	addi	$a0, $a0, -1	# dekrementera $a0 med 1 varje iteration i outer loop
	beq	$0, $0, outer_loop
	nop
zero:
	addi	$v0, $0, 1	# ifall $a0 = 0 sätt $v0 = 1
stop_loop:
	beq	$0, $0, stop_loop
	

