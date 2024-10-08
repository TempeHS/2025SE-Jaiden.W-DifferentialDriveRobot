#ifndef WHEEL_H
#define WHEEL_H

#include <Arduino.h>

#include <Servo.h>

class Wheel
{
  private:
  Servo servo;
  byte pin;
  //unsigned long speed;

  public:
  Wheel () {} // default constructor 
  Wheel (byte pin);

  // init the pin for the wheel
  void init();

  void moveForward();

  void moveBackward();

  void stop();

};

#endif