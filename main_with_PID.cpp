/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\USER                                             */
/*    Created:      Sat Jan 11 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motor1               motor         1               
// motor2               motor         2               
// motor3               motor         3               
// motor4               motor         4               
// ramp1                motor         5               
// ramp2                motor         6               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;


void PIDBaseControl (motor r, float target, float waitTime, float maxPower = 1);
class ramp {
private:
  motor r = motor(PORT1, ratio18_1, false);
public:
  bool run;
  ramp(int32_t port){
    r = motor(port, ratio18_1, false);
  } 
  void raise(){
    r.setReversed(false);

    //set target revolution and wait time
    PIDBaseControl(r, 20, .1);
  }
  void lower(){
    r.setReversed(true);
 //   r.rotateFor(/*how many revolution*/, rev, /*how fast*/, rpm, true);
  }
};




int fixTimerValue (float rawSeconds)
{
	int miliseconds;
	miliseconds = rawSeconds*1000;
	if (miliseconds < 250)
	{
		miliseconds = 250;
	}
	return miliseconds;
}

void PIDBaseControl (motor r, float target, float waitTime, float maxPower)
{
	float Kp = 0.34;      // change
	float Ki = 0.01;
	float Kd = 0.5;

	int error;


//needchanging
	float proportion;
	int integralRaw;
	float integral;
	int lastError;
	int derivative;
// might need this or not
  float integralActiveZone = 50;
	float integralPowerLimit = 50/Ki;

	int finalPower;

	bool timerBool = true;

//  reset ramp rotation
  r.resetRotation();
  Brain.resetTimer();

	while (Brain.Timer.value() < fixTimerValue(waitTime))
	{
		error = target-r.rotation(rev);

		proportion = Kp*error;

		if (abs(error) < integralActiveZone && error != 0)
		{
			integralRaw = integralRaw+error;
		}
		else
		{
			integralRaw = 0;
		}

		if (integralRaw > integralPowerLimit)
		{
			integralRaw = integralPowerLimit;
		}
		if (integralRaw < -integralPowerLimit)
		{
			integralRaw = -integralPowerLimit;
		}

		integral = Ki*integralRaw;

		derivative = Kd*(error-lastError);
		lastError = error;

		if (error == 0)
		{
			derivative = 0;
		}

		finalPower = proportion+integral+derivative;

		if (finalPower > maxPower*127)
		{
			finalPower = maxPower*127;
		}
		else if (finalPower < -maxPower*127)
		{
			finalPower = -maxPower*127;
		}

		r.setVelocity(finalPower,rpm);
    r.spin(forward);

    vex::task::sleep(40);

		if (error < 30)
		{
			timerBool = false;
		}

		if (timerBool)
		{
			Brain.resetTimer();
		}
	}
	r.setVelocity(0,rpm);
  r.spin(forward);
}















void run(int vertical, int horizontal){
  motor1.spin(forward);
  motor2.spin(forward);
  motor3.spin(forward);
  motor4.spin(forward);
  motor1.setVelocity(vertical,rpm);
  motor2.setVelocity(vertical,rpm); 
  motor3.setVelocity(horizontal,rpm);
  motor4.setVelocity(horizontal,rpm);
}



int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(true){
    run(Controller1.Axis3.position(percent),
        Controller1.Axis4.position(percent)
    );





  }
}
