/*
 * EventTest.h
 *
 *  Created on: Aug 10, 2018
 *      Author: ivan
 */

#ifndef HEADERS_EVENTTEST_H_
#define HEADERS_EVENTTEST_H_

#include <systemc.h>

SC_MODULE(EventTest) {

	sc_event evt1;

	void p1() {

		cout << "p1: before wait " << sc_time_stamp() << endl;

		evt1.notify(10, SC_NS);
		evt1.notify(5, SC_NS);
		cout << "p1: before wait evt1.notify() " << sc_time_stamp() << endl;
		evt1.notify();
		cout << "p1: after wait evt1.notify() " << sc_time_stamp() << endl;
		evt1.notify(0, SC_NS);
		wait(10, SC_NS);
		cout << "p2: evt1.notify(5, SC_NS); before " << sc_time_stamp() << endl;
		evt1.notify(5, SC_NS);

		wait(10, SC_NS);
		cout << "p2: evt1.notify(5, SC_NS); after " << sc_time_stamp() << endl;

	}

	void p2() {

		cout << "p2: before wait " << sc_time_stamp() << endl;

		wait(10, SC_NS);
w
		cout << "p2: after wait " << sc_time_stamp() << endl;
		evt1.cancel();
		evt1.notify();
		wait(10, SC_NS);

	}

	void p3() {

		cout << "p3: " << sc_time_stamp() << endl;

		cout << "evt1 is activated at " << sc_time_stamp() << endl;

	}

	SC_CTOR(EventTest) {

		SC_THREAD(p1);
		SC_THREAD(p2);
		SC_METHOD(p3);
		sensitive << evt1;
		dont_initialize();

	}
};


#endif /* HEADERS_EVENTTEST_H_ */
