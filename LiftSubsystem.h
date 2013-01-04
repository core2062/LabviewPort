#include "CORESubsystem.h"

class LiftSubsystem : public CORESubsystem{

	Jaguar	frontMotor;
	Jaguar	backMotor;
	bool	lift_up;
	float	speed;
	
public:
	std::string name(void);
	
	LiftSubsystem();
	
	void teleop_init(void);
		
	void teleop_joystick(COREJoystick& joystick);
	void teleop_main(void);
	void teleop_motors(void);
};
