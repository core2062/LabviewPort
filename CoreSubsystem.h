#include "WPILib.h"
#include "COREJoystick.h"
#include <string>
#ifndef CORESUBSYSTEM_H
#define CORESUBSYSTEM_H

class CORESubsystem{
	public:	
	virtual std::string name(void) = 0;

	CORESubsystem(void);
	
	virtual ~CORESubsystem(void){};	// Suppresses GNU GCC warning. Can be removed under GCC version 4.3
	
	// Called before loop at start of Teleop period
	virtual void robot_init(void);
	virtual void teleop_init(void) = 0;
	
	//Called sequentially during loop, interleaved with other subsystems
	virtual void teleop_joystick(COREJoystick& joystick) = 0;
	virtual void teleop_main(void) = 0;
	virtual void teleop_motors(void) = 0;
};

#endif
