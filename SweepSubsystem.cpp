#include "CORESubsystem.h"
#include "WPILib.h"
#include "util.h"
#include "SweepSubsystem.h"

std::string SweepSubsystem::name(void){
	return "sweep";
}

SweepSubsystem::SweepSubsystem(CORERobot& robot):
	CORESubsystem(robot),
	rightMotor(5),
	leftMotor(3){
	sweep_button = false;
	speed = 0;
}

void SweepSubsystem::teleop_init(void){
	robot.joystick.register_button("sweep", 2, 1);
}
	
void SweepSubsystem::teleop_joystick(void){
	sweep_button = robot.joystick.button("sweep");
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
