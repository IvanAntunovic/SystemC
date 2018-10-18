/*
 * Basic.h
 *
 *  Created on: Jun 24, 2018
 *      Author: ivan
 */

#ifndef HEADERS_BASIC_H_
#define HEADERS_BASIC_H_

#include <systemc.h>

SC_MODULE(Basic) {

	int x, y;
	sc_signal<int> s;
	sc_buffer<int> b;
	sc_fifo<int> f1, f2;

	sc_signal<int> sig;
		sc_buffer<int> buf;
	void p1() {
		sc_fifo_in<int> fifoIn;


		cout << "Sig: " << s << "\tBuf: " << b << endl;
		s = 2; b = 3;
		cout << "Sig: " << s << "\tBuf: " << b << endl;

		cout << "Prije s: " << s << "\tb: " << b << endl;
		s = s + x; b = b + y;
		wait(0, SC_NS);

		x = 20; y = 30;
		s = 200; b = 300;
		s = s + x; b = b + y;
		wait(0, SC_NS);
		cout << "s: " << x << "\tb: " << b << endl;

		s = 200; b = 300;
		wait(10,SC_NS);
		cout << "s: " << x << "\tb: " << b << endl;

		s = s + x; b = b + y;
		wait(10, SC_NS);
		cout << "s: " << x << "\tb: " << b << endl;

		s = 220; b = 330;
		wait(10, SC_NS);
		cout << "s: " << x << "\tb: " << b << endl;

		int t;
		cout << "elements in f1: ";

		while (f1.nb_read(t)) {
			cout << t << " ";
		}
		cout << endl;

		cout << "elements in f2: ";
		while(f2.nb_read(t)) {
			cout << t << " ";
		}


		cout << endl;
	}

	void p2() {

		for (;;) { f1.write(s); wait(); }
	}

	void p3() {
		for(;;) { f2.write(b); wait(); }
	}

	SC_CTOR(Basic) : x(2), y(3) {
		SC_THREAD(p1);
		SC_THREAD(p2);
		sensitive << s;
		SC_THREAD(p3);
		sensitive << b; dont_initialize();
	}


};



#endif /* HEADERS_BASIC_H_ */