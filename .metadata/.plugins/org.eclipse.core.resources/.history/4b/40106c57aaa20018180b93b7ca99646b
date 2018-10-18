/*
 * fifo.h
 *
 *  Created on: Aug 18, 2018
 *      Author: ivan
 */

#ifndef FIFO_H_
#define FIFO_H_

#include <systemc.h>

SC_MODULE(Fifo) {

	sc_fifo<int> fifo;
	sc_buffer<int> buffer;
	sc_signal<int> sig;

	void p1() {

		int i = 0;
		while (true) {

			cout << "p1: delta:" << sc_delta_count() << "\t" << sc_time_stamp() << endl;
			fifo.write(i++);
			wait(10, SC_NS);

		}

	}

	void p2() {

		while (true) {

			cout << "p1: delta:" << sc_delta_count() << "\t" << sc_time_stamp() << endl;
			wait( fifo.data_written_event() );
		}

	}

	SC_CTOR(Fifo) {

		SC_THREAD(p1);
		SC_THREAD(p2);

	}
};



#endif /* FIFO_H_ */
