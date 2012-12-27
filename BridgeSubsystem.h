#include "CoreSubsystem.h"

class BridgeSubsystem : public CoreSubsystem{
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
	
	BridgeSubsystem(void);
	
	void teleop_init(void);
	
	void teleop_joystick(Joystick& joystick1, Joystick& joystick2);
	void teleop_main(void);
	void teleop_motors(void);
};
