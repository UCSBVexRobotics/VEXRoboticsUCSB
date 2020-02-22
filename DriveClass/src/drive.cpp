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

using namespace vex;


class Drive{
  public:
    static constexpr double PI = 3.14159265;
    static constexpr double velocity = -1; //PLACEHOLDER TEST

    //constructor
    Drive(int portA = 0,int portB = 0){
      delete LeftMotor;
      delete RightMotor;
      LeftMotor = new motor(portA, ratio18_1, false);
      RightMotor = new motor(portB, ratio18_1, false);
    }

    //destructor
    ~Drive(){
      delete LeftMotor;
      delete RightMotor;
    }

    void startMotors(){
      LeftMotor->spin(forward);
      RightMotor->spin(forward);
    }

    void move(double x, double y){
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
        RightMotor->setVelocity(100*unit_magnitude, percent);
        LeftMotor->setVelocity(100*unit_magnitude, percent);
      }

      //turn left
      else if(x < 0){
        RightMotor->setVelocity(100*unit_magnitude, percent);
        LeftMotor->setVelocity((100+x)*unit_magnitude, percent);
      }

      //turn right
      else{
        LeftMotor->setVelocity(100*unit_magnitude, percent);
        RightMotor->setVelocity((100-x)*unit_magnitude, percent);
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

  private:
    motor* LeftMotor = new motor(0, ratio18_1, false);
    motor* RightMotor = new motor(0, ratio18_1, false);

};

