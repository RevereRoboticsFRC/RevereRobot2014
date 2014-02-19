/*
 * RobotInput.h
 * Handles input from the joystick to manipulate various different parts of the robot.
 * 
 *  Created on: Feb 14, 2014
 *      Author: Vince
 */

#ifndef ROBOTINPUT_H_
#define ROBOTINPUT_H_

#include "RobotMaster.h"

#define MAX_BUTTONS 12

class RobotInput {
	bool lastTickKeystate[MAX_BUTTONS];
	bool currentTickKeystate[MAX_BUTTONS];
	RobotMaster* m_robotMaster;
	
	/**
	 * Handles controls for the traction motors.
	 */
	void TractionControl();
	
	/**
	 * 2014: Handles controls for the winch system.
	 */
	void WinchControl();
	
	/**
	 * Checks if a certain button is currently down.
	 */
	bool IsButtonDown(uint8_t);
	/**
	 * Checks if a certain button has just been released this tick (previous tick down, now up).
	 */
	bool IsButtonOnUp(uint8_t);
	/**
	 * Checks if a certain button has just been pressed this tick (previous tick up, now down).
	 */
	bool IsButtonOnDown(uint8_t);
public:
	RobotInput(RobotMaster*);
	/**
	 * Performs input handling during teleop mode.
	 * MUST be called every tick during Teleop mode, otherwise safety timeouts and loss of control may occur.
	 */
	void TeleopControl();

	/**
	 * Sends debug information to the SmartDashboard at regular intervals.
	 * Should NOT be called every tick except for testing or issue resolution purposes.
	 */
	void DebugInfo();
};

#endif /* ROBOTINPUT_H_ */
