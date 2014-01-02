#include "CORESubsystem.h"

static const float keySpeed [] = {.25, .625	};

class ShootSubsystem : public CORESubsystem{

	CANJaguar	topShooter;
	CANJaguar	bottomShooter;
	Jaguar	conveyerLeft;
	Jaguar	conveyerRight;

	double	topSpeed;
	double bottomSpeed;
	bool	active;
	
	bool old_toggle;
	bool old_up;
	bool old_down;
public:
	std::string name(void);
	ShootSubsystem(CORERobot& robot);
	
	void teleop_init(void);
		
	void teleop_joystick(void);
	void teleop_main(void);
	void teleop_motors(void);
};
