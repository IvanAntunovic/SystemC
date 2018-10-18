/*
 * Adder.h
 *
 *  Created on: Jun 22, 2018
 *      Author: ivan
 */

#ifndef HEADERS_ADDER_H_
#define HEADERS_ADDER_H_

#include <systemc.h>

class Adder : public sc_module {

public:
	sc_fifo_in<int> mInPort_1, mInPort_2;
	sc_fifo_out<int> mOutPort;

	Adder(sc_module_name);
	void add(void);
};



#endif /* HEADERS_ADDER_H_ */
