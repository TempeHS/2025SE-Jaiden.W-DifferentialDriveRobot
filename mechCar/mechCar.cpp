#include "mechCar.h"
#include "lineSensor.h"
#include "ledArray.h"

MechCar::MechCar(LineSensor& lineSensor, LEDArray& ledArray, wheelsControl& wheels)
  : lineSensor(lineSensor), ledArray(ledArray), wheels(wheels) {}

void MechCar::init(){
  lineSensor.init();
  wheels.init();
  ledArray.init();
}

void MechCar::followLine() {
  bool leftOnLine = lineSensor.leftDetermineState();
  bool rightOnLine = lineSensor.rightDetermineState();
  if (!leftOnLine && !rightOnLine) {
    wheels.moveForward();
    wheels.update();
  } else if (!leftOnLine && rightOnLine) {
    wheels.turnRight();
    wheels.update();
  } else if (leftOnLine && !rightOnLine) {
    wheels.turnLeft();
    wheels.update();
  } else {
    wheels.stop();
    wheels.update();
  }
  //lineSensor.displayState(ledArray);
}


void MechCar::showState() {
  lineSensor.displayState(ledArray);
}

void MechCar::test(){
  wheels.stop();
  wheels.update();
}

