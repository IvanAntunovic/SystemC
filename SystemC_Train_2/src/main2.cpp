/*
 * main2.cpp
 *
 *  Created on: Aug 15, 2018
 *      Author: ivan
 */
#include <systemc.h>

SC_MODULE(Test) {

	void p1(void) {

		while (true) {

			cout << "p1 " << sc_time_stamp() << endl;
			wait(1, SC_NS);
		}

	}

	void p2(void) {

		while (true) {

			cout << "p2 " << sc_time_stamp() << endl;
			wait(2, SC_NS);
		}

	}


	SC_CTOR(Test) {


		SC_THREAD(p1);
		SC_THREAD(p2);

	}
};

int sc_main(int argc, char* argv[]) {

	Test test("test");

	sc_start(1001, SC_NS);

	return 0;
}