#include "CORESubsystem.h"
#include "DriveSubsystem.h"
#include "COREJoystick.h"
#include "WPILib.h"
#include "util.h"

std::string DriveSubsystem::name(void){
	return "Drive";
}

DriveSubsystem::DriveSubsystem(void):
	driveMotors(9,8,6,7)
{
	driveMotors.SetExpiration(0.1);
	// Motor Invertions
//	driveMotors.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
//	driveMotors.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	driveMotors.SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	driveMotors.SetInvertedMotor(RobotDrive::kRearRightMotor, true);
}

void DriveSubsystem::teleop_init(void){}
	
void DriveSubsystem::teleop_joystick(COREJoystick& joystick)
{
	drive_x = joystick.drive_x();
	drive_rotation = joystick.drive_rotation();
	drive_y = joystick.drive_y();
}

void DriveSubsystem::teleop_main(void)
{
	drive_x = deadband(drive_x);
	drive_rotation = deadband(drive_rotation);
	drive_y = deadband(drive_y);
}

void DriveSubsystem::teleop_motors(void)
{
	driveMotors.MecanumDrive_Cartesian(drive_x, drive_y, drive_rotation);
}

