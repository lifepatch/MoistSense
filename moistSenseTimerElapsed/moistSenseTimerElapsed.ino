#include <elapsedMillis.h>
// see warning above about FioV3
const int pumpPin =  PB0;      // the number of the LED pin
// Pin 13 has an LED connected on most Arduino boards.
// if using Arduino IDE 1.5 or above you can use pre-defined
// LED_BUILTIN  instead of 'led'
// 
elapsedMillis timer0;
#define timerinterval 1000
#define pumpinterval  500
// the interval in mS 
boolean pumpActive = false;


// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(pumpPin, OUTPUT);
  timer0 = 0; // clear the timer at the end of startup
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

