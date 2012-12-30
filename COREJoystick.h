#include "WPILib.h"

#ifndef COREJOYSTICK_H
#define COREJOYSTICK_H

class COREJoystick{
public:
	Joystick joystick1;
	Joystick joystick2;
	
	COREJoystick():
		joystick1(1),
		joystick2(2){}
	
	float drive_x(void){return joystick1.GetRawAxis(1);}
	float drive_rotation(void){return joystick1.GetRawAxis(4);}
	float drive_y(void){return joystick1.GetRawAxis(2);}
	
	float rotate_turret(void){return -joystick2.GetRawAxis(3);}
	bool turret_is_autoaim(void){return joystick2.GetRawButton(7);}
	
	bool bridge_manip(void){return joystick1.GetRawButton(5);}
	
	bool lift_up(void){return joystick2.GetRawButton(5);}
	
	bool sweeper(void){return joystick2.GetRawButton(1);}
};

#endif
