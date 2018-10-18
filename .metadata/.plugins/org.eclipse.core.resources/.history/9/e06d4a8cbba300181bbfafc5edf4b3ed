/*
 * watch.h
 *
 *  Created on: Jun 13, 2018
 *      Author: ivan
 */

#ifndef HEADERS_WATCH_H_
#define HEADERS_WATCH_H_

#include <systemc.h>
#include <iostream>
#include "counter.h"


class Watch : public sc_module {

	public:
		sc_in<bool> mClock;
		Counter mSecondsCounter, mMinutesCounter, mHoursCounter;
		sc_event mNextMinuteEvent,  mNextHourEvent;

		void incrementSeconds(void);
		void incrementMinutes(void);
		void incrementHours(void);
		void writeTime(void);


		SC_CTOR(Watch) : mSecondsCounter(60), mMinutesCounter(60), mHoursCounter(24) {

			SC_METHOD(incrementSeconds);
			sensitive << mClock.pos();
			sc_module::dont_initialize();

			SC_METHOD(incrementMinutes);
			sensitive << mNextMinuteEvent;
			sc_module::dont_initialize();

			SC_METHOD(incrementHours);
			sensitive << mNextHourEvent;
			sc_module::dont_initialize();

			SC_METHOD(writeTime);
			sensitive << mClock.neg();

		}

};



#endif /* HEADERS_WATCH_H_ */
