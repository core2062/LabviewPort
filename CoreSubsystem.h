#include "WPILib.h"
#include "JoystickCache.h"
#include <string>

#ifndef CORESUBSYSTEM_H
#define CORESUBSYSTEM_H
using namespace CORE;

namespace CORE {
class CORESubsystem;

class CORERobot {
	std::vector<CORESubsystem*> subsystems;
public:
	JoystickCache joystick;
	CORERobot():
		subsystems(),
		joystick()
	{}
	
	void add(CORESubsystem& subsystem);
	
	std::vector<CORESubsystem*>& get_subsystems(void);
	
	void robot_init(void);
	void teleop_init(void);
	
	void teleop(void);
};

class CORESubsystem{
	public:	
	virtual std::string name(void) = 0;
	CORERobot& robot;
	CORESubsystem(CORERobot& robot):
	robot(robot)
	{}
	
	
	virtual ~CORESubsystem(){};	// Suppresses GNU GCC warning. Can be removed under GCC version 4.3
	
	// Called before loop at start of Teleop period
	virtual void robot_init(void);
	
	virtual void teleop_init(void) = 0;
	
	//Called sequentially during loop, interleaved with other subsystems
	virtual void teleop_joystick(void) = 0;
	virtual void teleop_main(void) = 0;
	virtual void teleop_motors(void) = 0;
};
}
#endif
