#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "Arduino.h"

class Ultrasonic {
  public:
    Ultrasonic(int pin);
    long MeasureInCentimeters(uint32_t timeout = 1000000L);
    long MeasureInMillimeters(uint32_t timeout = 1000000L);
    bool isObjectDetected(int threshold, uint32_t timeout = 1000000L);
  private:
    int _pin;//pin number of Arduino that is connected with SIG pin of Ultrasonic Ranger.
    long duration(uint32_t timeout = 1000000L);
};

#endif