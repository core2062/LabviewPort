#include "CORESubsystem.h"

class TurretSubsystem : public CORESubsystem{

	Jaguar motor;
	
	DigitalInput leftLimit;
	DigitalInput rightLimit;
	
	bool is_autoaim;
	bool leftValue;
	bool rightValue;
	float speed;
	float gain;
	float rotation;	
	
public:
	std::string name(void);

	TurretSubsystem(void);
	
	void teleop_init(void);
		
		//Called sequentially during loop, interleaved with other subsystems
	void teleop_joystick(COREJoystick& joystick);
	void teleop_main(void);
	void teleop_motors(void);
};
