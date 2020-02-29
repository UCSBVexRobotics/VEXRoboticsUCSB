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
    //AND starts motors
    //PORTS: [A = Front Left, B = Front Right, C = Back Left, D = Back Right]
    Drive(int portA = 0,int portB = 0, int portC = 0, int portD = 0);

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
    void autoPeriod();

  private:
    motor* FrontLeftMotor = new motor(0, ratio18_1, false);
    motor* FrontRightMotor = new motor(0, ratio18_1, false);
    motor* BackLeftMotor = new motor(0, ratio18_1, false);
    motor* BackRightMotor = new motor(0, ratio18_1, false);
};
#endif
