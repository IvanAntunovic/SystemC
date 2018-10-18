/*
 * EventNotifications.h
 *
 *  Created on: Aug 18, 2018
 *      Author: ivan
 */

#ifndef HEADERS_EVENTNOTIFICATIONS_H_
#define HEADERS_EVENTNOTIFICATIONS_H_

#include <systemc.h>

SC_MODULE(EventNotifications) {

	sc_event e;

	void p1() {

		cout << "p1:\tDelta: " << sc_delta_count() << "\t" << sc_time_stamp() << endl;
		e.notify();
		e.notify(30, SC_NS);
		e.notify(20, SC_NS);
		wait(10, SC_NS);
		cout << "p1:\tDelta: " << sc_delta_count() << "\t" << sc_time_stamp() << endl;

		e.notify(20, SC_NS);
		wait(30, SC_NS),
				cout << "p1:\tDelta: " << sc_delta_count() << "\t" << sc_time_stamp() << endl;

		e.notify(20, SC_NS);
		wait(10, SC_NS);
		cout << "p1:\tDelta: " << sc_delta_count() << "\t" << sc_time_stamp() << endl;

		e.notify(0, SC_NS);
		e.notify(5, SC_NS);
		wait(10, SC_NS);
		cout << "p1:\tDelta: " << sc_delta_count() << "\t" << sc_time_stamp() << endl;
	}

	void p2() {

		cout << "p2:\tDelta: " << sc_delta_count() << "\t" << sc_time_stamp() << endl;
	}

	SC_CTOR(EventNotifications) {

		SC_THREAD(p1);
		SC_METHOD(p2);
		sensitive << e;
		dont_initialize();

	}
};



#endif /* HEADERS_EVENTNOTIFICATIONS_H_ */