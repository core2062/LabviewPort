#include "CORESubsystem.h"

class SweepSubsystem : public CORESubsystem{

	Jaguar	rightMotor;
	Jaguar	leftMotor;
	bool	sweep_button;
	float	speed;
	
public:
	std::string name(void);
	SweepSubsystem(CORERobot& robot);
	
	void teleop_init(void);
		
	void teleop_joystick(void);
	void teleop_main(void);
	void teleop_motors(void);
};
