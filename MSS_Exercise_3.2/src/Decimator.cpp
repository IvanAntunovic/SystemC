#include "Decimator.h"

Decimator::Decimator(sc_module_name moduleName, int modulus) : sc_module(moduleName), mModulus(modulus) {

	SC_HAS_PROCESS(Decimator);
	SC_THREAD(decimationHandler);

	mInputValCounter = 0;

}

void Decimator::decimationHandler() {

	int readVal;

	while (true) {

		readVal = mInputPort.read();

		mInputValCounter++;
		if (mInputValCounter % mModulus == 0) {

			mOutputPort.write(readVal);

		}
	}

}
