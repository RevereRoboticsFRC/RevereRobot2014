/*
 * DriveSystem.cpp
 * Provides an interface to the robot's motor system and associated components.
 *
 *  Created on: Feb 16, 2014
 *      Author: Vince
 */
#include "DriveSystem.h"

DriveSystem::DriveSystem(RobotMaster* rm) {
	m_robotMaster = rm;
	//	TRACTION MOTORS
	//	Port numbers are the numbers on the Digital Sidecar PWM channels.
	m_leftTractionMotor = new Victor(1);
	m_rightTractionMotor = new Victor(2);

	//	WINCH MOTOR
	//	2014
	//	Port number is the number on the Digital Sidecar PWM channel.
	m_winchMotor = new Jaguar(3);

	//	WINCH LIMIT SWITCHES
	//	2014
	//	Port numbers are the numbers on the Digital Sidecar Input channels.
	m_limitSwitchHigh = new DigitalInput(0);
	m_limitSwitchLow = new DigitalInput(1);
}

void DriveSystem::DebugInfo() {
	//	TRACTION MOTORS
	SmartDashboard::PutNumber("trxLeftMotorSpd", m_leftTractionMotor->Get());
	SmartDashboard::PutNumber("trxRightMotorSpd", m_rightTractionMotor->Get());

	//	WINCH MOTOR
	//	2014
	SmartDashboard::PutNumber("winchMotorSpd", m_winchMotor->Get());

	//	WINCH LIMIT SWITCHES
	//	2014
	SmartDashboard::PutBoolean("winchLimSwitchHigh", m_limitSwitchHigh->Get());
	SmartDashboard::PutBoolean("winchLimSwitchLow", m_limitSwitchLow->Get());
}

void DriveSystem::StopAll() {
	//	TRACTION MOTORS
	m_leftTractionMotor->StopMotor();
	m_rightTractionMotor->StopMotor();

	//	WINCH MOTOR
	//	2014
	m_winchMotor->StopMotor();
}

void DriveSystem::TractionDrive(float leftSpeed, float rightSpeed) {
	//	Clamp speed values
	leftSpeed = Clamp(-1.0, 1.0, leftSpeed);
	rightSpeed = Clamp(-1.0, 1.0, rightSpeed);

	//	Consistency note: if the speed argument is positive, the traction motor should drive the robot FORWARD.
	//	If this is not the case...
	//	Uncomment a line to flip that motor's "forward" direction.
	//	leftSpeed *= -1.0;
	//	rightSpeed *= -1.0;

	m_leftTractionMotor->SetSpeed(leftSpeed);
	m_rightTractionMotor->SetSpeed(rightSpeed);
}

void DriveSystem::TractionStop() {
	m_leftTractionMotor->StopMotor();
	m_rightTractionMotor->StopMotor();
}

void DriveSystem::TractionFeed() {
	TractionDrive(m_leftTractionMotor->Get(), m_rightTractionMotor->Get());
}

void DriveSystem::WinchDrive(float speed) {
	//	Clamp speed values
	speed = Clamp(-1.0, 1.0, speed);

	//	Refuse to drive the winch UP if we've hit the UPPER switch
	if (m_limitSwitchHigh->Get() && speed > 0) {
		return;
	}
	//	Refuse to drive the winch DOWN if we've hit the LOWER switch
	if (m_limitSwitchLow->Get() && speed < 0) {
		return;
	}

	//	Consistency note: if the speed argument is positive, the winch motor should pull the arms UP.
	//	If this is not the case...
	//	Uncomment to flip the motor's "up" direction.
	//	speed *= -1.0;

	m_winchMotor->SetSpeed(speed);
}

void DriveSystem::WinchStop() {
	m_winchMotor->StopMotor();
}

void DriveSystem::WinchFeed() {
	WinchDrive(m_winchMotor->Get());
}

DriveSystem::~DriveSystem() {
	//	Deconstruct things here. Do we need it?
}
