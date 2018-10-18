#ifndef _DECIMATOR_H_
#define _DECIMATOR_H_

#include <systemc.h>

SC_MODULE(Decimator) {

	sc_fifo_in<int> mInputPort;
	sc_fifo_out<int> mOutputPort;

	int mInputValCounter;

	void decimationHandler(void);

	SC_CTOR(Decimator) {

		SC_THREAD(decimationHandler);

		mInputValCounter = 0;

	}

};

#endif
