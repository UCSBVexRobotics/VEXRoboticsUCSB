/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Alex Mei                                                  */
/*    Created:      Sat Jan 18 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftMotor            motor         1               
// RightMotor           motor         2               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <cmath>
#include <iostream>

using namespace vex;

#define PI 3.14159265
double const velocity = -1; //PLACEHOLDER TEST

void startMotors(){
  LeftMotor.spin(forward);
  RightMotor.spin(forward);
}

void move(double x, double y){
  double unit_x = x / 100;
  double unit_y = y / 100;
  double unit_magnitude = sqrt(unit_x * unit_x + unit_y * unit_y);
  std::cout << x << "," << y << std::endl;

  //check domain
  if(unit_magnitude > 1){
      unit_magnitude = 1;
  }
  //check for reverse direction
  if(y < 0){
    unit_magnitude *= -1;
  }

  //go straight
  if(x == 0){
    RightMotor.setVelocity(100*unit_magnitude, percent);
    LeftMotor.setVelocity(100*unit_magnitude, percent);
  }
  //turn left
  else if(x < 0){
    RightMotor.setVelocity(100*unit_magnitude, percent);
    LeftMotor.setVelocity((100+x)*unit_magnitude, percent);
  }
  //turn right
  else{
    LeftMotor.setVelocity(100*unit_magnitude, percent);
    RightMotor.setVelocity((100-x)*unit_magnitude, percent);
  }
}

void moveForward(double distance){
  double time = velocity / distance;
  move(0, 100);
  task::sleep(time);
}

void turnRight(){
  move(70.71, 70.71);
  task::sleep(-1); //PLACEHOLDER TIME
}

void turnLeft(){
  move(-70.71, 70.71);
  task::sleep(-1); //PLACEHOLDER TIME
}

void autonomous(){
  double d1 = -1; //PLACEHOLDER VALUE; NEEDS TESTING
  double d2 = -1; //PLACEHOLDER VALUE; NEEDS TESTING
  //start ramp suction
  moveForward(d1);
  turnRight();
  moveForward(d2);
  //place blocks in zone
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  startMotors();
  while(true){
    move(Controller1.Axis1.position(percent), 
         Controller1.Axis2.position(percent));
    
  }
}
