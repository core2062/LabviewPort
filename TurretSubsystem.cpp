#include "CORESubsystem.h"
#include "WPILib.h"
#include "util.h"
#include "TurretSubsystem.h"

std::string TurretSubsystem::name(void){
	return "Turret";
}

TurretSubsystem::TurretSubsystem(CORERobot& robot):
	CORESubsystem(robot),
	motor(4),
	leftLimit(6),
	rightLimit(7)
{
	speed = 0;
	gain = .5;
}
	
void TurretSubsystem::teleop_init(void){
	robot.joystick.register_axis("turret_rotation", 1, 3);
	robot.joystick.register_button("turret_autoaim", 1, 7);
}
	
void TurretSubsystem::teleop_joystick(void){
	rotation = robot.joystick.axis("turret_rotation");
	is_autoaim = robot.joystick.button("turret_autoaim");
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
