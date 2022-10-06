#include "p16f690.inc"
    
__config 0xFFF2
    
CODE	0x000
        
        rrf h'30',w
	movwf h'31'
	
  	Loop	nop
	goto	Loop
	
	END
