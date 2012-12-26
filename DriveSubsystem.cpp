#include "CoreSubsystem.h"
#include "WPILib.h"
#include "util.h"

class DriveSubsystem : public CoreSubsystem
{
	// Drive Motors
	RobotDrive driveMotors;
	
	float axis1;
	float axis2;
	float axis4;
	
public:
	
	DriveSubsystem(void):
		driveMotors(8,7,10,6)
	{
		driveMotors.SetExpiration(0.1);
		// Motor Invertions
		driveMotors.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
		driveMotors.SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
		driveMotors.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
		driveMotors.SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	}
	
	void teleop_init(void){}
		
	void teleop_joystick(Joystick& joystick1, Joystick& joystick2)
	{
		axis1 = joystick1.GetRawAxis(1);
		axis2 = joystick1.GetRawAxis(2);
		axis4 = joystick1.GetRawAxis(4);
	}
	
	void teleop_main(void)
	{
		axis1 = deadband(axis1);
		axis2 = deadband(axis2);
		axis4 = deadband(axis4);
	}
	
	void teleop_motors(void)
	{
		driveMotors.MecanumDrive_Cartesian(axis1, axis2, axis4);
	}

};
