/*
 * Process2.cpp
 *
 *  Created on: Jun 22, 2018
 *      Author: ivan
 */
#include "Process2.h"

Process2::Process2(sc_module_name moduleName) : sc_module(moduleName),
	mInPort("Input_Port"), mOutPort("Output_Port") {

	SC_HAS_PROCESS(Process2);
	SC_THREAD(processThread);

}

void Process2::processThread(void) {

	int inputValue;

	while (true) {

		inputValue = mInPort.read();
		//cout << sc_module::name() << " -> Read Value: " << inputValue << endl;

		mOutPort.write(inputValue);

	}
}



