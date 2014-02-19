/*
 * RobotInput.cpp
 * Handles input from the joystick to manipulate various different parts of the robot.
 *
 *  Created on: Feb 16, 2014
 *      Author: Vince
 */

#include "RobotInput.h"
#include "WinchTickerTask.cpp"
#include <cmath>

//	2014
//	Key mappings
#define WINCH_STEP_UP_KEY 12
#define WINCH_STEP_DOWN_KEY 11
#define WINCH_FULL_UP_KEY 10
#define WINCH_FULL_DOWN_KEY 9
//	Winch step lengths
#define WINCH_STEP_UP_TICKS 30
#define WINCH_STEP_DOWN_TICKS 30

RobotInput::RobotInput(RobotMaster* rm) {
	m_robotMaster = rm;
}

void RobotInput::TeleopControl() {
	//	Update the key states.
	for (int i = 0; i < MAX_BUTTONS; i++) {
		//	Push the previously new key states to the previous tick
		lastTickKeystate[i] = currentTickKeystate[i];
		//	Update current
		currentTickKeystate[i] = m_robotMaster->m_joystick->GetRawButton(i + 1);
	}
	TractionControl();
	//	2014
	WinchControl();
}

void RobotInput::TractionControl() {
	//	Get us our joystick
	Joystick* joy = m_robotMaster->m_joystick;
	//	Raw direction from joystick
	float directionRaw = joy->GetDirectionDegrees();
	//	Remap angles
	//	[ -80,   80] --------------> [ -45,   45]
	//	[-100,  -80] U [ 80, 100] -> [-135,  -45] U [ 45, 135]
	//	[-180, -100] U [100, 180] -> [-180, -135] U [135, 180]
	if (abs(directionRaw) <= 80) {
		directionRaw = directionRaw / 80.0 * 45.0;
	} else if (abs(directionRaw) < 100.0) {
		if (directionRaw > 0) {
			directionRaw = (((directionRaw - 80.0) / 20.0) * 90.0) + 45.0;
		} else {
			directionRaw = (((directionRaw + 80.0) / 20.0) * 90.0) - 45.0;
		}
	} else {
		if (directionRaw > 0) {
			directionRaw = (((directionRaw - 100.0) / 80.0) * 45.0) + 135.0;
		} else {
			directionRaw = (((directionRaw + 100.0) / 80.0) * 45.0) - 135.0;
		}
	}
	//	Convert to radians and flip
	float directionCorrect = directionRaw * 3.14159 / -180.0;
	float magnitude = joy->GetMagnitude();
	//	Add 0.32 to eliminate deadband if the joystick is not in neutral.
	if (magnitude > 0.15) {
		magnitude += 0.32;
	}
	//	Clamp
	magnitude = Clamp(0.0, 1.0, magnitude);
	//	Map the response curve to a 3/2 power curve
	magnitude = pow(magnitude, 1.5);
	//	Convert polar to Cartesian for the tank drive formula
	float x = cos(directionCorrect) * magnitude;
	float y = sin(directionCorrect) * magnitude;
	//	Intermediate U and V values for calculating final left and right motor speeds
	float u = (1 - abs(x)) * y + y;
	float v = (1 - abs(y)) * x + x;
	//	Convert and drive
	m_robotMaster->m_driveSystem->TractionDrive((u - v) / 2.0, (u + v) / 2.0);
}

void RobotInput::WinchControl() {
	//	Check for on button release
	Ticker* ticker = m_robotMaster->m_ticker;
	if (IsButtonOnUp(WINCH_FULL_DOWN_KEY)) {
		ticker->m_currentTickTask = new WinchTickerTask(
				ticker->m_tickCount, m_robotMaster, false);
	} else if (IsButtonOnUp(WINCH_FULL_UP_KEY)) {
		ticker->m_currentTickTask = new WinchTickerTask(
				ticker->m_tickCount, m_robotMaster, true);
	} else if (IsButtonOnUp(WINCH_STEP_DOWN_KEY)) {
		ticker->m_currentTickTask = new WinchTickerTask(
				ticker->m_tickCount, m_robotMaster, false, WINCH_STEP_DOWN_TICKS);
	} else if (IsButtonOnUp(WINCH_STEP_UP_KEY)) {
		ticker->m_currentTickTask = new WinchTickerTask(
				ticker->m_tickCount, m_robotMaster, true, WINCH_STEP_UP_TICKS);
	}
	m_robotMaster->m_driveSystem->WinchFeed();
}

bool RobotInput::IsButtonDown(uint8_t buttonId) {
	if (buttonId > MAX_BUTTONS || buttonId == 0) {
		return false;
	}
	return currentTickKeystate[buttonId - 1];
}

bool RobotInput::IsButtonOnUp(uint8_t buttonId) {
	if (buttonId > MAX_BUTTONS || buttonId == 0) {
		return false;
	}
	//	Button OnUp occurs when the last tick the button was DOWN (true) and now it is UP (false)
	return (!currentTickKeystate[buttonId - 1]
			&& lastTickKeystate[buttonId - 1]);
}

bool RobotInput::IsButtonOnDown(uint8_t buttonId) {
	if (buttonId > MAX_BUTTONS || buttonId == 0) {
		return false;
	}
	//	Button OnDown occurs when the last tick the button was UP (false) and now it is DOWN (true)
	return (currentTickKeystate[buttonId - 1]
			&& !lastTickKeystate[buttonId - 1]);
}

void RobotInput::DebugInfo() {
	//	Get us our joystick
	Joystick* joy = m_robotMaster->m_joystick;
	SmartDashboard::PutNumber("JoyPosX", joy->GetX(Joystick::kRightHand));
	SmartDashboard::PutNumber("JoyPosY", joy->GetY(Joystick::kRightHand));
	SmartDashboard::PutNumber("JoyMag", joy->GetMagnitude());
	SmartDashboard::PutNumber("JoyDeg", joy->GetDirectionDegrees());
	for (int i = 0; i < 13; i++) {
		SmartDashboard::PutBoolean(FormatString("JoyButton%i", i),
				joy->GetRawButton(i));
	}
}
