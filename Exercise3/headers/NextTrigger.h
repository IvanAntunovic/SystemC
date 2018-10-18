/*
 * NextTrigger.h
 *
 *  Created on: Aug 18, 2018
 *      Author: ivan
 */

#ifndef HEADERS_NEXTTRIGGER_H_
#define HEADERS_NEXTTRIGGER_H_

#include <systemc.h>

SC_MODULE(NextTrigger) {

	sc_signal<int> sig1;
	sc_signal<int> toggle;

	sc_signal<int>* sigPtr = new sc_signal<int>();

	void t1() {

		sigPtr->write(1);

		cout << "t1 " << endl;
		sig1 = 0;
		wait(10, SC_NS);

		cout << "t1 " << endl;
		sig1 = 2;
		wait(10, SC_NS);

		cout << "t1 toggling" << endl;
		toggle = 2;
		wait(10, SC_NS);

		cout << "t1 " << endl;
		sig1 = -1;
		toggle = -1;
		wait(10, SC_NS);

		cout << "t1 " << endl;
		sig1 = -4;
		wait(10, SC_NS);

	}

	void m1() {

		cout << "m1" << endl;
		if (toggle > 0) {
			next_trigger(sig1.value_changed_event());
		}
	}

	SC_CTOR(NextTrigger) {

		SC_THREAD(t1);
		SC_METHOD(m1);
		sensitive <<  toggle;
	}
};



#endif /* HEADERS_NEXTTRIGGER_H_ */
