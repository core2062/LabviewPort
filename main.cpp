#include <string>
#include <stdio.h>

#include "WPILib.h"
#include "Subsystems.h"
#include "util.h"

/*#define SSNUM 5*/
using namespace CORE;

class LabviewPort : public SimpleRobot{

	CORERobot robot;
	DriveSubsystem drive;
	TurretSubsystem turret;
	ShootSubsystem shooter;
	SweepSubsystem sweep;
	BridgeSubsystem bridge;
	
//	CORESubsystem *subsystems [SSNUM];
public:
	LabviewPort(void):
		robot(),
		drive(robot),
		turret(robot),
		shooter(robot),
		sweep(robot),
		bridge(robot){
		robot.add(drive);
		robot.add(turret);
		robot.add(shooter);
		robot.add(sweep);
		robot.add(bridge);
	}

	void Autonomous(void)
	{
		//Nope.avi
		Wait(.005);
	}

	void RobotInit(void){
		robot.robot_init();
	}
	
	void OperatorControl(void)
	{
		Watchdog &wd = GetWatchdog();
		wd.SetEnabled(true);
		wd.SetExpiration(1);
		
		
		
//		drive.teleop_init();
//		turret.teleop_init();
//		lift.teleop_init();
//		sweep.teleop_init();
//		bridge.teleop_init();
		
		robot.teleop_init();
		
		while(IsOperatorControl() and !IsDisabled()){
			
			robot.teleop();
			
			
			////////////////////////////
			// Array based for loops. 
			////////////////////////////
			
			//	for (int i = 0; i < SSNUM; ++i){
			//		subsystems[i]->teleop_joystick(joystick1,joystick2);
			//		if(check_and_break("joystick ", i)){return;}
			//		wd.Feed();
			//	}
			//	for (int i = 0; i < SSNUM; ++i){
			//		subsystems[i]->teleop_main();
			//		if(check_and_break("main ", i)){return;}
			//		wd.Feed();
			//	}
			//	for (int i = 0; i < SSNUM; ++i){
			//		subsystems[i]->teleop_motors();
			//		if(check_and_break("motors ", i)){return;}
			//		wd.Feed();
			//	}
			
			//////////////////
			// Static calls. 
			//////////////////
			
			
			//	drive.teleop_joystick(joystick1, joystick2);
			//	turret.teleop_joystick(joystick1, joystick2);
			//	lift.teleop_joystick(joystick1, joystick2);
			//	sweep.teleop_joystick(joystick1, joystick2);
			//	bridge.teleop_joystick(joystick1, joystick2);
			//	
			//	drive.teleop_main();
			//	turret.teleop_main();
			//	lift.teleop_main();
			//	sweep.teleop_main();
			//	bridge.teleop_main();
			//	
			//	drive.teleop_motors();
			//	turret.teleop_motors();
			//	lift.teleop_motors();
			//	sweep.teleop_motors();
			//	bridge.teleop_motors();
			
			
			wd.Feed();
			cout << endl << endl;
			Wait(.005);
		}
		
	}
	bool check_and_break(std::string string, int num){
		if ( !( IsOperatorControl() and !IsDisabled() ) ){
			cout << string << num << endl;
			return true;
		}
		return false;
	}
};

START_ROBOT_CLASS(LabviewPort);

