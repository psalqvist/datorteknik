.text
	addi	$a0, $0, 5	# sätt $a0 till fakultetvärde
	beq	$a0, $0, zero	# ifall $a0 är 0 sätter vi $v0 = 1 och avslutar
	nop
	add	$v0, $0, $a0	# initiera $v0 till $a0
	addi	$a0, $a0, -1	# dekrementera $a0
outer_loop:
	addi	$a0, $a0, -1	# dekrementera $a0 med 1 varje iteration i outer loop
	add	$a1, $0, $v0	# sätt $a1 till $v0, alltså värdet vi vill öka $v0 med i inner loop
	add	$at, $0, $a0	# sätt $at till $a0, at dekrementeras i inner loop
	beq	$a0, $0, stop_loop	# när $a0 når 0, terminera
	nop
inner_loop:
	add	$v0, $v0, $a1	# öka $v0 med $v0 + $a1
	addi	$at, $at, -1	# dekrementera $at i varje iteration
	beq	$at, $0, outer_loop	# när $at når 0, gå tillbaka till yttre loopen
	nop
	beq	$0, $0, inner_loop	# kör inre loopen ovillkorligt
	nop
zero:
	addi	$v0, $0, 1	# ifall $a0 = 0 sätt $v0 = 1
stop_loop:
	beq	$0, $0, stop_loop
	
