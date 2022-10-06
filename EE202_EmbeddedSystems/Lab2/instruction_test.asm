#include "p16f690.inc"
    
__config 0xFFF2
    
CODE	0x000
        
	movlw h'45'
        movlw h'00'
	
  	Loop	nop
	goto	Loop
	
	END
