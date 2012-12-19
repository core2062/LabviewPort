#include "CoreSubsystem.h"
#include "WPILib.h"
#include "util.h"

class TurretSubsystem : public CoreSubsystem
{
	
	CANJaguar motor;
	
	DigitalInput leftLimit;
	DigitalInput rightLimit;
	
	bool button7;
	bool leftValue;
	bool rightValue;
	float speed;
	float gain;
	float axis3;	
	
public:
	
	TurretSubsystem(void):
		motor(17),
		leftLimit(6),
		rightLimit(7)
	{
		speed = 0;
		gain = .5;
	}
		
	void teleop_init(void){}
		
	void teleop_joystick(Joystick joystick1, Joystick joystick2)
	{
		axis3 = -joystick2.GetRawAxis(3);
		button7 = joystick2.GetRawButton(7);
		leftValue = leftLimit.Get();
		rightValue= rightLimit.Get();
		
	}
	
	void teleop_main(void)
	{
		axis3 = deadband(axis3);
		axis3 = axis3 * gain;
		
		if(!button7)
		{
			//Vision code?
		}
		
		if(leftValue && rightValue)
		{
			speed = 0;
		}
		else if (axis3 > 0)
		{
			speed = rightValue ? 0 : axis3;
		}
		else if (axis3 < 0)
		{
			speed = leftValue ? 0 : axis3;
		}
	}
	
	void teleop_motors(void)
	{
		motor.Set(speed);
	}

};
