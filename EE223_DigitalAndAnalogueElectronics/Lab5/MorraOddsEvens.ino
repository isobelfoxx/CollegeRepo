 // setting the dice LED [ins on the Arduino
int pinLeds1 = A4;
int pinLeds2 = A2;
int pinLeds3 = A3;
int pinLed4 = A1;
// setting the green and red LED on the Arduino
int greenledpin = 10;
int redledpin = 9;
// setting the roll dice pin button on the Arduino
int rollbuttonPin = A0;
// declaring the state of the dice button and the whether its odd or even
int rollbuttonState;
int rolldicechoice = 2;
// setting the odd button pin on the Arduino
int oddbuttonPin = 12;
// declaring the state of the odd and even buttons 
int evenbuttonState;
int oddbuttonState;
int oddorevenchoice = 3;
// setting the even button pin on the Arduino
int evenbuttonPin = 13;
// declaring dice
long dice;
int dicevalue;
int time = 2000; // setting time to 2 seconds
int repeat; // declaring repeat
 
// the stepup routine, only runs once
void setup () 
{
    //initialising the pins as either output or input
    pinMode (pinLeds1, OUTPUT);  
    pinMode (pinLeds2, OUTPUT);
    pinMode (pinLeds3, OUTPUT);
    pinMode (pinLed4, OUTPUT);
    pinMode (rollbuttonPin, INPUT); 
    pinMode (oddbuttonPin, INPUT);  
    pinMode (evenbuttonPin, INPUT);  
    pinMode (greenledpin, OUTPUT);  
    pinMode (redledpin, INPUT);  
    randomSeed (analogRead (5)); 
 
    // sets up 7 pins for our 7-segment display - all as output pins
    for (int i = 2; i <= 8; i++)
    { // pins 2 to 8 (i.e. 7 pins)
         pinMode (i, OUTPUT);    
    } 
    
    // count from 0 to 5 since there are 4 letters
    for (int i = 0; i <= 5; i++)
    {     
        display (i);    // display "play" once
        delay (750);    // wait 0.75 of a second between each count
    } 
} // end of set up
 

// displays the words "play" on the 7-seg display
void display (int letter)
{
    switch (letter)
    {  // displays "play"
      
        case 0:
        //displays "P"
        displaySegment (1, 1, 0, 0, 1, 1, 1);      
        break;
    
        case 1:
        // displays "L"
        displaySegment (0, 0, 0, 1, 1, 1, 0);      
        break;
    
        case 2:
        // displays "A"
        displaySegment (1, 1, 1, 0, 1, 1, 1);  
        break;
    
        case 3:
        // displays "Y"
        displaySegment (0, 1, 1, 1, 0, 1, 1);      
        break;
    
        case 4:
        // displays nothing
        displaySegment (0, 0, 0, 0, 0, 0, 0);   
        break;   
    }
} // end of display


// This lights up the segments a-g which have been wired 2-8
void displaySegment (int a, int b, int c, int d, int e, int f, int g)
{
    digitalWrite (2, a);
    digitalWrite (3, b);  
    digitalWrite (4, c);  
    digitalWrite (5, d);  
    digitalWrite (6, e);      
    digitalWrite (7, f); 
    digitalWrite (8, g);
}  // end of displaysegment
 
