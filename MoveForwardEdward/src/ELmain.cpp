/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       edward                                                    */
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
class Motor {
  public:
    Motor();
};

void setVel(int speed) {

  Motor1.setVelocity(speed, rpm);
  Motor2.setVelocity(speed, rpm);
  Motor3.setVelocity(speed, rpm);
  Motor4.setVelocity(speed, rpm);
}

Motor::Motor (){
  Motor1.spin(forward);
  Motor2.spin(forward);
  Motor3.spin(forward);
  Motor4.spin(forward);
  setVel(100);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Motor Go;
  task::sleep(5000);
  setVel(0);

}

