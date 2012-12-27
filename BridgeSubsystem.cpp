#include "CoreSubsystem.h"
#include "WPILib.h"
#include "BridgeSubsystem.h"

BridgeSubsystem::BridgeSubsystem(void):
	bridgeManipulatorMotor(4),
	bridgeLock(9),
	bridgeSwitchTop(4),
	bridgeSwitchBtm(5),
	bTimer()
{ds = DriverStation::GetInstance();};
	
// Called before loop at start of Teleop period
void BridgeSubsystem::teleop_init(void){
	bTimer.Start();
}
	
//Called sequentially during loop, interleaved with other subsystems
void BridgeSubsystem::teleop_joystick(Joystick& joystick1, Joystick& joystick2){
	bridgeButton = joystick1.GetRawButton(5);
}
void BridgeSubsystem::teleop_main(void){
	bridgeOutput = 0;

	if (bridgeButton){
			bridgeOutput = bridgeSwitchBtm.Get() ? 0 : -0.5;
	} else {
			bridgeOutput = bridgeSwitchTop.Get() ? 0 : 0.5;
	}
}
void BridgeSubsystem::teleop_motors(void){

	if ((ds->GetMatchTime() > 15.5) and (bTimer.Get() >= 0.5)){
		bridgeManipulatorMotor.SetSpeed(bridgeOutput);
	}
	bridgeLock.SetAngle((bridgeButton and bridgeSwitchBtm.Get()) ? 180 : 80);

	if (bridgeButtonOld != bridgeButton){
		bTimer.Reset();
	}
	bridgeButtonOld = bridgeButton;
}
