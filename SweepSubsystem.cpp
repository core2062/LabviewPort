#include "CORESubsystem.h"
#include "WPILib.h"
#include "util.h"
#include "SweepSubsystem.h"

SweepSubsystem::SweepSubsystem(void):
	rightMotor(5),
	leftMotor(3)
{
	name = "Sweep";
	sweep_button = false;
	speed = 0;
}

void SweepSubsystem::teleop_init(void)
{
	
}
	
void SweepSubsystem::teleop_joystick(COREJoystick& joystick)
{
	sweep_button = joystick.sweeper();
}

void SweepSubsystem::teleop_main(void)
{
	speed = sweep_button ? 0.75 : 0;
}

void SweepSubsystem::teleop_motors(void)
{
	rightMotor.SetSpeed(-1 * speed);
	leftMotor.SetSpeed(speed);
}
