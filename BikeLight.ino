/*
  Mini-Project #1

  In MP1, we are tasked to create a bike light
  using Arduino and some other electrical parts. 
  The following is our documented code that we used 
  to successfully meet the criteria to this firt 
  mini-project. 

  Part 1: Set up LEDs with a button-press switch to 
  change between several different modes.

  Part 2: Use potentiometer to change the brightness 
  of the LED output. 

  Coded by Toluope Oshinowo and Walter Villa
  September 13, 2021
  Principles of Integrated Engineering (PIE)
*/

// Initializing Global Variables

int ledState = 0; // setting initial illumination mode for the LED's (all on)
int currentButtonState = LOW; // setting the defalut previous pressed state of the button (not pressed = LOW, pressed = HIGH)
int lastButtonState = LOW; // setting the defalut previous pressed state of the button (not pressed = LOW, pressed = HIGH)
int potentiometerState = 0; // setting the default potentiometer reading to 0


// the setup function runs once on start

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600); // artifact from testing ledState and potentiometerState logic
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

// the loop function runs continuously

void loop() {
  currentButtonState = digitalRead(8); // storing the button state to manage the illumination mode of the LED's
  potentiometerState = analogRead(0); // storing potentiometer state to manage the brightness of the LED's

  // this 'if' statement handles the cycling of ledState's value (which controls the illumination modes)
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    ledState++;
    if (ledState > 4) {
      ledState = 0;
    }
    delay(100);
    lastButtonState = HIGH;
  } else if(currentButtonState == LOW) {
    lastButtonState = LOW;
  }

  // this 'switch' statement handles the invocation of the different illumination modes
  switch (ledState) {
    case 0:
      lightson();
      break;
    case 1:
      blinking();
      break;
    case 2:
      bouncing();
      break;
    case 3:
      zone();
      break;
    case 4:
      lightsoff();
    default:
      break;
  }

}

// Declaring different illumination modes as helper functions
/* 
 *  Note: For the analogWrite functions, we use the values read by
 *  the potentiometer to fluctuate the LED brightness. 
*/ 

void lightsoff() {
  // set all the LED's off by making the voltage LOW
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
}

void lightson() {
  // set all the LED's on based on potentiometerState
  analogWrite(13, potentiometerState);
  analogWrite(12, potentiometerState);
  analogWrite(11, potentiometerState);
  analogWrite(10, potentiometerState);
  analogWrite(9, potentiometerState);
}

void blinking() {
  // set all the LED's on based on potentiometerState
  analogWrite(13, potentiometerState);
  analogWrite(12, potentiometerState);
  analogWrite(11, potentiometerState);
  analogWrite(10, potentiometerState);
  analogWrite(9, potentiometerState);
  // wait for 1000 ms
  delay(1000);
  // set all the LED's off by making the voltage LOW                 
  analogWrite(13, LOW);    
  analogWrite(12, LOW);
  analogWrite(11, LOW);
  analogWrite(10, LOW);
  analogWrite(9, LOW);
  // wait for 1000 ms
  delay(1000);                       
}

void bouncing() {
  analogWrite(13, potentiometerState);
  analogWrite(12, LOW);
  analogWrite(11, LOW);
  analogWrite(10, LOW);
  analogWrite(9, LOW);
  delay(100);                      
  analogWrite(13, LOW);
  analogWrite(12, potentiometerState);
  analogWrite(11, LOW);
  analogWrite(10, LOW);
  analogWrite(9, LOW);
  delay(100);                   
  analogWrite(13, LOW);
  analogWrite(12, LOW);
  analogWrite(11, potentiometerState);
  analogWrite(10, LOW);
  analogWrite(9, LOW);
  delay(100);                    
  analogWrite(13, LOW);
  analogWrite(12, LOW);
  analogWrite(11, LOW);
  analogWrite(10, potentiometerState);
  analogWrite(9, LOW);
  delay(100);                     
  analogWrite(13, potentiometerState);
  analogWrite(12, LOW);
  analogWrite(11, LOW);
  analogWrite(10, LOW);
  analogWrite(9, potentiometerState);
  delay(100);                    
  analogWrite(13, LOW);
  analogWrite(12, LOW);
  analogWrite(11, LOW);
  analogWrite(10, potentiometerState);
  analogWrite(9, LOW);
  delay(100);
  analogWrite(13, LOW);
  analogWrite(12, LOW);
  analogWrite(11, potentiometerState);
  analogWrite(10, LOW);
  analogWrite(9, LOW);
  delay(100);
  analogWrite(13, LOW);
  analogWrite(12, potentiometerState);
  analogWrite(11, LOW);
  analogWrite(10, LOW);
  analogWrite(9, LOW);
  delay(100);
}

void zone() {
  analogWrite(13, potentiometerState);
  analogWrite(12, LOW);
  analogWrite(11, LOW);
  analogWrite(10, LOW);
  analogWrite(9, potentiometerState);
  delay(100);
  analogWrite(13, LOW);
  analogWrite(12, potentiometerState);
  analogWrite(11, LOW);
  analogWrite(10, potentiometerState);
  analogWrite(9, LOW);
  delay(100);
  analogWrite(13, LOW);
  analogWrite(12, LOW);
  analogWrite(11, potentiometerState);
  analogWrite(10, LOW);
  analogWrite(9, LOW);
  delay(100);
  analogWrite(13, LOW);
  analogWrite(12, potentiometerState);
  analogWrite(11, LOW);
  analogWrite(10, potentiometerState);
  analogWrite(9, LOW);
  delay(100);
  analogWrite(13, potentiometerState);
  analogWrite(12, LOW);
  analogWrite(11, LOW);
  analogWrite(10, LOW);
  analogWrite(9, potentiometerState);
  delay(100);
}
