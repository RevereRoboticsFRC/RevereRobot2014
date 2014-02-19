/*
 * WinchTickerTask.cpp
 *
 *  Created on: Feb 18, 2014
 *      Author: Vince
 */
#ifndef WINCHTICKERTASK
#define WINCHTICKERTASK

#include "TickerTask.h"

class WinchTickerTask: public TickerTask {
	/**
	 * Are we going up (TRUE) or down (FALSE)?
	 */
	bool m_goUp;
	/**
	 * Are we operating in step mode?
	 * Step mode means that we stop the winch after a certain amount of time, 
	 * instead of letting the motor run continuously until it hits either limit switch.
	 */
	bool m_step;

	uint32_t m_stepMaxTicks;
public:
	/**
	 * Creates a WinchTickerTask in step mode.
	 */
	WinchTickerTask(uint32_t tick, RobotMaster* rm, bool up, uint32_t maxTicks) :
		TickerTask(tick, rm) {
		m_goUp = up;
		m_step = true;
		m_stepMaxTicks = maxTicks;
	}

	/**
	 * Creates a WinchTickerTask in full/continuous mode.
	 */
	WinchTickerTask(uint32_t tick, RobotMaster* rm, bool up) :
		TickerTask(tick, rm) {
		m_goUp = up;
		m_step = false;
		m_stepMaxTicks = 0;
	}

	void OnTick(uint32_t tickNum) {
		if (m_goUp) {
			//	We're going up
			//	We've finished if the upper limit switch is triggered.
			if (m_robotMaster->m_driveSystem->m_limitSwitchHigh->Get()
			//	Or if we're in step mode and we've exceeded the number of ticks to run
					|| (m_step && tickNum > m_stepMaxTicks)) {
				m_isDone = true;
				return;
			}
			//	Drive up
			m_robotMaster->m_driveSystem->WinchDrive(1.0);
		} else {
			//	We're going down
			//	We've finished if the lower limit switch is triggered.
			if (m_robotMaster->m_driveSystem->m_limitSwitchLow->Get()
			//	Or if we're in step mode and we've exceeded the number of ticks to run
					|| (m_step && tickNum > m_stepMaxTicks)) {
				m_isDone = true;
				return;
			}
			//	Drive down
			m_robotMaster->m_driveSystem->WinchDrive(-1.0);
		}
	}

	int GetId() {
		return 1;
	}
};

#endif
