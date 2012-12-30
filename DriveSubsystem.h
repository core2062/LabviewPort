#include "CORESubsystem.h"
#include "WPILib.h"

class DriveSubsystem : public CORESubsystem{
	// Drive Motors
	RobotDrive driveMotors;
	
	float axis1;
	float axis2;
	float axis4;
	
public:
	
	std::string name;
	DriveSubsystem(void);
	
	// Called before loop at start of Teleop period
	void teleop_init(void);
	
	//Called sequentially during loop, interleaved with other subsystems
	void teleop_joystick(Joystick& joystick1, Joystick& joystick2);
	void teleop_main(void);
	void teleop_motors(void);
};
