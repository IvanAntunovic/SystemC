/*
 * Test.h
 *
 *  Created on: Aug 10, 2018
 *      Author: ivan
 */

#ifndef HEADERS_TEST_H_
#define HEADERS_TEST_H_

#include <systemc.h>

SC_MODULE(Test) {

	sc_event e;

	void threadHandler(void) {

		e.notify();
		e.notify(30, SC_NS);
		e.notify(20, SC_NS);
		wait(10, SC_NS);

		e.notify(20, SC_NS);
		wait(30, SC_NS);

		e.notify(20, SC_NS);
		wait(10, SC_NS);

		wait();

		e.notify(0, SC_NS);
		e.notify(5, SC_NS);
		wait(10, SC_NS);

	}

	void methodHandler(void) {

		cout << "e is activated at " << sc_time_stamp() <<  endl;
	}

	SC_CTOR(Test) {
		SC_THREAD(threadHandler);
		SC_METHOD(methodHandler);
		sensitive << e;
		dont_initialize();
	}
};



#endif /* HEADERS_TEST_H_ */
