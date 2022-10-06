#include "p16f690.inc"
    
__config 0xFFF2
    
    CODE 0x0000

INPUT	    equ		h'20'
OUTPUT	    equ		h'21'
	    
START

bsf OUTPUT,7 ; set bit 7 in temp	   
btfss INPUT,0 ; if bit 0 in input = 1 skip 
bcf OUTPUT,7 ; clear bit 7 in temp 
	    
bsf OUTPUT,6 ; set bit 6 in temp		   
btfss INPUT,1 ; if bit 1 in input = 1 skip
bcf OUTPUT,6 ; clear bit 6 in temp 
	    
bsf OUTPUT,5 ; set bit 5 in temp	   
btfss INPUT,2 ; if bit 2 in input = 1 skip
bcf OUTPUT,5 ; clear bit 5 in temp 
	    
bsf OUTPUT,4 ; set bit 4 in temp		   
btfss INPUT,3 ; if bit 3 in input = 1 skip
bcf OUTPUT,4 ; clear bit 4 in temp 
	    
bsf OUTPUT,3 ; set bit 3 in temp		    
btfss INPUT,4 ; if bit 4 in input = 1 skip
bcf OUTPUT,3 ; clear bit 3 in temp 
	    
bsf OUTPUT,2 ; set bit 2 in temp		   
btfss INPUT,5 ; if bit 5 in input = 1 skip
bcf OUTPUT,2 ; clear bit 2 in temp 
	    
bsf OUTPUT,1 ; set bit 1 in temp		   
btfss INPUT,6 ; if bit 6 in input = 1 skip
bcf OUTPUT,1 ; clear bit 1 in temp --
	    
bsf OUTPUT,0 ; set bit 0 in temp		   
btfss INPUT,7 ; if bit 7 in input = 1 skip
bcf OUTPUT,0 ; clear bit 0 in temp  

Loop	goto	Loop
	
    END
