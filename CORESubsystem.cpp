#include "CORESubsystem.h"

CORESubsystem::CORESubsystem(void){}

std::string CORESubsystem::name(void){
	return "undefined name";
}

void CORESubsystem::robot_init(void){
	printf("Unimplemented robot_init\n");
}
void CORESubsystem::teleop_init(void){
	printf("Unimplemented teleop_init\n");
}

void CORESubsystem::teleop_joystick(COREJoystick& joystick){
	printf("Unimplemented teleop_inputs\n");
}

void CORESubsystem::teleop_main(void){
	printf("Unimplemented teleop_logic\n");
}

void CORESubsystem::teleop_motors(void){
	printf("Unimplemented teleop_outputs\n");
}

