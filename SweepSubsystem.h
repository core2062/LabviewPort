#include "CORESubsystem.h"

class SweepSubsystem : public CORESubsystem{

	Jaguar	rightMotor;
	Jaguar	leftMotor;
	bool	button1;
	float	speed;
	
public:
	std::string name;

	SweepSubsystem(void);
	
	void teleop_init(void);
		
	void teleop_joystick(Joystick& joystick1, Joystick& joystick2);
	void teleop_main(void);
	void teleop_motors(void);
};
