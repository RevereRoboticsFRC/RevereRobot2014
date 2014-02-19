/*
 * DebugTickerTask.cpp
 *
 *  Created on: Feb 18, 2014
 *      Author: Vince
 */

#ifndef DEBUGTICKERTASK
#define DEBUGTICKERTASK

#include "TickerTask.h"

class DebugTickerTask: public TickerTask {
	/**
	 * The interval (in ticks) that debug values are sent.
	 * e.g. an interval of 5 means every 5 ticks (0, 5, 10, 15, ...)
	 */
	uint32_t m_debugInterval;

public:
	DebugTickerTask(uint32_t tick, RobotMaster* rm, uint32_t debugInterval) :
		TickerTask(tick, rm) {
		m_debugInterval = debugInterval;
	}

	void OnTick(uint32_t tickNum) {
		if (m_debugInterval == 0) {
			if (tickNum == 1) {
				m_robotMaster->m_logger->Fatal("Debug interval cannot be zero!");
			}
			return;
		}
		if (tickNum % m_debugInterval) {
			m_robotMaster->m_driveSystem->DebugInfo();
			m_robotMaster->m_robotInput->DebugInfo();
		}
	}
	
	int GetId() {
		return 0;
	}
};
#endif
