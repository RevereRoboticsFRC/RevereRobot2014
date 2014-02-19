#include "WPILib.h"
#include "RobotMaster.h"

class RobotDemo: public IterativeRobot {
	RobotMaster* robotMaster;
public:
	RobotDemo() 
	{
		//	Set our interval to 20 milliseconds.
		SetPeriod(0.02);
		
		//	Create and hand over control.
		robotMaster = new RobotMaster(m_ds, &m_watchdog);
	}

	/**
	 * Robot startup
	 */
	void RobotDemo::RobotInit() {
		robotMaster->OnInit();
	}

	/**
	 * Enter disabled
	 */
	void RobotDemo::DisabledInit() {
		robotMaster->OnDisable();
	}

	/**
	 * Disabled tick
	 */
	void RobotDemo::DisabledPeriodic() {
		robotMaster->DisableTick();
	}

	/**
	 * Enter Auton
	 */
	void RobotDemo::AutonomousInit() {
		robotMaster->OnAuton();
	}

	/**
	 * Auton tick
	 */
	void RobotDemo::AutonomousPeriodic() {
		robotMaster->AutonTick();
	}

	/**
	 * Enter Teleop
	 */
	void RobotDemo::TeleopInit() {
		robotMaster->OnTeleop();
	}

	/**
	 * Teleop tick
	 */
	void RobotDemo::TeleopPeriodic() {
		robotMaster->TeleopTick();
	}

	/**
	 * Enter Test
	 */
	void RobotDemo::TestInit() {
		robotMaster->OnTest();
	}

	/**
	 * Test tick
	 */
	void RobotDemo::TestPeriodic() {
		robotMaster->TestTick();
	}
	
	~RobotDemo() {
		delete robotMaster;
		robotMaster = NULL;
	}

};

START_ROBOT_CLASS(RobotDemo)
;

