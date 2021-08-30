.text

	lui	$at, 0x1dbb
	ori	$t0, $at, 0x8050	# address for leds in $t0
	lui	$at, 0x2243
	ori	$t1, $at, 0x0030	# address for switches in $t1

	lw	$t2, 0($t0)		# load the value stored in leds to $t2
	nop
	andi	$t2, $t2, 0xff9f	# andi on leds

	lw	$t3, 0($t1)		# load value stored in switches address
	srl 	$t3, $t3, 0x4		# shift right on switches
	andi	$t3, $t3, 0x3		# andi on switches
	sll	$t3, $t3, 0x3		# sll on switches

	or	$t2, $t2, $t3		# or operation on leds and switches stored in leds
	sw	$t4, 0($t2)		# store result in $t4
	nop

