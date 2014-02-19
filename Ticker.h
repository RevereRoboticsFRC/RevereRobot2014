/*
 * Ticker.h
 * Tracks robot time per mode.
 *
 *  Created on: Feb 14, 2014
 *      Author: Vince
 */

#ifndef TICKER_H_
#define TICKER_H_

#include "TickerTask.h"
//#include <cstdlib>

//	Don't know why it doesn't understand int32_t in this file only...
//	So define it
#ifndef int32_t
typedef long int32_t;
#endif

//	Another forward declaration because C++ plz.
class TickerTask;

static const float TICK_LENGTH_MS = 20.0;
static const float TICK_LENGTH_SEC = 0.02;

class Ticker {
public:
	/**
	 * Number of ticks that have elapsed during the current mode.
	 */
	uint32_t m_tickCount;

	/**
	 * The current TickerTask that is run every tick.
	 */
	TickerTask* m_currentTickTask;

	/**
	 * The debug TickerTask that is run every tick.
	 */
	TickerTask* m_debugTask;

	Ticker();
	/**
	 * Called every tick (e.g. by TeleopTick())
	 */
	void OnTick();
	/**
	 * Resets the system, called when modes change (e.g. by OnTeleop());
	 */
	void Reset();
	/**
	 * Returns the number of ticks that have elapsed since val (if negative, how many ticks are left until tickCount equals val)
	 */
	int32_t TicksElapsedSince(uint32_t val);
	/**
	 * Whether or not the specified tick val has occurred.
	 */
	bool TickHasPassed(uint32_t val);

	~Ticker();
};

/**
 * Converts ticks to seconds.
 */
static float TicksToSeconds(uint32_t ticks) {
	return ticks * TICK_LENGTH_SEC;
}
/**
 * Converts seconds to ticks. If seconds is negative, it is forced positive.
 */
static uint32_t SecondsToTicks(float seconds) {
	if (seconds < 0.0) {
		seconds *= -1.0;
	}
	return (uint32_t) (seconds / TICK_LENGTH_SEC);
}

#endif /* TICKER_H_ */
