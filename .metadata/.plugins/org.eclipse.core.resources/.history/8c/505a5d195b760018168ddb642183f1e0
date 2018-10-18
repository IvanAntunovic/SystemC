/*
 * Testbench.cpp
 *
 *  Created on: Jun 22, 2018
 *      Author: ivan
 */
#include "Testbench.h"

Testbench::Testbench(sc_module_name moduleName) : sc_module(moduleName),
		process_1("Process 1"), process_2("Process 2"), process_3("Process 3"), process_4("Process 4"),
		mChannel_1("Channel 1"), mChannel_2("Channel 2"), mInputChannel("Input Channel") {

	SC_HAS_PROCESS(Testbench);
	SC_THREAD(stimuliThread);
	SC_THREAD(evaluationThread);

	process_1.mInPort.bind(mInputChannel);
	process_1.mOutPort_1.bind(mChannel_1);
	process_1.mOutPort_2.bind(mChannel_2);

	process_2.mInPort.bind(mChannel_1);
	process_2.mOutPort.bind(mChannel_3);

	process_3.mInPort.bind(mChannel_2);
	process_3.mOutPort.bind(mChannel_4);

	process_4.mInputPort_1.bind(mChannel_3);
	process_4.mInputPort_2.bind(mChannel_4);
	process_4.mOutPort.bind(mOutputChannel);

}

void Testbench::stimuliThread(void) {

	std::vector<int> stimuliData = {5, 8, 21, 11, 5, 8, 16, 0, 3, 7};
	int index = 0;

	while (true) {

		mInputChannel.write(stimuliData[index]);
		//cout << "Testbench::stimuliThread -> Written value to Input Channel: " << stimuliData[index] << endl;

		if ( index >= stimuliData.size() - 1 ) break;
		index++;

		wait(10, SC_SEC);

	}
}

void Testbench::evaluationThread(void) {

	int readVal;

	while (true) {

		readVal = mOutputChannel.read();
		cout << "Testbench::evaluationThread: "
				<< readVal << endl;

	}

}



