#include <elapsedMillis.h>
// see warning above about FioV3
const int pumpPin =  PB0;      // the number of the LED pin
// Pin 13 has an LED connected on most Arduino boards.
// if using Arduino IDE 1.5 or above you can use pre-defined
// LED_BUILTIN  instead of 'led'
// 
elapsedMillis timer0;

// attiny85 1000 = 10 sec
// attiny85 100 = 1 sec * 60 = 6000

#define timerinterval 360000 // 1 hour?
#define pumpinterval  7500 // 1 min
//#define pumpinterval  15000 // 2min

// the interval in mS 
boolean pumpActive = false;


// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(pumpPin, OUTPUT);
  timer0 = 0; // clear the timer at the end of startup
  
  pumpActive = true;
  digitalWrite(pumpPin, HIGH);    // turn the LED off by making the voltage LOW
  
}

void loop() {
  if (pumpActive == false)
  {
     if (timer0 > timerinterval) {
      timer0 -= timerinterval; //reset the timer
      pumpActive = true;
      digitalWrite(pumpPin, HIGH);    // turn the LED off by making the voltage LOW
     }    
  }else{
     if (timer0 > pumpinterval) {
      timer0 -= pumpinterval; //reset the timer
      pumpActive = false;
      digitalWrite(pumpPin, LOW);    // turn the LED off by making the voltage LOW
     }    
    
  }

}

