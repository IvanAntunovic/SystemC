#include "watch.h"

void Watch::incrementSeconds(void) {

	mSecondsCounter.count();
	if (mSecondsCounter.overflow()) {

		mNextMinuteEvent.notify();

	}

}

void Watch::incrementMinutes(void) {

	mMinutesCounter.count();
	if (mMinutesCounter.overflow()) {

		mNextHourEvent.notify();

	}

}

void Watch::incrementHours(void) {

	mHoursCounter.count();
	mHoursCounter.overflow(); // to reset the overflow flag

}

void Watch::writeTime(void) {

	cout << mHoursCounter.read() << ":" << mMinutesCounter.read() << ":" << mSecondsCounter.read() << endl;

}
