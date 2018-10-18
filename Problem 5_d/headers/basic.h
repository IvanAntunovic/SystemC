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
	sc_fifo<int> f1, f2;

	void p1() {

		s.write(5);
		b.write(5);
		//cout << "p1 s: " << s << " b: " << b << endl;
		cout << "p1 => s: " << s << " b: " << b  << endl;
		s = s + x;   b = b + y;
		wait(0, SC_NS);
		//cout << "p1 s: " << s << " b: " << b << endl;
		cout << "p1 => s: " << s << " b: " << b  << endl;

		x = 20; y = 30;
		s = 200; b = 300;
		s = s + x; b = b + y;
		wait(0, SC_NS);
		//cout << "p1 s: " << s << " b: " << b << endl;
		cout << "p1 => s: " << s << " b: " << b  << endl;

		s = 200; b = 300;
		wait(10, SC_NS);
		//cout << "p1 s: " << s << " b: " << b << endl;
		cout << "p1 => s: " << s << " b: " << b  << endl;

		s = s + x; b = b + y;
		wait(10, SC_NS);
		cout << "p1 => s: " << s << " b: " << b  << endl;

		//cout << "p1 s: " << s << " b: " << b << endl;
		s = 220; b = 330;
		wait(10, SC_NS);
		cout << "p1 => s: " << s << " b: " << b  << endl;
		//cout << "p1 s: " << s << " b: " << b << endl;

		cout << "f1.num_available(): " << f1.num_available() << endl;
		cout << "f2.num_available(): " << f2.num_available() << endl;

		cout << "f1: " << endl; f1.print(cout);
		cout << endl << "f2: " << endl; f2.print(cout);


	}

	void p2() {
		for (;;) {
			cout << "p2" << endl;
			f1.write(s); wait();
		}
	}

	void p3() {
		for (;;) {
			cout << "p3" << endl;
			f2.write(b); wait();
		}
	}

	SC_CTOR(Basic) : x(2), y(3) {

		SC_THREAD(p1);
		SC_THREAD(p2);
		sensitive << s;
		SC_THREAD(p3);
		sensitive << b;
		dont_initialize();


	}

};


#endif /* HEADERS_BASIC_H_ */