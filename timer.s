    .file	"timer.c"
.text
	.align 2
	.global	timer_start
timer_start:
	MOV.W	&currentTime, R12
	MOV.W	R12, &startTime
	RET
	.global	timer_elapsed
timer_elapsed:
	MOV.W	&currentTime, R12
	MOV.B	#5, R13
	MOV.W	R12, R13
	MOV.W	&randSeed, R12
	ADD.W	R13, R12
	MOV.W	R12, &randSeed
	MOV.W	&currentTime, R12
	MOV.W	&startTime, R13
	SUB.W	R13, R12
	RET
	.align 2
	.global	WDT
WDT:

	PUSH	R15
	PUSH	R14
	PUSH	R13
	PUSH	R12
	PUSH	R11
	PUSH	R10
	PUSH	R9
	PUSH	R8
	PUSH	R7
	PUSH	R6
	PUSH	R5
	MOV.W	&stateTime, R12
	ADD.W	#1, R12
	MOV.W	R12, &stateTime
	MOV.W	&currentTime, R12
	ADD.W	#1, R12
	MOV.W	R12, &currentTime
	MOV.W	&randSeed, R12
	ADD.W	#1, R12
	MOV.W	R12, &randSeed
	MOV.W	&stateTime, R13
	MOV.W	&stateTransition, R12
	CMP.W	R12, R13
	MOV.W	#0, &stateTime
	MOV.W	&randSeed, R12
	ADD.W	#5, R12
	MOV.W	R12, &randSeed
	CALL	#state_update
	POP	R5
	POP	R6
	POP	R7
	POP	R8
	POP	R9
	POP	R10
	POP	R11
	POP	R12
	POP	R13
	POP	R14
	POP	R15
	RETI
	.align 2
	.global	timer_set_state_transition
timer_set_state_transition:
	SUB.W	#2, R1
	MOV.W	R12, R1
	MOV.W	R1, &stateTransition
	ADD.W	#2, R1
	RET
	timer_set_state_transition
	.global	prand
prand:
	MOV.W  &randSeed, R12
	RET
