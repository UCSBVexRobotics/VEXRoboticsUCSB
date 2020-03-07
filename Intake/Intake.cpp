#include "vex.h"

class Intake{
  // Intake class for two motors
  public:
  Intake(int32_t setPortR, int32_t setPortL, gearSetting setRatio, bool isReversedRight, bool isReversedLeft, directionType one, directionType two);
  void setIntakeVelocity(double Velocity);
  double velocityInput;


  private:
  motor rightIntake, leftIntake;
};

Intake::Intake(int32_t setPortR, int32_t setPortL, gearSetting setRatio, bool isReversedRight,
                bool isReversedLeft, directionType one, directionType two):
                  // Initializing the Motors
                  rightIntake(motor(setPortR, setRatio, isReversedRight)),
                  leftIntake (motor(setPortL, setRatio, isReversedLeft)) 
{
  // Default format: Intake(setPort, setRatio, isReversedRight, isReversedLeft, right, left)
  // Valid inputs for setPortR and setPortL: PORT + a number from 1 to 21
  // Valid Inputs for setRatio: ratio36_1, ratio18_1, ratio6_1 
  // Set isReversedRight and isReversedLeft to either true or false
  // Set the direction of the motors (one and two) to either forward or reverse

  rightIntake.spin(one);
  leftIntake.spin(two);

}

void Intake::setIntakeVelocity(double Velocity){
  rightIntake.setVelocity(Velocity, rpm);
  leftIntake.setVelocity(Velocity, rpm);
}
