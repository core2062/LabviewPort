#include "WPILib.h"
#include "COREJoystick.h"
#include <string>
#ifndef CORESUBSYSTEM_H
#define CORESUBSYSTEM_H

class CORESubsystem{
	public:
	
	std::string name;
	CORESubsystem(void){
		name = "undefined name";
	}
	
	virtual ~CORESubsystem(void){};	// Suppresses GNU GCC warning. Can be removed under GCC version 4.3
	
	// Called before loop at start of Teleop period
	virtual void teleop_init(void){
		printf("Unimplemented teleop_init\n");
	}
	
	//Called sequentially during loop, interleaved with other subsystems
	virtual void teleop_joystick(COREJoystick& joystick){
		printf("Unimplemented teleop_joystick\n");
	}
	virtual void teleop_main(void){
		printf("Unimplemented teleop_main\n");
	}
	virtual void teleop_motors(void){
		printf("Unimplemented teleop_joystick\n");
	}
};

#endif
