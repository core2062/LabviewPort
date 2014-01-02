#include "CORESubsystem.h"


void CORERobot::add(CORESubsystem& subsystem){
	subsystems.push_back(&subsystem);
}

std::vector<CORESubsystem*>& CORERobot::get_subsystems(void){
	return subsystems;
}

void CORERobot::teleop_init(void){
	std::vector<CORESubsystem*>::iterator it;
	for(it = subsystems.begin(); it != subsystems.end(); ++it){
		cout << "tele init " << (*it)->name() << endl;
		(*it)->teleop_init();
	}
}

void CORERobot::robot_init(void){
	std::vector<CORESubsystem*>::iterator it;
		for(it = subsystems.begin(); it != subsystems.end(); ++it){
			cout << "robot init " << (*it)->name() << endl;
			(*it)->robot_init();
		}
}

void CORERobot::teleop(){
	std::vector<CORESubsystem*>::iterator it;
	joystick.update_cache();
	for (it = subsystems.begin(); it != subsystems.end(); ++it){
		cout << "tele inputs " << (*it)->name() << endl;
		(*it)->teleop_joystick();
	}
	for (it = subsystems.begin(); it != subsystems.end(); ++it){
		cout << "tele logic " << (*it)->name() << endl;
		(*it)->teleop_main();
	}
	for (it = subsystems.begin(); it != subsystems.end(); ++it){
		cout << "tele outputs " << (*it)->name() << endl;
		(*it)->teleop_motors();
	}
}


std::string CORESubsystem::name(void){
	return "undefined name";
}

void CORESubsystem::robot_init(void){
	printf("Unimplemented robot_init\n");
}
void CORESubsystem::teleop_init(void){
	printf("Unimplemented teleop_init\n");
}

void CORESubsystem::teleop_joystick(){
	printf("Unimplemented teleop_inputs\n");
}

void CORESubsystem::teleop_main(void){
	printf("Unimplemented teleop_logic\n");
}

void CORESubsystem::teleop_motors(void){
	printf("Unimplemented teleop_outputs\n");
}



