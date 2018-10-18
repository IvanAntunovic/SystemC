/*
 * Testbench.h
 *
 *  Created on: Jun 22, 2018
 *      Author: ivan
 */

#ifndef HEADERS_TESTBENCH_H_
#define HEADERS_TESTBENCH_H_

#include <systemc.h>
#include <Process1.h>
#include <Process2.h>
#include <Process3.h>

class Testbench : public sc_module {

public:
	sc_fifo<int> mInputChannel, mChannel_1, mChannel_2, mChannel_3, mChannel_4, mOutputChannel;
	Process1 process_1;
	Process2 process_2, process_3;
	Process3 process_4;

	Testbench(sc_module_name);
	void stimuliThread(void);
	void evaluationThread(void);

};



#endif /* HEADERS_TESTBENCH_H_ */
