#include "p16f690.inc"
    
__config 0xFFF2
    
    CODE 0x0000
	
START
	
; Copies value from File h'20' to File h'21'
	movf h'20',w
	movwf h'21'
	
; test if it clears the dc and c flags
	addlw h'99'
	
; Clears the carry and digit carry flag 
	bcf h'03',0
	bcf h'03',1	

; Gets complement of value in h'29' and stores in file h'2A' 
	comf h'29', w
	movwf h'2A'

; Initialises FSR with value h'2F'
	movlw h'2F'
	movwf h'04'
	
; Subtracts the value in mem location h'30' from the value in mem location h'31'
; stores result in mem location h'32'
	movf h'30',w
	subwf h'31',w
	movwf h'32' 

;Swap nibbles in file h'35'
	swapf h'35',f
	
; Add numbers in file h'3E' and h'3F' if carry is high store h'01' in file h'40'
; otherwise clear file h'40'
	bcf h'03',0
	bcf h'03',1	
	movf h'3E',w
	addwf h'3F',w
	movwf h'41'
	clrf h'40'
	btfsc STATUS,C
	incf h'40',f
	
; Set Port B to an input port then read the value from Port B and store value 
; in mem location h'45'
	bsf STATUS,RP0
	bcf STATUS,RP1
	movlw b'11111001'
	andwf TRISB,f
	
	bcf STATUS,RP0
	bcf STATUS,RP1
	movf PORTB, w
	movwf h'45'

; Multiply the number in File h'50' by four and store the result in file h'51'
	movf h'50',w
	addwf h'50',w
	addwf h'50',w
	addwf h'50',w
	movwf h'51'

; Decrement the contents in File h'5F' by one
	decf h'5F',f
	
Loop	goto	Loop
	
    END
