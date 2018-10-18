/*
 * Task5_a.h
 *
 *  Created on: Aug 17, 2018
 *      Author: ivan
 */

#ifndef HEADERS_TASK5_A_H_
#define HEADERS_TASK5_A_H_

#include <systemc.h>

SC_MODULE(Task5_a) {

	int x, y;
	sc_signal<int> s;
	sc_signal<int> b;
	sc_fifo<int> f1, f2;

	void p1() {

		cout << "p1: delta: " << sc_delta_count() << "\t" << sc_time_stamp() << "\t" << "s: " << s << "\tb: " << b << endl;
		s = s + x ; b = b + y;

		wait(0, SC_NS);
		cout << "p1: delta: " << sc_delta_count() << "\t" << sc_time_stamp() << "\t" << "s: " << s << "\tb: " << b << endl;
		x = 20; y = 30;
		s = 200; b = 300;
		s = s + x; b = b + y;

		wait(0, SC_NS);
		cout << "p1: delta: " << sc_delta_count() << "\t" << sc_time_stamp() << "\t" << "s: " << s << "\tb: " << b << endl;
		s = 200; b = 300;

		wait(10, SC_NS);
		cout << "p1: delta: " << sc_delta_count() << "\t" << sc_time_stamp() << "\t" << "s: " << s << "\tb: " << b << endl;
		s = s + x; b = b + y;

		wait(10, SC_NS);
		cout << "p1: delta: " << sc_delta_count() << "\t" << sc_time_stamp() << "\t" << "s: " << s << "\tb: " << b << endl;
		s = 220; b = 330;

		wait(10, SC_NS);
		cout << "p1: delta: " << sc_delta_count() << "\t" << sc_time_stamp() << "\t" << "s: " << s << "\tb: " << b << endl;


		int t;
		cout << "elements in f1: ";
		f1.dump(cout);
		cout << endl;

		cout << "elements in f2: ";
		f2.dump(cout);
		cout << endl;

	}

	void p2() {

		for(;;) {

			cout << "p2: delta: " << sc_delta_count() << "\t" << sc_time_stamp() << endl;
			f1.write(s);
			wait();
		}
	}

	void p3() {

		for(;;) {

			cout << "p3: delta: " << sc_delta_count() << "\t" << sc_time_stamp() << endl;
			f2.write(b);
			wait();
		}
	}

	SC_CTOR (Task5_a) : x(2), y(3)  {

		SC_THREAD(p1);
		SC_THREAD(p2);
		sensitive << s;
		SC_THREAD(p3);
		sensitive << b; dont_initialize();
	}
};




#endif /* HEADERS_TASK5_A_H_ */
