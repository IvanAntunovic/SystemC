#include "Decimator.h"

void Decimator::decimationHandler() {

	int readVal;

	while (true) {

		readVal = mInputPort.read();

		mInputValCounter++;
		if (mInputValCounter % 10 == 0) {

			mOutputPort.write(readVal);
			//cout << "Decimator::decimatorHandler -> Read value: " << readVal << endl;

		} else {

			//cout << "Decimator::decimatorHandler -> Discarded value: " << readVal << endl;
		}

	}

}