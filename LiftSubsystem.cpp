#include "CoreSubsystem.h"
#include "WPILib.h"
#include "util.h"
#include "LiftSubsystem.h"
	
LiftSubsystem::LiftSubsystem(void):
	frontMotor(1),
	backMotor(2)
{
	button5 = false;
	speed = 0;
}

void LiftSubsystem::teleop_init(void)
{
	
}
	
void LiftSubsystem::teleop_joystick(Joystick& joystick1, Joystick& joystick2)
{
	button5 = joystick2.GetRawButton(5);
}

void LiftSubsystem::teleop_main(void)
{
	speed = button5 ? -1 : 0;
}

void LiftSubsystem::teleop_motors(void)
{
	frontMotor.SetSpeed(speed);
	backMotor.SetSpeed(speed);
}
