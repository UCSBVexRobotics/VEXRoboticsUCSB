/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       albertohuanghe                                            */
/*    Created:      Sat Feb 01 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftMotor            motor         1               
// rightMotor           motor         2               
// Controller1          controller                    
// Motor4               motor         4               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void forwardOrBackward(double verticalVelocity, double horizontalVelocity){
  leftMotor.setVelocity(verticalVelocity + horizontalVelocity,rpm);
  rightMotor.setVelocity(verticalVelocity - horizontalVelocity,rpm);
  //leftMotor.setVelocity(-horizontalVelocity,rpm);
  //rightMotor.setVelocity(horizontalVelocity,rpm);
}
/*
void turning(double horizontalVelocity){
  leftMotor.setVelocity(-horizontalVelocity,rpm);
  rightMotor.setVelocity(horizontalVelocity,rpm);
}
*/

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  leftMotor.spin(forward);
  rightMotor.spin(forward);
  leftMotor.setVelocity(0,rpm);
  rightMotor.setVelocity(0,rpm);
  while(true){
    forwardOrBackward(Controller1.Axis3.position(percent),Controller1.Axis4.position(percent));
    //turning(Controller1.Axis1.position(percent));
  
  }
  
}
