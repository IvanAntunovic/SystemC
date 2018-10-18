/*
 * Process3.cpp
 *
 *  Created on: Jun 22, 2018
 *      Author: ivan
 */

#include "Process3.h"

Process3::Process3(sc_module_name moduleName) : sc_module(moduleName),
		mInputPort_1("Input_Port_1"), mInputPort_2("Input_Port_2"), mOutPort("Output_Port") {

	SC_HAS_PROCESS(Process3);
	SC_THREAD(processThread);

}

void Process3::processThread(void) {

	int inputValue;
	bool switch_ = true;

	while (true) {

		if (switch_) {

			inputValue = mInputPort_1.read();
			//cout << sc_module::name() << "\n\t-Read Value from Inpurt Port 1: " << inputValue << endl;

		} else {

			inputValue = mInputPort_2.read();
			//cout << sc_module::name() << "\n\t-Read Value from Inpurt Port 1: " << inputValue << endl;

		}

		//cout << "Writing Value to Output Port: " << inputValue << endl;
		mOutPort.write(inputValue);
		switch_ = !switch_;

	}

}

