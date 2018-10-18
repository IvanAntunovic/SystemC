/*
 * Source.cpp
 *
 *  Created on: Jun 23, 2018
 *      Author: ivan
 */
#include "Source.h"

Source::Source(sc_module_name moduleName) : sc_module(moduleName) {

	SC_HAS_PROCESS(Source);
	SC_THREAD(threadHandler);

}

void Source::threadHandler(void) {

	while (true) {

		for (int data = 0; data < 100; data++) {

			for (int outputPortNum = 0; outputPortNum < mOutPort.size(); ++outputPortNum) {

				mOutPort[outputPortNum]->write(data);

			}

			wait(10, SC_NS);
		}

	}

}


