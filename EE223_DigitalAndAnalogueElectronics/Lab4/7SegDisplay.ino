// Analog Read and Serial Write
int ldrPin = A0; // select the input pin A0 for the LDR input
int ldrValue = 0; // variable to store the value coming from the LDR
int redledpin = 11; // Red LED connected to digital 9
int greenledpin = 10; // Green LED connected to digital 10
int redledvalue; // defines red led value
int greenledvalue; // defines green led value

// The 7-Segment Display Counter
// The Counting Programme - Counts 0-9 - DM. 

void setup() {
pinMode(redledpin, OUTPUT); // sets red LED pin as output
pinMode(greenledpin, OUTPUT); // sets green LED pin as output
pinMode(ldrPin, INPUT); // Set up the pin as an input pin
Serial.begin(9600); // Set up the serial output at 9600 characters per second
// need to set up 7 pins for our 7-segment display - all as output pins
for(int i=2; i<=8; i++){ 
// pins 2 to 8 (i.e. 7 pins)
pinMode(i, OUTPUT);
}
}

// This displays the number 0-9 by calling the displaySegment() function and telling it
// which segments to light for the number 0..9. This is not the most efficient way to do this
// but it is the easiest to understand. Just use this code.
// This lights up the segments a-g which have been wired 2-8
void displaySegment(int a, int b, int c, int d, int e, int f, int g){
digitalWrite(2,a);
digitalWrite(3,b);
digitalWrite(4,c);
digitalWrite(5,d);
digitalWrite(6,e);
digitalWrite(7,f);
digitalWrite(8,g);
}

// The loop() function will be called over-and-over, forever!
void loop() {
  
//read the value from the LDR. This is a 10-bit ADC 
//so there will be 2^10 values (1024), 0 to 1023.
ldrValue = analogRead(ldrPin);

//send to the serial output the value
Serial.print("LDR:"); // no 'ln' as I don't want a new line yet
Serial.println(ldrValue); // print out the LDR value

//delay for 1 second
delay(1000);

// sets the number on the display depending on how bright the room is.
// the bright the room the higher the number displayed and vice versa
// the brighter the room the darker the red led is set, the brighter the red led is set
if ( ldrValue > 900) {
redledvalue = 0;
displaySegment(1,1,1,1,0,1,1);
}
if ( ldrValue < 900 && ldrValue > 800) {
redledvalue = 30;
displaySegment(1,1,1,1,1,1,1);
}
if ( ldrValue < 800 && ldrValue > 700) {
displaySegment(1,1,1,0,0,0,0);
redledvalue = 60;
}
if ( ldrValue < 700 && ldrValue > 600) {
displaySegment(1,0,1,1,1,1,1);
redledvalue = 90;
}
if ( ldrValue < 600 && ldrValue > 500) {
displaySegment(1,0,1,1,0,1,1);
redledvalue = 120;
}
if ( ldrValue < 500 && ldrValue > 400) {
displaySegment(0,1,1,0,0,1,1);
redledvalue = 150;
}
if ( ldrValue < 400 && ldrValue > 300) {
displaySegment(1,1,1,1,0,0,1);
redledvalue = 180;
}
if ( ldrValue < 300 && ldrValue > 200) {
displaySegment(1,1,0,1,1,0,1);
redledvalue = 205;
}
if (ldrValue < 200 && ldrValue > 100) {
displaySegment(0,1,1,0,0,0,0);
redledvalue = 230;
}
if (ldrValue < 100) {
displaySegment(1,1,1,1,1,1,0);
redledvalue = 255;
}

Serial.print("Red LED:"); // no ln means no new line 
Serial.println(redledvalue); //prints out RedeledValue
analogWrite(redledpin, redledvalue); // PWM write a value to the LED pin

// sets Green LED to bright when room is bright and dims when the room is dark
greenledvalue = (ldrValue)/(36);//sets output value for green LED 
analogWrite(greenledpin, greenledvalue); // PWM write a value to the LED pin
Serial.print("Green LED:"); // Print Green LED: on same line the value
Serial.println(greenledvalue); //Print Green LED value
}
