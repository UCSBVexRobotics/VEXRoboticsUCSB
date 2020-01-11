/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\0edlo                                            */
/*    Created:      Sun Jan 05 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// VerticalMotorLeft    motor         1               
// Controller1          controller                    
// VerticalMotorRight   motor         2               
// HorizontalMotorBot   motor         3               
// HorizontalMotorTop   motor         4               
// leftIntakeMotor      motor         5               
// rightIntakeMotor     motor         6               
// leftRampLever        motor         7               
// rightRampLever       motor         8               
// SexYMotor            motor         21              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;

void configureMotors() {
  //Configuring Driving motors
  VerticalMotorLeft.spin(forward);
  VerticalMotorRight.spin(forward);
  HorizontalMotorBot.spin(forward);
  HorizontalMotorTop.spin(forward);

  //Configuring Intake Motors
  leftIntakeMotor.spin(forward);
  rightIntakeMotor.spin(forward);
  
  //Configuring Ramp Levers
  leftRampLever.spin(forward);
  rightRampLever.spin(forward);
}

void setDriveMotorVelocities(double verticalVelocity, double horizontalVelocity) {
    VerticalMotorLeft.setVelocity(verticalVelocity,rpm);
    VerticalMotorRight.setVelocity(verticalVelocity,rpm);
    HorizontalMotorBot.setVelocity(horizontalVelocity,rpm);
    HorizontalMotorTop.setVelocity(horizontalVelocity,rpm);
}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  //Configures all of Robot's Motors
  configureMotors();

  bool leftIntakeOn = false;
  bool rightIntakeOn = false;

  bool leftIntakeDirection = true;
  bool rightIntakeDirection = false;

  double verticalVelocities = 0;
  double horizontalVelocities = 0;
  while(true) {
    //Sets drive motor velocities base on right joystick
    verticalVelocities = Controller1.Axis2.position(percent);
    horizontalVelocities = Controller1.Axis1.position(percent);
    setDriveMotorVelocities(verticalVelocities, horizontalVelocities);
    //Turns ON and OFF right intake
    if(Controller1.ButtonR1.pressing()) {
      rightIntakeOn = !rightIntakeOn;
      if(rightIntakeOn) {
        rightIntakeMotor.setVelocity(100,rpm);
      } else {
        rightIntakeMotor.setVelocity(0,rpm);
      }
    }
    //Turns ON and OFF left intake
    if(Controller1.ButtonL1.pressing()) {
      leftIntakeOn = !leftIntakeOn;
      if(leftIntakeOn) {
        leftIntakeMotor.setVelocity(100,rpm);
      } else {
        leftIntakeMotor.setVelocity(0,rpm);
      }
    }
    //Reverses right intake flow
    if(Controller1.ButtonR2.pressing()) {
      rightIntakeDirection = !rightIntakeDirection;
      if(rightIntakeDirection) {
        rightIntakeMotor.spin(forward);
      } else {
        rightIntakeMotor.spin(reverse);
      }
    }
    //Reverses left intake flow
    if(Controller1.ButtonL2.pressing()) {
      leftIntakeDirection = !leftIntakeDirection;
      if(leftIntakeDirection) {
        leftIntakeMotor.spin(forward);
      } else {
        leftIntakeMotor.spin(reverse);
      }
    }


    //Raises left ramp updwards
    if(Controller1.ButtonUp.pressing()) {
      //TO DO: Code that implements PID control to raise left ramp upwards
    }
    //Raises left ramp downwards
    if(Controller1.ButtonDown.pressing()) {
      //TO DO: Code to raise ramp down and stop when hits bumper switch
    }

    //Raises right ramp updwards
    if(Controller1.ButtonX.pressing()) {
      //TO DO: Code that implements PID control to raise right ramp upwards
    }
    //Raises right ramp downwards
    if(Controller1.ButtonB.pressing()) {
      //TO DO: Code to raise ramp down and stop when hits bumper switch
    }
  }


}

