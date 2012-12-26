#include "WPILib.h"
#include "util.h"
#include <string>
#include <stdio.h>

#include "DriveSubsystem.h"
#include "TurretSubsystem.h"
#include "LiftSubsystem.h"
#include "SweepSubsystem.h"
#include "BridgeSubsystem.h"
#define SSNUM 5

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
		subsystems[0] = drive;
		subsystems[1] = turret;
		subsystems[2] = lift;
		subsystems[3] = sweep;
		subsystems[4] = bridge;
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
		
		for (int i = 0; i < SSNUM; ++i) {
			subsystems[i].teleop_init();
			if(check_and_break("init ", i)){return;}
			wd.Feed();
		}
		
		while(IsOperatorControl() and !IsDisabled()){
			for (int i = 0; i < SSNUM; ++i){
				subsystems[i].teleop_joystick(joystick1,joystick2);
				if(check_and_break("joystick ", i)){return;}
				wd.Feed();
			}
			for (int i = 0; i < SSNUM; ++i){
				subsystems[i].teleop_main();
				if(check_and_break("main ", i)){return;}
				wd.Feed();
			}
			for (int i = 0; i < SSNUM; ++i){
				subsystems[i].teleop_motors();
				if(check_and_break("motors ", i)){return;}
				wd.Feed();
			}
		}
		
	}
	bool check_and_break(std::string string, int num){
		if ( !( IsOperatorControl() and !IsDisabled() ) ){
			cout << string << num;
			return true;
		}
		return false;
	}
};

START_ROBOT_CLASS(RobotDemo);

