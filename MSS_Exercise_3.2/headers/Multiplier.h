#ifndef _MULTIPLIER_H_
#define _MULTIPLIER_H_

#include "systemc.h"

SC_MODULE(Multiplier) {

	sc_fifo_in<int> mInputPort;
	sc_fifo_out<int> mOutputPort;
	int K;

	void multiplyHandler(void);

	Multiplier(sc_module_name moduleName, int constantVal) : sc_module(moduleName), K(constantVal) {

		SC_HAS_PROCESS(Multiplier);
		SC_THREAD(multiplyHandler);

	}

};

#endif


