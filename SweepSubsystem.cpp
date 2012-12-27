#include "CoreSubsystem.h"
#include "WPILib.h"
#include "util.h"
#include "SweepSubsystem.h"

SweepSubsystem::SweepSubsystem(void):
	rightMotor(1),
	leftMotor(2)
{
	button1 = false;
	speed = 0;
}

void SweepSubsystem::teleop_init(void)
{
	
}
	
void SweepSubsystem::teleop_joystick(Joystick& joystick1, Joystick& joystick2)
{
	button1 = joystick2.GetRawButton(5);
}

void SweepSubsystem::teleop_main(void)
{
	speed = button1 ? 0.75 : 0;
}

void SweepSubsystem::teleop_motors(void)
{
	rightMotor.SetSpeed(-1 * speed);
	leftMotor.SetSpeed(speed);
}
