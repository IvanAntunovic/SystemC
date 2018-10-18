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

		cout << "p1 s: " << s << " b: " << b << endl;
		s = s + x;   b = b + y;
		wait(0, SC_NS);
		cout << "p1 s: " << s << " b: " << b << endl;

		x = 20; y = 30;
		s = 200; b = 300;
		s = s + x; b = b + y;
		wait(0, SC_NS);
		cout << "p1 s: " << s << " b: " << b << endl;

		s = 200; b = 300;
		wait(10, SC_NS);
		cout << "p1 s: " << s << " b: " << b << endl;

		s = s + x; b = b + y;
		wait(10, SC_NS);

		cout << "p1 s: " << s << " b: " << b << endl;
		s = 220; b = 330;
		wait(10, SC_NS);

		cout << "p1 s: " << s << " b: " << b << endl;

		cout << "f1.num_available(): " << f1.num_available() << endl;

		for (int i = 0; i < f1.num_available(); i++) {

			int data;
			bool flag;

			flag = f1.nb_read(data);
			cout << "f1[" << i << "]: " << data << endl;

			//if (!flag) { break; }
		}

	}

	void p2() {
		for (;;) {
			cout << "p2" << endl;
			f1.write(s); wait();
		}
	}

	void p3() {
		cout << "p3 entered for the 1st time" << endl;
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
