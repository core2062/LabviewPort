#include "CORERobot.h"
#include "util.h"

CORERobot::CORERobot():
	subsystems(){}

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

void CORERobot::teleop(COREJoystick& joystick){
	std::vector<CORESubsystem*>::iterator it;
	for (it = subsystems.begin(); it != subsystems.end(); ++it){
		cout << "tele inputs " << (*it)->name() << endl;
		(*it)->teleop_joystick(joystick);
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
