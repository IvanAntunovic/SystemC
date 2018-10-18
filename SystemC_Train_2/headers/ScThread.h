/*
 * SCThread.h
 *
 *  Created on: Jun 24, 2018
 *      Author: ivan
 */

#ifndef HEADERS_SCTHREAD_H_
#define HEADERS_SCTHREAD_H_

#include <systemc.h>

class ScThread : public sc_module {

public:

	sc_out<int> mInputPort;

	void action(void) {

		int k;

		while(true) {

			wait(10, SC_NS);
			//k = x.read() * x.read() + y.read() * y.read();
			//k = mInputPort.read();
			//cout << sc_module::name() << " -> Read val: " << k << endl;
			//wait(10, SC_NS);

		}
	}

	ScThread(sc_module_name moduleName) : sc_module(moduleName), mInputPort("Input_Port")
	{

		SC_HAS_PROCESS(ScThread);
		SC_THREAD(action);
		//sensitive << x << y;
		//sensitive << mInputPort;

	}
};


#endif /* HEADERS_SCTHREAD_H_ */
