#include "CORESubsystem.h"
#include "WPILib.h"
#include "util.h"
#include "LiftSubsystem.h"

std::string LiftSubsystem::name(void){
	return "Lift";
}

LiftSubsystem::LiftSubsystem(void):
	frontMotor(1),
	backMotor(2)
{
	lift_up = false;
	speed = 0;
}

void LiftSubsystem::teleop_init(void)
{
	
}
	
void LiftSubsystem::teleop_joystick(COREJoystick& joystick)
{
	lift_up = joystick.lift_up();
}

void LiftSubsystem::teleop_main(void)
{
	speed = lift_up ? -1 : 0;
}

void LiftSubsystem::teleop_motors(void)
{
	frontMotor.SetSpeed(speed);
	backMotor.SetSpeed(speed);
}
