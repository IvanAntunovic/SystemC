#ifndef _DECIMATOR_H_
#define _DECIMATOR_H_

#include <systemc.h>

class Decimator : sc_module {

public:
	sc_fifo_in<int> mInputPort;
	sc_fifo_out<int> mOutputPort;
	int mInputValCounter;
	int mModulus;

	void decimationHandler(void);
	Decimator(sc_module_name, int);

};

#endif
