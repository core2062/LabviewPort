#include "CORESubsystem.h"
#include "WPILib.h"
#include "util.h"
#include "ShootSubsystem.h"

std::string ShootSubsystem::name(void){
	return "shoot";
}

ShootSubsystem::ShootSubsystem(void):
	top_motor(5),
	bottom_motor(3),
	conveyer_left(),
	conveyer_right()
{
	shoot_button = false;
	shoot_up = false;
	shoot_down = false;
	speed = 0;
}

void ShootSubsystem::teleop_init(void)
{
	
}
	
void ShootSubsystem::teleop_joystick(COREJoystick& joystick)
{
	shoot_button = joystick.shooter();
}

void ShootSubsystem::teleop_main(void)
{
	speed = shoot_button ? 0.75 : 0;
}

void ShootSubsystem::teleop_motors(void)
{
	rightMotor.SetSpeed(-1 * speed);
	leftMotor.SetSpeed(speed);
}
