/*
 * Process.cpp
 *
 *  Created on: Jun 22, 2018
 *      Author: ivan
 */

#include <Process1.h>

Process1::Process1(sc_module_name moduleName) : sc_module(moduleName),
	mInPort("Input_Port"), mOutPort_1("Output_port_1"), mOutPort_2("Output_port_2") {

	SC_HAS_PROCESS(Process1);
	SC_THREAD(processThread);
}

void Process1::processThread(void) {

	int inputData;

	while (true) {

		inputData = mInPort.read();

		if (inputData % 2 == 0) {
			mOutPort_1.write(inputData);
			//cout << sc_module::name() << "-> Read value from Input Port: " << inputData
			//		<< ".\nWriting Data to Output Port 1" << endl;
		} else {

			mOutPort_2.write(inputData);
			//cout << sc_module::name() << "-> Read value from Input Port: " << inputData
			//		<< ".\nWriting Data to Output Port 2" << endl;

		}


	}

}

