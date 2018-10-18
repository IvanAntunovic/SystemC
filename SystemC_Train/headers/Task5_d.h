#ifndef _TASK_5D_H_
#define _TASK_5D_H_

#include "systemc.h"

SC_MODULE(Task5_d) {

	sc_event evt1;

	void p1() {
		evt1.notify(10, SC_NS);
		evt1.notify(5, SC_NS);
		evt1.notify();
		evt1.notify(0, SC_NS);
		wait(10, SC_NS);
		evt1.notify(5, SC_NS);
		wait(10, SC_NS);
	}

	void p2() {
		wait(10, SC_NS);
		evt1.cancel();
		evt1.notify();
		wait(10,SC_NS);
	}

	void p3() {
		cout << "evt1 is activated at " << sc_time_stamp() << " delta: " << sc_delta_count() << endl;
	}

	SC_CTOR(Task5_d){

		SC_THREAD(p1);
		SC_THREAD(p2);

		SC_METHOD(p3);
		sensitive << evt1;
		dont_initialize();
	}
};


#endif
