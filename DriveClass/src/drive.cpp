/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       drive.cpp                                                  */
/*    Author:       Alex Mei                                                  */
/*    Created:      Sat Feb 22 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "drive.h"

using namespace vex;

Drive::Drive(int portA,int portB, int portC, int portD){
  delete FrontLeftMotor;
  delete FrontRightMotor;
  delete BackLeftMotor;
  delete BackRightMotor;
  FrontLeftMotor = new motor(portA, ratio18_1, false);
  FrontRightMotor = new motor(portB, ratio18_1, false);
  BackLeftMotor = new motor(portC, ratio18_1, false);
  BackRightMotor = new motor(portD, ratio18_1, false);
}

//destructor
Drive::~Drive(){
  delete FrontLeftMotor;
  delete FrontRightMotor;
  delete BackLeftMotor;
  delete BackRightMotor;
}

void Drive::startMotors(){
  FrontLeftMotor->spin(forward);
  FrontRightMotor->spin(forward);
  BackLeftMotor->spin(forward);
  BackRightMotor->spin(forward);
}

void Drive::move(double x, double y){
  double unit_x = x / 100;
  double unit_y = y / 100;
  double unit_magnitude = sqrt(unit_x * unit_x + unit_y * unit_y);

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
    FrontRightMotor->setVelocity(100*unit_magnitude, percent);
    FrontLeftMotor->setVelocity(100*unit_magnitude, percent);
    BackRightMotor->setVelocity(100*unit_magnitude, percent);
    BackLeftMotor->setVelocity(100*unit_magnitude, percent);
  }

  //turn left
  else if(x < 0){
    FrontRightMotor->setVelocity(100*unit_magnitude, percent);
    FrontLeftMotor->setVelocity((100+x)*unit_magnitude, percent);
    BackRightMotor->setVelocity(100*unit_magnitude, percent);
    BackLeftMotor->setVelocity((100+x)*unit_magnitude, percent);
  }

  //turn right
  else{
    FrontLeftMotor->setVelocity(100*unit_magnitude, percent);
    FrontRightMotor->setVelocity((100-x)*unit_magnitude, percent);
    BackLeftMotor->setVelocity(100*unit_magnitude, percent);
    BackRightMotor->setVelocity((100-x)*unit_magnitude, percent);
  }
}

void Drive::moveForward(double distance, double velocity){
  double time = velocity / distance;
  move(0, 100);
  task::sleep(time);
}

void Drive::turnRight(){
  move(70.71, 70.71);
  task::sleep(-1); //PLACEHOLDER TIME
}

void Drive::turnLeft(){
  move(-70.71, 70.71);
  task::sleep(-1); //PLACEHOLDER TIME
}

void Drive::autoPeriod(){
  //PLACEHOLDER
}


