/*
 * Testbench.cpp
 *
 *  Created on: Jun 22, 2018
 *      Author: ivan
 */
#include "Testbench.h"

Testbench::Testbench(sc_module_name moduleName) : sc_module(moduleName), mSource("Source") ,mDecimator("Decimator", 10) {

	SC_HAS_PROCESS(Testbench);
	//SC_THREAD(stimuliThread);
	//SC_THREAD(checkThread);

	for (int i = 0; i < ADDERS_SIZE; ++i) {
		mAdders[i] = new Adder("Adder");
	}

	mMultipliers[0] = new Multiplier("Multiplier_0", -3);
	mMultipliers[1] = new Multiplier("Multiplier_1", -2);

	for (int i = 0; i < ARCS_SIZE; ++i) {
		mArcs[i] = new sc_fifo<int>();
	}

	this->initUut();
}

Testbench::~Testbench() {

	delete[] mAdders;
	delete[] mArcs;
	delete[] mMultipliers;

}

void Testbench::initUut(void) {

	mSource.mOutPort.bind(*mArcs[0]);
	mSource.mOutPort.bind(*mArcs[1]);
	mSource.mOutPort.bind(*mArcs[2]);

	mAdders[0]->mInPort_1.bind(*mArcs[1]);
	mAdders[0]->mInPort_2.bind(*mArcs[2]);
	mAdders[0]->mOutPort.bind(*mArcs[3]);

	mAdders[1]->mInPort_1.bind(*mArcs[0]);
	mAdders[1]->mInPort_2.bind(*mArcs[3]);
	mAdders[1]->mOutPort.bind(*mArcs[4]);

	mAdders[2]->mInPort_1.bind(*mArcs[4]);
	mAdders[2]->mInPort_2.bind(*mArcs[5]);
	mAdders[2]->mOutPort.bind(*mArcs[6]);

	mAdders[3]->mInPort_1.bind(*mArcs[6]);
	mAdders[3]->mInPort_2.bind(*mArcs[7]);
	mAdders[3]->mOutPort.bind(*mArcs[8]);
	mAdders[3]->mOutPort.bind(*mArcs[9]);
	mAdders[3]->mOutPort.bind(*mArcs[10]);

	mMultipliers[0]->mInputPort.bind(*mArcs[9]);
	mMultipliers[0]->mOutputPort.bind(*mArcs[5]);

	mMultipliers[1]->mInputPort.bind(*mArcs[8]);
	mMultipliers[1]->mOutputPort.bind(*mArcs[7]);

	mDecimator.mInputPort.bind(*mArcs[10]);
	mDecimator.mOutputPort.bind(*mArcs[11]);

}

void Testbench::stimuliThread(void) {

	while (true) {

		for (int i = 0; i < 10; i++) {

			cout << sc_module::name() << " Writing " << i << endl;
			mInputChannel_1.write(i);
			mInputChannel_2.write(i);
			mMultiInputChannel.write(i);
			wait(10, SC_SEC);
		}

	}
}

void Testbench::checkThread(void) {

	int readVal;

	while (true) {

		readVal = mOutputChannel.read();
		cout << "Testbench::evaluationThread: ADDER: "
				<< readVal << endl;

		cout << "Testbench::evaluationThread: MULTIPLIER: "
						<< mMultiOutChannel.read() << endl << endl;

	}

}



