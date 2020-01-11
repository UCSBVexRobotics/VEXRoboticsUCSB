/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Rory                                             */
/*    Created:      Sat Jan 11 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Motor1               motor         1               
// Motor2               motor         2               
// Motor3               motor         3               
// Motor4               motor         4               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <iostream>
using namespace vex;

class Chassis{
  public:
    Chassis();
    ~Chassis();
    void setDriveMotorVelocities(double verticalVelocity, double horizontalVelocity);
    double verticalVelocities;
    double horizontalVelocities;
    void setDriveTurnVelocities(double rightTurnVelocity, double leftTurnVelocity);
    double rightTurnVelocity;
    double leftTurnVelocity;
};

Chassis::Chassis(){
  Motor1.spin(forward);
  Motor2.spin(forward);
  Motor3.spin(forward);
  Motor4.spin(forward);

}

Chassis::~Chassis(){
  Brain.Screen.print("bruh\n");
}

void Chassis::setDriveMotorVelocities(double verticalVelocity, double horizontalVelocity) {
    Motor1.setVelocity(verticalVelocity,rpm);
    Motor2.setVelocity(verticalVelocity,rpm);
    Motor3.setVelocity(horizontalVelocity,rpm);
    Motor4.setVelocity(horizontalVelocity,rpm);
}

void setDriveTurnVelocities(double rightTurnVelocity, double leftTurnVelocity){
    Motor1.setVelocity(rightTurnVelocity,rpm);
    Motor2.setVelocity(rightTurnVelocity,rpm);
    Motor3.setVelocity(leftTurnVelocity,rpm);
    Motor4.setVelocity(leftTurnVelocity,rpm);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Chassis drive;

  while(true){
    drive.verticalVelocities = Controller1.Axis3.position(percent);
    drive.horizontalVelocities = Controller1.Axis4.position(percent);
    drive.rightTurnVelocity = -Controller1.Axis1.position(percent);
    drive.leftTurnVelocity = Controller1.Axis2.position(percent);
    drive.setDriveMotorVelocities(drive.verticalVelocities, drive.horizontalVelocities);
  }
}
