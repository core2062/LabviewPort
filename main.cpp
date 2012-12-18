#include "WPILib.h"
#include "util.h"


class RobotDemo : public SimpleRobot
{
	// Joysticks
	Joystick joystick1;
	Joystick joystick2;
	
	CANJaguar turret;
	Victor bridgeManipulatorMotor;
	Servo bridgeLock;
	
	// Lift Motors
	Victor liftMotorFront;
	Victor liftMotorBack;
	
	// Sweeper Motors
	Victor sweepMotorLeft;
	Victor sweepMotorRight;
	
	// Shooter Motors
	CANJaguar shooterTop;
	CANJaguar shooterBottom;
	
	// Turret Limit Switches
	DigitalInput turretLimitLeft;
	DigitalInput turretLimitRight;
	
	// Bridge Limit Switches
	DigitalInput bridgeSwitchTop;
	DigitalInput bridgeSwitchBtm;
	
	// Thumbwheel Digits
	DigitalInput thumb1;
	DigitalInput thumb2;
	DigitalInput thumb3;
	
	DriverStation * ds;
	
public:
	RobotDemo(void):
		joystick1(1),
		joystick2(2),
				
		turret(17),
		bridgeManipulatorMotor(4),
		bridgeLock(9),
		
		liftMotorFront(1),
		liftMotorBack(2),
		
		sweepMotorLeft(3),
		sweepMotorRight(5),
		
		shooterTop(11),
		shooterBottom(15),
		
		turretLimitLeft(6),
		turretLimitRight(7),
		
		bridgeSwitchTop(4),
		bridgeSwitchBtm(5),
		
		thumb1(9),
		thumb2(10),
		thumb3(11)
	{
		
		shooterTop.SetSpeedReference(CANJaguar::kSpeedRef_Encoder);
		shooterBottom.SetSpeedReference(CANJaguar::kSpeedRef_Encoder);
		
		shooterTop.ConfigEncoderCodesPerRev(360);
		shooterBottom.ConfigEncoderCodesPerRev(360);
		
		shooterTop.SetPID(1.5,.025,.005);
		shooterBottom.SetPID(1.5,.025,.005);
		ds = DriverStation::GetInstance();
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous(void)
	{
//		myRobot.SetSafetyEnabled(false);
//		myRobot.Drive(0.5, 0.0); 	// drive forwards half speed
//		Wait(2.0); 				//    for 2 seconds
//		myRobot.Drive(0.0, 0.0); 	// stop robot
	}

	void OperatorControl(void)
	{
		Timer bTimer;
		bTimer.Start();
		
		bool bridgeButtonOld = false;
		bool shooterOverride = false;
		
		while(IsOperatorControl() and !IsDisabled()){
			
			// Bridge Manipuator code
			bool bridgeButton = joystick1.GetRawButton(5);
			float bridgeOutput = 0;
			
			if (bridgeButton){
				bridgeOutput = bridgeSwitchBtm.Get() ? 0 : -0.5;
			} else {
				bridgeOutput = bridgeSwitchTop.Get() ? 0 : 0.5;
			}

			if	((ds->GetMatchTime() > 15.5) and (bTimer.Get() >= 0.5)){
				bridgeManipulatorMotor.SetSpeed(bridgeOutput);
			}
			bridgeLock.SetAngle((bridgeButton and bridgeSwitchBtm.Get()) ? 180 : 80);
			
			if (bridgeButtonOld != bridgeButton){
				bTimer.Reset();
			}
			bridgeButtonOld = bridgeButton;
			
			//Shooter Code
			if(joystick2.GetRawButton(4)){
				shooterOverride = true;
			}
			
			if(joystick2.GetRawButton(6)){
				shooterOverride = false;
			}
			
			float throttle = joystick2.GetRawAxis(6);
		}
	}
};

START_ROBOT_CLASS(RobotDemo);

