#include "CoreSubsystem.h"
#include "WPILib.h"
#include "util.h"

class LiftSubsystem : public CoreSubsystem
{
	Jaguar	frontMotor;
	Jaguar	backMotor;
	bool	button5;
	float	speed;
	
	
public:
	
	LiftSubsystem(void):
		frontMotor(1),
		backMotor(2)
	{
		button5 = false;
		speed = 0;
	}
	
	void teleop_init(void)
	{
		
	}
		
	void teleop_joystick(Joystick joystick1, Joystick joystick2)
	{
		button5 = joystick2.GetRawButton(5);
	}
	
	void teleop_main(void)
	{
		speed = button5 ? -1 : 0;
	}
	
	void teleop_motors(void)
	{
		frontMotor.SetSpeed(speed);
		backMotor.SetSpeed(speed);
	}

};
