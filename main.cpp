#include "WPILib.h"
#include "util.h"
#include <string>
#include <stdio.h>

#include "DriveSubsystem.h"
#include "TurretSubsystem.h"
#include "LiftSubsystem.h"
#include "SweepSubsystem.h"
#include "BridgeSubsystem.h"
#define SSNUM 1

class RobotDemo : public SimpleRobot
{
	Joystick joystick1;
	Joystick joystick2;
	
	DriveSubsystem drive;
	TurretSubsystem turret;
	LiftSubsystem lift;
	SweepSubsystem sweep;
	BridgeSubsystem bridge;
	
	CoreSubsystem subsystems [SSNUM];
public:
	RobotDemo(void):
		joystick1(1),
		joystick2(2),
		drive(),
		turret(),
		lift(),
		sweep(),
		bridge()
	{
//		subsystems[0] = drive;
//		subsystems[1] = turret;
//		subsystems[2] = lift;
//		subsystems[3] = sweep;
//		subsystems[4] = bridge;
	}

	void Autonomous(void)
	{
		//Nope.avi
		Wait(.005);
	}

	void OperatorControl(void)
	{
		Watchdog &wd = GetWatchdog();
		wd.SetEnabled(true);
		wd.SetExpiration(1);
		
//		for (int i = 0; i < SSNUM; ++i) {
//			subsystems[i].teleop_init();
//			drive.teleop_init();
//			if(check_and_break("init ", i)){return;}
//			wd.Feed();
//		}
		
		drive.teleop_init();
		turret.teleop_init();
		lift.teleop_init();
		sweep.teleop_init();
		bridge.teleop_init();
		
		
		while(IsOperatorControl() and !IsDisabled()){
//			for (int i = 0; i < SSNUM; ++i){
//				subsystems[i].teleop_joystick(joystick1,joystick2);
////				drive.teleop_joystick(joystick1, joystick2);
//				if(check_and_break("joystick ", i)){return;}
//				wd.Feed();
//			}
//			for (int i = 0; i < SSNUM; ++i){
//				subsystems[i].init
//				if(check_and_break("main ", i)){return;}
//				wd.Feed();
//			}
//			for (int i = 0; i < SSNUM; ++i){
//				subsystems[i].teleop_motors();
//				if(check_and_break("motors ", i)){return;}
//				wd.Feed();
//			}
			
			drive.teleop_joystick(joystick1, joystick2);
			turret.teleop_joystick(joystick1, joystick2);
			lift.teleop_joystick(joystick1, joystick2);
			sweep.teleop_joystick(joystick1, joystick2);
			bridge.teleop_joystick(joystick1, joystick2);
			
			drive.teleop_main();
			turret.teleop_main();
			lift.teleop_main();
			sweep.teleop_main();
			bridge.teleop_main();
			
			drive.teleop_motors();
			turret.teleop_motors();
			lift.teleop_motors();
			sweep.teleop_motors();
			bridge.teleop_motors();
			
			wd.Feed();
			
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

START_ROBOT_CLASS(RobotDemo);

