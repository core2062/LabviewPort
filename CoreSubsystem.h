#import "WPILib.h"
#ifndef CORESUBSYSTEM_H
#define CORESUBSYSTEM_H

class CoreSubsystem{
	public:
	
	CoreSubsystem(void);
	
	virtual ~CoreSubsystem(void){};	// Suppresses GNU GCC warning. Can be removed under GCC version 4.3
	
	// Called before loop at start of Teleop period
	virtual void teleop_init(void);
	
	//Called sequentially during loop, interleaved with other subsystems
	virtual void teleop_joystick(Joystick& joystick1, Joystick& joystick2);
	virtual void teleop_main(void);
	virtual void teleop_motors(void);
};

#endif
