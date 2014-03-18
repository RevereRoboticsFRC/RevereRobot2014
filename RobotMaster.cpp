/*
 * RobotMaster.cpp
 *
 *  Created on: Feb 16, 2014
 *      Author: Vince
 */
#include "RobotMaster.h"

static const char* ROBOT_NAME = "L'AQUISHA";
static const char* VERSION = "3.0_CC1";

#include "DebugTickerTask.cpp"
#include "2014AutonModeTickerTask.cpp"

void OnReset(RobotMaster*);

RobotMaster::RobotMaster(DriverStation* ds, Watchdog* wd) {
	//	NOTE!!!
	//	A few settings are set in MyRobot.cpp before control is handed over to this class.
	//	Most notably, tick length (20ms).
	m_driverStation = ds;
	m_watchdog = wd;
	m_logger = new Logger(FINE, "Main");
	m_driveSystem = new DriveSystem(this);
	//	Only input: Joystick on port 1
	m_joystick = new Joystick(1);
	m_robotInput = new RobotInput(this);
	m_ticker = new Ticker();
	//	Debug/metrics task
	m_ticker->m_debugTask = new DebugTickerTask(0, this, 10);
}

void RobotMaster::OnInit() {
	m_logger->All("===== ROBOT INIT =====");
	m_logger->All("%s version %s", ROBOT_NAME, VERSION);
	m_logger->All("Compiled on %s at %s", __DATE__, __TIME__);
	m_logger->All("======================");
	m_logger->Info("Init OK");
}

void RobotMaster::OnDisable() {
	OnReset(this);
	m_logger->Info("Robot disabled.");
}

void RobotMaster::DisableTick() {
	m_ticker->OnTick();
	//	Do nothing else.
}

void RobotMaster::OnAuton() {
	OnReset(this);
	m_logger->Info("Starting autonomous mode.");
	//	Set our task to...
	//	2014: Drive forward for a few seconds and stop.
	m_ticker->m_currentTickTask = new AutonModeTickerTask(0, this);
}

void RobotMaster::AutonTick() {
	m_ticker->OnTick();
	//	2014: Do nothing else, the tick task will be running.
}

void RobotMaster::OnTeleop() {
	OnReset(this);
	m_logger->Info("Starting teleoperated mode.");
	//	2014: Do nothing else.
}

void RobotMaster::TeleopTick() {
	m_ticker->OnTick();
	//	Handle input
	m_robotInput->TeleopControl();
}

void RobotMaster::OnTest() {
	OnReset(this);
	m_logger->Info("Entered test mode.");
	//	2014: Do nothing else.
}

void RobotMaster::TestTick() {
	m_ticker->OnTick();
	//	2014: Do nothing else.
}

/**
 * Resets the robot for the next mode.
 */
void OnReset(RobotMaster* rm) {
	rm->m_ticker->Reset();
	rm->m_driveSystem->StopAll();
}

RobotMaster::~RobotMaster() {
	delete m_driveSystem;
	delete m_joystick;
	delete m_robotInput;
	delete m_ticker;
}

