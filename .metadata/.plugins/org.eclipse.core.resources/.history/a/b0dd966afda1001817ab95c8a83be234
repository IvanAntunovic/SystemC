/*
 * basic.h
 *
 *  Created on: Aug 9, 2018
 *      Author: ivan
 */

#ifndef HEADERS_BASIC_H_
#define HEADERS_BASIC_H_

#include <systemc.h>

SC_MODULE(Basic) {

	int x, y;
	sc_signal<int> s;
	sc_buffer<int> b;
	sc_fifo<int> f;
	sc_fifo<int> f1, f2;

	sc_signal<int> sig1, sig2;

	void p1() {

		/*
		cout << "p1: b.write(1)" << endl;
		b.write(1);
		cout << "p1: b.write(2)" << endl;
		b.write(2);
		cout << "p1: b.write(3)" << endl;
		b.write(3);

		cout << "p1: f.write(1)" << endl;
		f.write(1);
		cout << "p1: f.write(2)" << endl;
		f.write(2);
		cout << "p1: f.write(3)" << endl;
		f.write(3);*/


		wait(10, SC_NS);

	}

	void p2() {
		int data;

		for (;;) {
			f1.write(s); wait();
		}
	}

	void p3() {
		int data;

		for (;;) {
			f2.write(b); wait();
		}
	}

	SC_CTOR(Basic) : x(2), y(3) {

		SC_THREAD(p1);
		SC_THREAD(p2);
		sensitive << s;
		dont_initialize();
		SC_THREAD(p3);
		sensitive << b;
		dont_initialize();

	}

};


#endif /* HEADERS_BASIC_H_ */
