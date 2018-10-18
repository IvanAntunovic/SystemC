/*
 * ParallelProcesses.h
 *
 *  Created on: Aug 18, 2018
 *      Author: ivan
 */

#ifndef HEADERS_PARALLELPROCESSES_H_
#define HEADERS_PARALLELPROCESSES_H_

#include <systemc.h>

SC_MODULE(ParallelProcesses) {

	int a, b;
	sc_signal<int> c, d;

	void p1() {

		a = 0;
		c = 1;
		wait(0, SC_NS);
		a = a + d;
		c = c + b;
	}

	void p2() {

		b = 2;
		d = 4;
		wait(0, SC_NS);
		b = a + c;
		d = c + d;
	}

	SC_CTOR(ParallelProcesses) {


		SC_THREAD(p2);
		SC_THREAD(p1);
	}

};


#endif /* HEADERS_PARALLELPROCESSES_H_ */
