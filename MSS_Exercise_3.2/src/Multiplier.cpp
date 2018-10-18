#include "Multiplier.h"

void Multiplier::multiplyHandler() {

	while (true) {

		mOutputPort.write( ( mInputPort.read() * K ) );
		wait(10, SC_NS);
	}

}
