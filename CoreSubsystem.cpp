#include <stdio.h>
#include "WPILib.h"
#include "CoreSubsystem.h"

CoreSubsystem::CoreSubsystem(void){
	return;
}

// Called before loop at start of Teleop period
void CoreSubsystem::teleop_init(void){
	printf("Unimplemented teleop_init\n");
}

//Called sequentially during loop, interleaved with other subsystems
void CoreSubsystem::teleop_joystick(Joystick& joystick1, Joystick& joystick2){
	printf("Unimplemented teleop_joystick\n");
}
void CoreSubsystem::teleop_main(void){
	printf("Unimplemented teleop_main\n");
}
void CoreSubsystem::teleop_motors(void){
	printf("Unimplemented teleop_motors\n");
}
