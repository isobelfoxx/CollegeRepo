#include <xc.h>
#define _XTAL_FREQ 4000000 // 4Mhz
// Set config word
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
// TASK 1: Display tens value using PORTA, PORTB and PORTC
}
}
void displayNumber(int number) {
int units = number % 10;
displayUnits(units);
int tens = (int)(number / 10);
displayTens(tens);
}
volatile int eventCount = 0;
void interrupt isr() {
// TASK 3: Respond to interrupt
}
void main(void) {
TRISA = 0x04; // All outputs except for INT bit
TRISB = 0x00;
TRISC = 0x00;
ANSEL = 0x00; // Set Port C pins to digital
ANSELH = 0x00; // (they are analog by default)
// TASK 2: Perform initialisation
displayNumber(eventCount);
while(1) {
// Main program would go here
}
}
