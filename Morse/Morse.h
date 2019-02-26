/*
 * Christopher Marisco
 * Author: Arduino
 * Sample library building using Morse class.
 * Header file for the library "Morse".
 * 2/23/19
 */

 #ifndef Morse_h
 #define Morse_h

 #include "Arduino.h"

 class Morse{
  public:
  //Constructor:
    Morse(int pin);
  //Method definitions:
    void dot();
    void dash();
  //Fields:
  private:
    int _pin;
  };
  
  #endif
