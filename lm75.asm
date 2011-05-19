.text
.code 32
  
.global	_start
_start:

/* select irq mode */
  mrs r0, cpsr
  bic r0, r0, #0x1F   /* clear mode flags */  
  orr r0, r0, #0xD2   /* set irq mode + DISABLE IRQ, FIQ*/
  msr cpsr, r0     

/* init irq stack */
  ldr sp,_Lirqstack_end

/* select System mode 
  CPSR[4:0]	Mode
  --------------
   10000	  User
   10001	  FIQ
   10010	  IRQ
   10011	  SVC
   10111	  Abort
   11011	  Undef
   11111	  System   
*/

  mrs r0, cpsr
  bic r0, r0, #0x1F   /* clear mode flags */  
  orr r0, r0, #0xDF   /* set system mode + DISABLE IRQ, FIQ*/
  msr cpsr, r0     
  
  /* init stack */
  ldr sp,_Lstack_end
                                   
  /* setup system clocks */
  bl clk_init

  /* enable I cache */
  bl enable_I_cache
  
.global _main
/* main program */
_main:
/* user code */

.equ TWI_BASE, 0xFFFAC000
.equ PMC_BASE, 0xFFFFFC00  /* (PMC) Base Address */

.equ PMC_PCER, 0x10
.equ TWI_CR, 0x00  
.equ TWI_MMR, 0x04  
.equ TWI_RHR, 0x30  
.equ TWI_SR, 0x20 
.equ TWI_CWGR, 0x10 

.equ PIOA_BASE, 0xFFFFF400
.equ PIO_PDR, 0x04
.equ PIO_MDER, 0x50
.equ PIO_ASR, 0x70


.equ PIOC_BASE, 0xFFFFF800
.equ PIO_SODR, 0x30
.equ PIO_CODR, 0x34

.equ DBGU_BASE,	0xFFFFF200
.equ DBGU_CR,	0x0000
.equ DBGU_MR,	0x0004
.equ DBGU_SR,	0x0014
.equ DBGU_RHR,	0x0018
.equ DBGU_THR,	0x001C
.equ DBGU_BRGR,	0x0020


  ldr r0, =DBGU_BASE
  mov r1, #0b1010000		/*mov r1, 0x101011100*/
  str r1, [r0, #DBGU_CR]
  mov r1, #0x800
  str r1, [r0, #DBGU_MR]
  mov r1, #0x1A
  str r1, [r0, #DBGU_BRGR]
                       
                       
  mov r4, #0x41
  bl debug_transmit             
                                

  ldr r0, =PMC_BASE
  mov r1,#1 << 11
  str r1,[r0,#PMC_PCER]

  ldr r0, =PIOA_BASE
  mov r1,#0b11 << 23
  str r1,[r0,#PIO_PDR]
  str r1,[r0,#PIO_MDER]
  str r1,[r0,#PIO_ASR]

  ldr r0,=TWI_BASE
  ldr r1,=0b11000000010000000
  str r1,[r0,#TWI_CWGR]
  mov r1,#0b100100
  str r1,[r0,#TWI_CR]

  mov r1,#0b1001111 << 16
  orr r1,r1,#1 << 12
  str r1,[r0,#TWI_MMR]

rep:
  mov r1,#1
  str r1,[r0,#TWI_CR]

wait1:
  ldr r1,[r0,#TWI_SR]
  ands r1,r1,#2
  beq wait1  

  ldr r1,[r0,#TWI_RHR]
  add r4,r1,#0
  bl debug_transmit   
  mov r4, #0x20
  bl debug_transmit   
  strb r1,hi
  

  mov r1,#2
  str r1,[r0,#TWI_CR]

wait2:
  ldr r1,[r0,#TWI_SR]
  ands r1,r1,#2
  beq wait2  

  ldr r1,[r0,#TWI_RHR]
  add r4,r1,#0
  bl debug_transmit   
  mov r4, #0x20
  bl debug_transmit   
  strb r1,lo
  

wait3:
  ldr r1,[r0,#TWI_SR]
  ands r1,r1,#1
  beq wait3 
  
  ldr r1,=100000000
dly:
  subs r1,r1,#1
  bne dly

  mov r4, #0x20
  bl debug_transmit   
  mov r4, #0x20
  bl debug_transmit   
  mov r4, #0x20
  bl debug_transmit   
  mov r4, #0x20
  bl debug_transmit   

  b rep

  mov r0,#0xA3
  bl  POSLJI
  b _wait_for_ever

debug_transmit:
  stmfd sp!, {r1 - r3 , lr}
  ldr r1, =DBGU_BASE
zanka_debug_transmit:
  ldr r2, [r1, #DBGU_SR]
  ands r2, r2, #2
  beq zanka_debug_transmit
  str r4, [r1, #DBGU_THR]
  ldmfd sp!, {r1 - r3 , pc}


POSLJI:	stmfd	sp!,{r1-r3,lr}
		ldr		r1,=PIOC_BASE
		mov		r2,#8
		mov		r3,#1
ZANKA:	str		r3,[r1,#PIO_SODR]
		bl		DELAY
		str		r3,[r1,#PIO_CODR]
		bl		DELAY
		tst		r0, #0x80
		blne		DELAY
		mov		r0,r0,lsl #1
		subs		r2,r2,#1
		bne		ZANKA
		ldmfd	sp!,{r1-r3,pc}

DELAY:  stmfd sp!,{lr}
        ldmfd sp!,{pc}  

/* end user code */

_wait_for_ever:
  b _wait_for_ever


/* variables here */

hi:   .space 1
lo:   .space 1
TABELA: .word 1,2,3,4,5,6,7,8,9,10
MIN: .space 4
MAX: .space 4

/* end variables */

  .align 2
_Lstack_end:
  .long __STACK_END__- 2*13*4  @ space for 26 registers on IRQ stack
_Lirqstack_end:
  .long __STACK_END__

.end

