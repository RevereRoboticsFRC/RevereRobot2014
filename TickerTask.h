/*
 * TickerTask.h
 * A task to be executed in a timeslice fashion over multiple ticks.
 *
 *  Created on: Feb 14, 2014
 *      Author: Vince
 */

#ifndef TICKERTASK_H_
#define TICKERTASK_H_

#include "RobotMaster.h"

//	Don't know why it doesn't understand uint32_t in this file only...
//	So define it
#ifndef uint32_t
typedef unsigned long uint32_t;
#endif

class TickerTask {
public:
	RobotMaster* m_robotMaster;
	/**
	 * Whether or not the task has terminated.
	 */
	bool m_isDone;
	/**
	 * The tick number that this task began on.
	 */
	uint32_t m_startingTick;

	TickerTask(uint32_t tick, RobotMaster* rm) {
		m_robotMaster = rm;
		m_startingTick = tick;
		m_isDone = false;
	}

	/**
	 * Override this to perform actions per tick.
	 */
	virtual void OnTick(uint32_t tickNum) = 0;

	void Tick(uint32_t currTick) {
		if (currTick < m_startingTick) {
			m_isDone = true;
			//	TODO Print error about traveling back in time
			return;
		}
		OnTick(currTick - m_startingTick);
	}
	bool IsDone() {
		return m_isDone;
	}
	virtual int GetId() = 0;
	virtual ~TickerTask() {
	}
};

#endif /* TICKERTASK_H_ */
