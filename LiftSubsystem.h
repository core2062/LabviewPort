#include "CoreSubsystem.h"

class LiftSubsystem : public CoreSubsystem{

	Jaguar	frontMotor;
	Jaguar	backMotor;
	bool	button5;
	float	speed;
	
public:
	LiftSubsystem();
	
	void teleop_init(void);
		
	void teleop_joystick(Joystick& joystick1, Joystick& joystick2);
	void teleop_main(void);
	void teleop_motors(void);
};
