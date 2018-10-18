/*
 * Process.h
 *
 *  Created on: Jun 22, 2018
 *      Author: ivan
 */

#ifndef HEADERS_PROCESS1_H_
#define HEADERS_PROCESS1_H_

#include <systemc.h>

class Process1 : public sc_module {

public:
	sc_fifo_in<int> mInPort;
	sc_fifo_out<int> mOutPort_1, mOutPort_2;

	void processThread(void);

	Process1(sc_module_name moduleName);

};

#endif /* HEADERS_PROCESS_H_ */
