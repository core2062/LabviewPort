#include "CORESubsystem.h"
#include "WPILib.h"
#include "util.h"
#include "ShootSubsystem.h"

std::string ShootSubsystem::name(void){
	return "shoot";
}

ShootSubsystem::ShootSubsystem(CORERobot& robot):
	CORESubsystem(robot),
	topShooter(11, CANJaguar::kPercentVbus),
	bottomShooter(15, CANJaguar::kPercentVbus),
	conveyerLeft(1),
	conveyerRight(2)
{
	topSpeed = 0;
	bottomSpeed = keySpeed[1];
	active = false;
	old_toggle=false;
	old_up=false;
	old_down=false;
}

void ShootSubsystem::teleop_init(void){
//	topShooter.SetPID(1.5, .025, .005);
//	bottomShooter.SetPID(1.5, .025, .005);
//	topShooter.SetSpeedReference(CANJaguar::kSpeedRef_QuadEncoder);
//	bottomShooter.SetSpeedReference(CANJaguar::kSpeedRef_QuadEncoder);
//	topShooter.ConfigEncoderCodesPerRev(360);
//	bottomShooter.ConfigEncoderCodesPerRev(360);
	SmartDashboard::PutNumber("bottom-speed", bottomSpeed);
	SmartDashboard::PutNumber("top-speed", topSpeed);
	
	robot.joystick.register_button("shooter_toggle", 2, 2);
	robot.joystick.register_button("shoot", 2, 5);
	robot.joystick.register_button("key_speed", 2, 3);
	robot.joystick.register_button("speed_up", 2, 6);
	robot.joystick.register_button("speed_down", 2, 4);
	robot.joystick.register_button("convey_down", 2, 12);
	
	SmartDashboard::PutBoolean("shooter_toggle", active);
}
	
void ShootSubsystem::teleop_joystick(void){	
}

void ShootSubsystem::teleop_main(void){
	if(robot.joystick.button("shooter_toggle") && !old_toggle){
		active = !active;
		SmartDashboard::PutBoolean("shooter_toggle", active);
	} else {
		active = SmartDashboard::GetBoolean("shooter_toggle");
	}
	
	if(robot.joystick.button("speed_up") && !old_up){
		topSpeed = fence(topSpeed+ .05, 1, 0);
		bottomSpeed = fence(bottomSpeed + .05, 1, 0);
		SmartDashboard::PutNumber("top-speed", topSpeed);
		SmartDashboard::PutNumber("bottom-speed", bottomSpeed);
	} else if (robot.joystick.button("speed_down") && !old_down) {
		topSpeed = fence(topSpeed - .05, 1, 0);
		bottomSpeed = fence(bottomSpeed - .05, 1, 0);
		SmartDashboard::PutNumber("top-speed", topSpeed);
		SmartDashboard::PutNumber("bottom-speed", bottomSpeed);
	} else if (robot.joystick.button("key_speed")) {
		topSpeed = keySpeed[0];
		bottomSpeed = keySpeed[1];
	} else {
		topSpeed = SmartDashboard::GetNumber("top-speed");
		bottomSpeed = SmartDashboard::GetNumber("bottom-speed");
	}
	old_up = robot.joystick.button("speed_up");
	old_down = robot.joystick.button("speed_down");
	old_toggle = robot.joystick.button("shooter_toggle");	
}

void ShootSubsystem::teleop_motors(void) {
	if(active){
		topShooter.Set(-1 * topSpeed);
		bottomShooter.Set(bottomSpeed);
	} else{
		topShooter.Set(0);
		bottomShooter.Set(0);
	}
//	SmartDashboard::PutNumber("topEnc", topShooter.GetSpeed());
//	SmartDashboard::PutNumber("bottomEnc", bottomShooter.GetSpeed());

	float con = (robot.joystick.button("shoot") ? .75 : (robot.joystick.button(
			"convey_down") ? -.75 : 0));
	conveyerLeft.Set(con);
	conveyerRight.Set(con);
}
