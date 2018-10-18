/*
 * sensitivity.h
 *
 *  Created on: Aug 18, 2018
 *      Author: ivan
 */

#ifndef HEADERS_SENSITIVITY_H_
#define HEADERS_SENSITIVITY_H_

#include <systemc.h>


SC_MODULE(Sensitivity) {

	sc_signal<int> x, y;
	sc_fifo<int> fifo;
	sc_event event;

	void p1() {

		cout << "p1: activated" << endl;
		//x = 5;
		//y = 10;

		if ( x.event() ) {
			cout << "p1: x.event() happened at delta: " << sc_delta_count() << endl;
		} else {
			cout << "p1: x.event() has not happened at delta: " << sc_delta_count() << endl;
		}

		fifo.write(1);

		wait(0, SC_NS);

		fifo.write(5);

		cout << endl;


	}

	void p2() {

		cout << "p2: activated" << endl;

	}

	void p3() {


		while (true) {

			wait( fifo.data_written_event() );


			if ( x.event() ) {
				cout << "p3: x.event() happened at delta: " << sc_delta_count() << endl;
			} else {
				cout << "p3: x.event() has not happened at delta: " << sc_delta_count() << endl;
			}

			cout << "p3: activated on the event notification" << endl;

		}


	}

	SC_CTOR(Sensitivity) {

		SC_THREAD(p1);
		SC_METHOD(p2);
		sensitive << x << y;
		SC_THREAD(p3);

	}

};



#endif /* HEADERS_SENSITIVITY_H_ */