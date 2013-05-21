#include "CORESubsystem.h"

class ShootSubsystem : public CORESubsystem{

	Jaguar	top_motor;
	Jaguar	bottom_motor;
	Jaguar	conveyer_left;
	Jaguar	conveyer_right;
	bool	shoot_button;
	bool	shoot_up;
	bool	shoot_down;
	float	speed;
	
public:
	std::string name(void);
	ShootSubsystem(void);
	
	void teleop_init(void);
		
	void teleop_joystick(COREJoystick& joystick);
	void teleop_main(void);
	void teleop_motors(void);
};
