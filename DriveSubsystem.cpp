#include "CORESubsystem.h"
#include "DriveSubsystem.h"
#include "WPILib.h"
#include "util.h"

std::string DriveSubsystem::name(void){
	return "Drive";
}

DriveSubsystem::DriveSubsystem(CORERobot& robot):
	CORESubsystem(robot),
	driveMotors(6,8,9,7){
	driveMotors.SetExpiration(0.1);
	// Motor Invertions
//	driveMotors.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
//	driveMotors.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	driveMotors.SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	driveMotors.SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	driveMotors.SetSafetyEnabled(false);
}

void DriveSubsystem::teleop_init(void){
	robot.joystick.register_axis("drive_x", 1, 1);
	robot.joystick.register_axis("drive_rotation", 1, 4);
	robot.joystick.register_axis("drive_y", 1, 2);
}
	
void DriveSubsystem::teleop_joystick()
{
	drive_x = robot.joystick.axis("drive_x");
	drive_rotation = robot.joystick.axis("drive_rotation");
	drive_y = robot.joystick.axis("drive_y");
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

