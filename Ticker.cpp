/*
 * Ticker.cpp
 * Tracks robot time per mode.
 *
 *  Created on: Feb 16, 2014
 *      Author: Vince
 */

#include "Ticker.h"

#ifndef NULL
#define NULL 0
#endif

Ticker::Ticker() {
	m_tickCount = 0;
}

void Ticker::OnTick() {
	//	Because it would take a few years for this ticker to overflow, we don't care to check
	m_tickCount++;
	//	Run/kill the current tick task if present
	if (m_currentTickTask != NULL) {
		//	Did this task finish?
		if (m_currentTickTask->IsDone()) {
			//	Remove the finished task
			m_currentTickTask = NULL;
		} else {
			//	Tick the current task
			m_currentTickTask->Tick(m_tickCount);
		}
	}
	//	Run the debug task if present
	if(m_debugTask != NULL) {
		m_debugTask->Tick(m_tickCount);
	}
}

void Ticker::Reset() {
	m_tickCount = 0;
	m_currentTickTask = NULL;
}

bool Ticker::TickHasPassed(uint32_t val) {
	return val <= m_tickCount;
}

int32_t Ticker::TicksElapsedSince(uint32_t val) {
	return m_tickCount - val;
}

Ticker::~Ticker() {
	
}


