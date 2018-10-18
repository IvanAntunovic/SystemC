/*
 * Process3.h
 *
 *  Created on: Jun 22, 2018
 *      Author: ivan
 */

#ifndef HEADERS_PROCESS3_H_
#define HEADERS_PROCESS3_H_

#include <systemc.h>

class Process3 : public sc_module {

public:
	sc_fifo_in<int> mInputPort_1, mInputPort_2;
	sc_fifo_out<int> mOutPort;

	Process3(sc_module_name);
	void processThread(void);

};



#endif /* HEADERS_PROCESS3_H_ */
