// Analog Read and Serial Write
int ldrPin = A0; // select the input pin A0 for the LDR input
int ldrValue = 0; // variable to store the value coming from the LDR
// Pin 11 has an LED connected on most Arduino boards.
// give it a name:
int led = 11 ;
void setup() {
// initialize the digital pin as an output.
pinMode(led, OUTPUT);
pinMode(ldrPin, INPUT); // Set up the pin as an input pin
Serial.begin(9600); // Set up the serial output at 9600 characters per second
}
void loop() {

// read the value from the LDR. This is a 10-bit ADC
// so there will be 2^10 values (1024), 0 to 1023.
ldrValue = analogRead(ldrPin);

// send to the serial output the value
Serial.print("LDR:"); // no 'ln' as I don't want a new line yet
Serial.println(ldrValue); // print out the LDR value

// delay for 1 second
delay(1000);

 digitalWrite(led, HIGH); // turn the LED on (HIGH is the voltage level)
 delay(500); // wait for a second
 digitalWrite(led, LOW); // turn the LED off by making the voltage LOW
 delay(500); // wait for a second
}
