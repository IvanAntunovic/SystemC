/*
 * watch.h
 *
 *  Created on: Aug 19, 2018
 *      Author: ivan
 */

#ifndef HEADERS_WATCH_H_
#define HEADERS_WATCH_H_

#include <systemc.h>
#include <counter.h>

SC_MODULE(Watch) {

	Counter secCounter;
	Counter minCounter;
	Counter hourCounter;

	sc_in<bool> clock;
	sc_event next_minute;
	sc_event next_hour;

	SC_CTOR(Watch) : secCounter(60), minCounter(60), hourCounter(24) {

		SC_THREAD( incSecProcess );
		sensitive << clock.pos();
		SC_THREAD( displayTimeProcess );
		sensitive << clock.neg();

		SC_THREAD(incHourProcess);
		SC_THREAD(incMinProcess);


	}

	void incSecProcess () {

		while (true) {

			wait( );

			if ( clock.event() ) {

				secCounter.count();

				if (secCounter.overflow()) {

					next_minute.notify();

				}

			}
		}

	}

	void incMinProcess() {

		while (true) {

			wait( next_minute );

			minCounter.count();

			if (minCounter.overflow()) {

				next_hour.notify();

			}

		}

	}

	void incHourProcess() {

		while (true) {

			wait( next_hour );
			hourCounter.count();

		}
	}

	void displayTimeProcess() {

		while (true) {

			//wait( clock.negedge_event() );
			wait();
			cout << "Time: "    << hourCounter.read() << ":"
								<< minCounter.read() << ":"
								<< secCounter.read() << endl;

		}
	}


};



#endif /* HEADERS_WATCH_H_ */