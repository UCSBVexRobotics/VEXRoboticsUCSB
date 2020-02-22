/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       kellylin                                                  */
/*    Created:      Sat Feb 22 2020                                           */
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
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

class Chassis{
  public:
    Chassis() {
      Motor1.spin(forward);
      Motor2.spin(forward);
      Motor3.spin(forward);
      Motor4.spin(forward);
    }

    void setDriveMotorVelocities(double velocity);
};

void Chassis::setDriveMotorVelocities(double velocity) {
    Motor1.setVelocity(velocity,rpm);
    Motor2.setVelocity(velocity,rpm);
    Motor3.setVelocity(velocity,rpm);
    Motor4.setVelocity(velocity,rpm);   
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Chassis drive;
  drive.setDriveMotorVelocities(100); 
  task::sleep(5000);
  drive.setDriveMotorVelocities(0);

}



