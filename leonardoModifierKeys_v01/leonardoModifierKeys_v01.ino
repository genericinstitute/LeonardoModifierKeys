
/*
  Leonardo Modifier Keys Control

  Push Modifier Keys from the keyboard with 3 push buttons corresponding to Shift, Ctrl and Alt on an Arduino Leonardo, Micro or Due.

  Hardware:
  - 3 pushbuttons attached to D5, D6, D7

  Based on
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/KeyboardMessage
  
  created  9 Jan 2022
  by Kristoff Lovetec

  This code is in the public domain.
*/

#include "Keyboard.h"

// set pin numbers for the buttons:
const int shift = 6;
const int ctrl = 5;
const int alt = 7;

// for checking the state of a pushButton
int shiftPreviousButtonState = HIGH;
int ctrlPreviousButtonState = HIGH;
int altPreviousButtonState = HIGH;

void setup() {
  // initialize the buttons inputs:
  pinMode(shift, INPUT);
  pinMode(ctrl, INPUT);
  pinMode(alt, INPUT);
  //open the serial port
  Serial.begin(9600);
  // initialize keyboard control:
  Keyboard.begin();
}

void loop() {
  
  // read the buttons
  int shiftButtonState = digitalRead(shift);
  int ctrlButtonState = digitalRead(ctrl);
  int altButtonState = digitalRead(alt);

  // shift functionality
  if (shiftButtonState != shiftPreviousButtonState) {
      // and it's currently pressed:
      if (shiftButtonState == HIGH) {
        // press the key
        Keyboard.press(KEY_LEFT_SHIFT);
        // type out a message
        Serial.println("You pressed the shift button.");
      } else {
        // release the key
        Keyboard.release(KEY_LEFT_SHIFT);
        Serial.println("You released the shift button.");
      }
  }

  // ctrl functionality
  if (ctrlButtonState != ctrlPreviousButtonState) {
      // and it's currently pressed:
      if (ctrlButtonState == HIGH) {
        // press the key
        Keyboard.press(KEY_LEFT_CTRL);
        // type out a message
        Serial.println("You pressed the ctrl button.");
      } else {
        // release the key
        Keyboard.release(KEY_LEFT_CTRL);
        Serial.println("You released the ctrl button.");
      }
  }

  // alt functionality
  if (altButtonState != altPreviousButtonState) {
      // and it's currently pressed:
      if (altButtonState == HIGH) {
        // press the key
        Keyboard.press(KEY_LEFT_ALT);
        // type out a message
        Serial.println("You pressed the alt button.");
      } else {
        // release the key
        Keyboard.release(KEY_LEFT_ALT);
        Serial.println("You released the alt button.");
      }
  }

  // save the current button state for comparison next time:
  shiftPreviousButtonState = shiftButtonState;
  ctrlPreviousButtonState = ctrlButtonState;
  altPreviousButtonState = altButtonState;
  
  // a little delay to avoid sticky keys
  delay(10);
}
