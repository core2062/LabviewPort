#include "CORESubsystem.h"
#include "WPILib.h"

class DriveSubsystem : public CORESubsystem{
	// Drive Motors
	RobotDrive driveMotors;
	
	float drive_x;
	float drive_rotation;
	float drive_y;
	
public:
	
	std::string name(void);
	DriveSubsystem(CORERobot& robot);
	
	// Called before loop at start of Teleop period
	void teleop_init(void);
	
	//Called sequentially during loop, interleaved with other subsystems
	void teleop_joystick(void);
	void teleop_main(void);
	void teleop_motors(void);
};
