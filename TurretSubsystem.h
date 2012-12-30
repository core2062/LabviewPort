#include "CORESubsystem.h"

class TurretSubsystem : public CORESubsystem{

	CANJaguar motor;
	
	DigitalInput leftLimit;
	DigitalInput rightLimit;
	
	bool button7;
	bool leftValue;
	bool rightValue;
	float speed;
	float gain;
	float axis3;	
	
public:
	std::string name;

	TurretSubsystem(void);
	
	void teleop_init(void);
		
		//Called sequentially during loop, interleaved with other subsystems
	void teleop_joystick(Joystick& joystick1, Joystick& joystick2);
	void teleop_main(void);
	void teleop_motors(void);
};
