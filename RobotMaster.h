/*
 * RobotMaster.h
 * Contains all the robot's software components
 *
 *  Created on: Feb 14, 2014
 *      Author: Vince
 */

#ifndef ROBOTMASTER_H
#define ROBOTMASTER_H

//	Forward declarations to avoid cyclical dependency/dependency resolution issues
class RobotMaster;
class DriveSystem;
class RobotInput;
class Ticker;

#include "WPILib.h"
#include "Ticker.h"
#include "DriveSystem.h"
#include "RobotInput.h"
#include "Logger.h"
#include "RobotUtils.h"

class RobotMaster {
public:
	Joystick* m_joystick;
	Ticker* m_ticker;
	DriveSystem* m_driveSystem;
	RobotInput* m_robotInput;
	DriverStation* m_driverStation;
	Watchdog* m_watchdog;
	Logger* m_logger;
	
	RobotMaster(DriverStation*, Watchdog*);
	void OnInit();
	void OnDisable();
	void DisableTick();
	void OnTeleop();
	void TeleopTick();
	void OnAuton();
	void AutonTick();
	void OnTest();
	void TestTick();
	~RobotMaster();
};
#endif /* ROBOTMASTER_H_ */
