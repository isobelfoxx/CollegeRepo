#include pl6f690.inc
    
__config 0xFFF2
    
    CODE 0x000
   
START 
   
    movlw  h'78'
    addlw  h'89'
    movwf  h'20'
    clrw 
    goto  START
   
    END
