/*
 * DriveSystem.h
 * Provides an interface to the robot's motor system and associated components.
 *
 *  Created on: Feb 14, 2014
 *      Author: Vince
 */

#ifndef DRIVESYSTEM_H_
#define DRIVESYSTEM_H_

#include "RobotMaster.h"

class DriveSystem {
public:
	RobotMaster* m_robotMaster;
	//	Traction System
	Victor* m_leftTractionMotor;
	Victor* m_rightTractionMotor;

	//	Winch System
	//	2014
	Jaguar* m_winchMotor;
	DigitalInput* m_limitSwitchHigh;
	DigitalInput* m_limitSwitchLow;
	
	DriveSystem(RobotMaster*);
	/**
	 * Stops all motors managed by the Drive System.
	 */
	void StopAll();
	/**
	 * Sends debug information to the SmartDashboard at regular intervals.
	 * Should NOT be called every tick except for testing or issue resolution purposes.
	 */
	void DebugInfo();
	/**
	 * Destructor.
	 */
	~DriveSystem();

	//*					*//
	//*	TRACTION MOTORS *//
	//*					*//
	/**
	 * Drives the corresponding traction motors at the specified speeds.
	 * Speed = [-1.0, +1.0] -> [Reverse, Forward]
	 */
	void TractionDrive(float leftSpeed, float rightSpeed);
	/**
	 * Drives both traction motors at the specified speed.
	 * Speed = [-1.0, +1.0] -> [Reverse, Forward]
	 */
	void TractionDrive(float speed) {
		TractionDrive(speed, speed);
	}
	/**
	 * Stops all traction motors.
	 */
	void TractionStop();
	
	/**
	 * Feeds the traction watchdogs by refreshing the current motor value.
	 */
	void TractionFeed();

	//*					*//
	//*	WINCH MOTOR		*//
	//* 2014			*//
	//*					*//
	/**
	 * Drives the winch motor at the specified speed.
	 * Speed = [-1.0, +1.0] -> [Down, Up]
	 */
	void WinchDrive(float speed);
	/**
	 * Stops the winch motor.
	 */
	void WinchStop();
	/**
	 * Feeds the winch watchdog by refreshing the current motor value.
	 */
	void WinchFeed();
};

#endif /* DRIVESYSTEM_H_ */
