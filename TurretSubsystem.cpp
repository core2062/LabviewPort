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
	
void TurretSubsystem::teleop_joystick(COREJoystick& joystick)
{
	rotation = joystick.rotate_turret();
	is_autoaim = joystick.turret_is_autoaim();
	leftValue = leftLimit.Get();
	rightValue= rightLimit.Get();
	
}

void TurretSubsystem::teleop_main(void)
{
	rotation = deadband(rotation);
	rotation = rotation * gain;
	
	if(is_autoaim)
	{
		//Vision code?
	}
	
	if(leftValue && rightValue)
	{
		speed = 0;
	}
	else if (rotation > 0)
	{
		speed = rightValue ? 0 : rotation;
	}
	else if (rotation < 0)
	{
		speed = leftValue ? 0 : rotation;
	}
}

void TurretSubsystem::teleop_motors(void)
{
	motor.Set(speed);
}
