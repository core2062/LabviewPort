#include "CORESubsystem.h"

class BridgeSubsystem : public CORESubsystem{
	Victor bridgeManipulatorMotor;
	Servo bridgeLock;
	
	DigitalInput bridgeSwitchTop;
	DigitalInput bridgeSwitchBtm;
	
	Timer bTimer;
	
	bool bridgeButton;
	bool bridgeButtonOld;
	
	float bridgeOutput;
	
	DriverStation * ds;
public:
	std::string name(void);

	BridgeSubsystem(CORERobot& robot);
	
	void teleop_init(void);
	
	void teleop_joystick();
	void teleop_main(void);
	void teleop_motors(void);
};
