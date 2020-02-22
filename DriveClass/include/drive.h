/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       drive.cpp                                                  */
/*    Author:       Alex Mei                                                  */
/*    Created:      Sat Feb 22 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
using namespace vex;

#ifndef DRIVE_H
#define DRIVE_H
class Drive{
  public:
    static constexpr double PI = 3.14159265;

    //constructor, pass in port numbers to appropriately initialize
    Drive(int portA = 0,int portB = 0);

    //destructor, destroys dynamic memory
    ~Drive();

    //starts the left and right motors for robot
    void startMotors();

    //pass in coordinates of joystick direction vector
    //moves robot in appropriate direction
    void move(double x, double y);

    //moves forward specified distance
    void moveForward(double distance, double velocity);

    //turns robot to the right, (moving [PLACEHOLDER] value forward in process)
    void turnRight();

    //turns robot to the left, (moving [PLACEHOLDER] value forward in process)
    void turnLeft();

    //robot movement during autonomous period
    void autonomous();

  private:
    motor* LeftMotor = new motor(0, ratio18_1, false);
    motor* RightMotor = new motor(0, ratio18_1, false);

};
#endif
