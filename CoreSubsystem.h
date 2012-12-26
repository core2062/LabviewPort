#import "WPILib.h"
#ifndef CORESUBSYSTEM_H
#define CORESUBSYSTEM_H

class CoreSubsystem{
	public:
	
	CoreSubsystem(void);
	
	// Called before loop at start of Teleop period
	void teleop_init(void);
	
	//Called sequentially during loop, interleaved with other subsystems
	void teleop_joystick(Joystick& joystick1, Joystick& joystick2);
	void teleop_main(void);
	void teleop_motors(void);
};

#endif
