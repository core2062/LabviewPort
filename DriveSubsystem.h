#include "CoreSubsystem.h"
#include "WPILib.h"

class DriveSubsystem : public CoreSubsystem{
	// Drive Motors
	RobotDrive driveMotors;
	
	float axis1;
	float axis2;
	float axis4;
	
public:
	
	DriveSubsystem(void);
	
	// Called before loop at start of Teleop period
	void teleop_init(void);
	
	//Called sequentially during loop, interleaved with other subsystems
	void teleop_joystick(Joystick& joystick1, Joystick& joystick2);
	void teleop_main(void);
	void teleop_motors(void);
};
