#include "CoreSubsystem.h"
#include "WPILib.h"
#include "util.h"

class LiftSubsystem : public CoreSubsystem
{
	Jaguar	rightMotor;
	Jaguar	leftMotor;
	bool	button1;
	float	speed;
	
	
public:
	
	LiftSubsystem(void):
		rightMotor(1),
		leftMotor(2)
	{
		button1 = false;
		speed = 0;
	}
	
	void teleop_init(void)
	{
		
	}
		
	void teleop_joystick(Joystick& joystick1, Joystick& joystick2)
	{
		button1 = joystick2.GetRawButton(5);
	}
	
	void teleop_main(void)
	{
		speed = button1 ? 0.75 : 0;
	}
	
	void teleop_motors(void)
	{
		rightMotor.SetSpeed(-1 * speed);
		leftMotor.SetSpeed(speed);
	}

};
