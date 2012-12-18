#include <stdio.h>

class CoreSubsystem{
	public:
	
	CoreSubsystem(void){};
	
	// Called before loop at start of Teleop period
	void teleop_init(void){
		printf("Unimplemented teleop_init");
	}
	
	//Called sequentially during loop, interleaved with other subsystems
	void teleop_joystick(void){
		printf("Unimplemented teleop_joystick");
	}
	void teleop_main(void){
		printf("Unimplemented teleop_main");
	}
	void teleop_motors(void){
		printf("Unimplemented teleop_motors");
	}
};
