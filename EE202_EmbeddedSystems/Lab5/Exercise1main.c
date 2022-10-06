#include <xc.h>
#define _XTAL_FREQ 4000000 // 4Mhz
#pragma config FOSC=INTRCIO, WDTE=OFF, PWRTE=OFF, MCLRE=ON, \
CP=OFF, CPD=OFF, BOREN=OFF, IESO=OFF, FCMEN=OFF
void displayUnits(int units) {
switch(units) {
case 0: PORTC=0b00111111; break;
case 1: PORTC=0b00000110; break;
case 2: PORTC=0b01011011; break;
case 3: PORTC=0b01001111; break;
case 4: PORTC=0b01100110; break;
case 5: PORTC=0b01101101; break;
case 6: PORTC=0b01111101; break;
case 7: PORTC=0b00000111; break;
case 8: PORTC=0b01111111; break;
case 9: PORTC=0b01101111; break;
}
}
void displayTens(int tens) {
switch(tens) {  
// Task 1: Display tens value using PORTA, PORTB and PORTC
case 0: 
    PORTA = 0b00110000;
    PORTB = 0b11110000;
    RC7 = 0; 
    break;
case 1:
    PORTA = 0b00100000;
    PORTB = 0b00010000;
    RC7 = 0; 
    break;
case 2: 
    PORTA = 0b00110000;
    PORTB = 0b01100000;
    RC7 = 1; 
    break;
case 3: 
    PORTA = 0b00110000;
    PORTB = 0b00110000;
    RC7 = 1; 
    break;
case 4:
    PORTA = 0b00100000;
    PORTB = 0b10010000;
    RC7 = 1; 
    break;
case 5: 
    PORTA = 0b00010000;
    PORTB = 0b10110000;
    RC7 = 1; 
    break;
case 6:
    PORTA = 0b00010000;
    PORTB = 0b11110000;
    RC7 = 1; 
    break;
case 7: 
    PORTA = 0b00110000;
    PORTB = 0b00010000;
    RC7 = 0; 
    break;
case 8: 
    PORTA = 0b00110000;
    PORTB = 0b11110000;
    RC7 = 1; 
    break;
case 9: 
    PORTA = 0b00110000;
    PORTB = 0b10110000;
    RC7 = 1; 
    break;
}
}
void displayNumber(int number) {
int units = number % 10;
displayUnits(units);
int tens = (int)(number / 10);
displayTens(tens);
}
void main(void) {
// Task 2: Configure the ports
    TRISA = 0;
    TRISB = 0;
    TRISC = 0;
    ANSEL = 0;
    ANSELH = 0;
    TRISAbits.TRISA2 = 1;
    ANSELbits.ANS2 = 1;
// Task 3: Initialise the AD converter
    ADCON0bits.ADFM = 1;
    ADCON0bits.VCFG = 0;
    ADCON1bits.ADCS = 0b001;
    ADCON0bits.CHS = 2;
    ADCON0bits.ADON = 1;
while(1){
// Task 4: Carry out conversion and update display
    __delay_ms(100);
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO == 1);
    
    int result = ((ADRESH << 8)+ ADRESL);
    float conversion1 = (5.05/1023);
    float conversion2 = conversion1/0.01;
    int vANS2 = result*conversion2;
   
    displayNumber(vANS2);  
}
}
