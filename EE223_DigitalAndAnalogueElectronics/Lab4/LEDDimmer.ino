Part 4.1 Code
// Fade in and out an LED 
int ledPin = 11;  // LED connected to digital pin 11 
void setup() {
 pinMode(ledPin, OUTPUT); // set up this pin as an output pin 
} 
void loop() {  

// fade in from low to high in steps of 5 
for(int i=0; i<256; i+=5) 
{ 
// sets the output value 
analogWrite(ledPin, i); // PWM write a value to the LED pin 
delay(50); //delay for 50ms 
} 

// fade out from high to low in steps of 5 
for(int i=255; i>=0; i-=5) { 
// sets the output value 
analogWrite(ledPin, i); // PWM write a value to the LED pin 
delay(50); //delay for 50ms 
}
}
