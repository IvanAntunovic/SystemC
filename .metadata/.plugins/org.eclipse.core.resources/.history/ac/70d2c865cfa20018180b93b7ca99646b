/*
 * Process2.h
 *
 *  Created on: Jun 22, 2018
 *      Author: ivan
 */

#ifndef HEADERS_PROCESS2_H_
#define HEADERS_PROCESS2_H_

#include <systemc.h>

class Process2 : public sc_module {

public:
	sc_fifo_in<int> mInPort;
	sc_fifo_out<int> mOutPort;

	Process2(sc_module_name);
	void processThread(void);

};



#endif /* HEADERS_PROCESS2_H_ */
