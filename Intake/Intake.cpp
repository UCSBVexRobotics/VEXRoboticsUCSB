#include "vex.h"

class Intake{
  // Intake class for two motors
  motor rightIntake, leftIntake;
  public:
  Intake(int32_t setPort, gearSetting setRatio, bool isReversedRight, bool isReversedLeft, directionType left, directionType right);
  void setIntakeVelocity(double Velocity);
  double velocityInput;

  private:
  
};

Intake::Intake(int32_t setPort, gearSetting setRatio, bool isReversedRight,
                bool isReversedLeft, directionType right, directionType left):
                  // Initializing the Motors to default values
                  rightIntake(motor(setPort, setRatio, isReversedRight)),
                  leftIntake (motor(setPort, setRatio, isReversedLeft)) 
{
  // Default format: Intake(setPort, setRatio, isReversedRight, isReversedLeft, right, left)
  // Valid inputs for setPort: PORT + a number from 1 to 21
  // Valid Inputs for setRatio: ratio36_1, ratio18_1, ratio6_1 
  // Set isReversedRight and isReversedLeft to either true or false
  // Set the direction of the motors (left and right) to either forward or reverse

  rightIntake.spin(right);
  leftIntake.spin(left);

}

void Intake::setIntakeVelocity(double Velocity){
  rightIntake.setVelocity(Velocity, rpm);
  leftIntake.setVelocity(Velocity, rpm);
}
