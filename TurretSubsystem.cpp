#include "CORESubsystem.h"
#include "WPILib.h"
#include "util.h"
#include "TurretSubsystem.h"

TurretSubsystem::TurretSubsystem(void):
	motor(17),
	leftLimit(6),
	rightLimit(7)
{
	name = "Turret";
	speed = 0;
	gain = .5;
}
	
void TurretSubsystem::teleop_init(void){}
	
void TurretSubsystem::teleop_joystick(Joystick& joystick1, Joystick& joystick2)
{
	axis3 = -joystick2.GetRawAxis(3);
	button7 = joystick2.GetRawButton(7);
	leftValue = leftLimit.Get();
	rightValue= rightLimit.Get();
	
}

void TurretSubsystem::teleop_main(void)
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

void TurretSubsystem::teleop_motors(void)
{
	motor.Set(speed);
}
