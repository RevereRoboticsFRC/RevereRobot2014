/*
 * AutonModeTickerTask.cpp
 *
 *  Created on: Feb 18, 2014
 *      Author: Vince
 */

#ifndef AUTONMODETICKERTASK
#define AUTONMODETICKERTASK

#include "TickerTask.h"

class AutonModeTickerTask: public TickerTask {
	uint32_t m_maxTickValue;
public:
	AutonModeTickerTask(uint32_t tick, RobotMaster* rm) :
		TickerTask(tick, rm) {
		m_maxTickValue = SecondsToTicks(5.0);
	}

	void OnTick(uint32_t tickNum) {
		if (tickNum > m_maxTickValue) {
			m_robotMaster->m_driveSystem->StopAll();
			m_isDone = true;
			return;
		}
		m_robotMaster->m_driveSystem->TractionDrive(1.0);
		m_robotMaster->m_driveSystem->WinchFeed();
	}
	
	int GetId() {
		return 2;
	}
};

#endif