void loop () 
{
    // defining roll dice button state 
    rollbuttonState = digitalRead (rollbuttonPin);
   
    // if the button is presssed
    if (rollbuttonState == HIGH)
    {      
        // picks random numbers for dice
        dice = random (1, 6 );
      
        // if dice is 1 lights up the corresponding LEDs
        if (dice == 1)
        {   
            digitalWrite (pinLed4, HIGH); // lights LED up
            delay (time); // waits two seconds
    
            rolldicechoice = 1; // sets roll dice choice to even
    
            // checks if the number rolled by the dice matches the entry
            //from user if it does light the green led up to signal correct
            if (oddorevenchoice == rolldicechoice)
            {        
                digitalWrite (greenledpin, HIGH); // turns green led on
                delay (2000); //delays for 2 seconds
                digitalWrite (greenledpin, LOW);  // turns green led on
            }
    
            else
            {
                 // if they aren't equal lights red led up
                 digitalWrite (redledpin, HIGH); // turns red led on
                 delay (2000); //delays for 2 seconds
                 digitalWrite (redledpin, LOW);  // turns red led off
             }
    
             // resets the variables represnting the dice number 
             //(whether its odd or even) and the users input (whether odd or even)
             oddorevenchoice = 3;
             rolldicechoice = 2; 
    }
      
    // if dice is roll lights 2 LEDS
    if (dice == 2)
    {    
        digitalWrite (pinLeds1, HIGH); // lights LEDs  
        delay (time); // delays 2 seconds
    
        rolldicechoice = 0; // sets roll dice choice to even
    
        // checks if the number rolled by the dice matches the entry
        //from user if it does light the green led up to signal correct
        if (oddorevenchoice == rolldicechoice)
      
        {        
        digitalWrite (greenledpin, HIGH); // turns green led on
        delay (2000); // waits 2 seconds
        digitalWrite (greenledpin, LOW);  // turns green led on
        }
    
        else
        {        
            digitalWrite (redledpin, HIGH); // turns red led on
            delay (2000); // waits 2 seconds
            digitalWrite (redledpin, LOW);  // turns red led off
        }
    
        // resets variables representing whether the dice number is
        // odds or even and if the user choose odds or evens
        oddorevenchoice = 3;    
        rolldicechoice = 2;  
    }
      
        // if dice 3 is roll lights 3 leds
        if (dice == 3)
        {    
            // lights LED up
            digitalWrite (pinLeds3, HIGH);    
            digitalWrite (pinLed4, HIGH);    
            delay (time); // waits for 2 seconds
    
            rolldicechoice = 1; // sets roll dice choice to 3
    
            // checks if the number rolled by the dice matches the entry
            //from user if it does light the green led up to signal correct
            if (oddorevenchoice == rolldicechoice)     
            {       
                digitalWrite (greenledpin, HIGH); // turns green led on
                delay (2000);   // waits for 2 seconds
                digitalWrite (greenledpin, LOW);  // turns red led off
            }
    
        else     
        {       
            digitalWrite (redledpin, HIGH); // turns green led on
            delay (2000); // waits for 2 seconds
            digitalWrite (redledpin, LOW);  // turns red led off
        }
    
        // resets variables representing whether the dice number is
        // odds or even and if the user choose odds or evens
        oddorevenchoice = 3;    
        rolldicechoice = 2;  
    }
      
    // if dice equal to 4 then lights 4 LEDS
    if (dice == 4)
        {  
            // lights LEDs
            digitalWrite (pinLeds1, HIGH);    
            digitalWrite (pinLeds3, HIGH);    
            delay (time); // waits 2 seconds
               
            rolldicechoice = 0; // sets roll dice choice to even
    
            // checks if the number rolled by the dice matches the entry
            //from user if it does light the green led up to signal correct
            if (oddorevenchoice == rolldicechoice)
            {
                digitalWrite (greenledpin, HIGH); // lights green led
                delay (2000); // waits 2 seconds // waits 2 seconds
                digitalWrite (greenledpin, LOW);  // turns green led off
            }

            else
            {
                digitalWrite (redledpin, HIGH); // lights red led
                delay (2000); // waits for 2 seconds
                digitalWrite (redledpin, LOW);  // turns red led off
            }
    
              // resets variables representing whether the dice number is
              // odds or even and if the user choose odds or evens
              oddorevenchoice = 3;    
              rolldicechoice = 2;
    }
      
    // if dice equal to 5 lights 5 LEDs
    if (dice == 5)
    {
        //lights the LEDs    
        digitalWrite (pinLeds1, HIGH);
        digitalWrite (pinLeds3, HIGH);    
        digitalWrite (pinLed4, HIGH);   
        delay (time); // waits for 2 seconds
    
        rolldicechoice = 1; // sets roll dice choice to odd
    
        // checks if the number rolled by the dice matches the entry
        //from user if it does light the green led up to signal correct
        if (oddorevenchoice == rolldicechoice)
        {
            digitalWrite (greenledpin, HIGH); // lights green led
            delay (2000); // waits for 2 seconds
            digitalWrite (greenledpin, LOW);  // turns off green led 
        }
      
        else     
        {      
            digitalWrite (redledpin, HIGH); // lights red led
            delay (2000); // waits for 2 seconds       
            digitalWrite (redledpin, LOW);  // turns red led off
        }
    
        // resets variables representing whether the dice number is
        // odds or even and if the user choose odds or evens
        oddorevenchoice = 3;  
        rolldicechoice = 2;  
    }
      
    // if dice is 6 lights 6 LEDS
    if (dice == 6)
    {  
        // lights teh LEDs up
        digitalWrite (pinLeds1, HIGH);
        digitalWrite (pinLeds2, HIGH);    
        digitalWrite (pinLeds3, HIGH); 
        // waits 2 seconds   
        delay (time);
    
        rolldicechoice = 0; // sets to even
    
        // checks if the number rolled by the dice matches the entry
        //from user if it does light the green led up to signal correct
        if (oddorevenchoice == rolldicechoice)      
        {        
            digitalWrite (greenledpin, HIGH); // turns green led on
            delay (2000); // waits for 2 seconds     
            digitalWrite (greenledpin, LOW);  // turns off green led
        }
    
        else
        {        
           digitalWrite (redledpin, HIGH); // turns red led on
           delay (2000); // waits for 2 seconds
           digitalWrite (redledpin, LOW);  // turns off red led
        }
    
        // resets variables representing whether the dice number is
        // odds or even and if the user choose odds or evens
        oddorevenchoice = 3;  
        rolldicechoice = 2;  
        }
    
    }
  
    // turns off all LEDS
    digitalWrite (pinLeds1, LOW);  
    digitalWrite (pinLeds2, LOW);  
    digitalWrite (pinLeds3, LOW);  
    digitalWrite (pinLed4, LOW);
  
 
    // defines the odd and even buttons
    evenbuttonState = digitalRead (evenbuttonPin);
    oddbuttonState = digitalRead (oddbuttonPin);
  
    // if even button is pressed
    if (evenbuttonState == HIGH)   
    {     
        oddorevenchoice = 0; // sets odd or even choice to even    
        delay (1000); // waits one second
    
    }
  
    // if odd button is pressed
    if (oddbuttonState == HIGH)
    {    
        oddorevenchoice = 1; // sets odd or even to odd
        delay (1000);
    }

} // end of loop


