/*
 * master.h
 *
 *  Created on: Aug 18, 2018
 *      Author: ivan
 */

#ifndef HEADERS_MASTER_H_
#define HEADERS_MASTER_H_

#include <systemc.h>
#include "bus_if.h"

SC_MODULE(Master) {

	sc_port<bus_if, 1> initiator_port;
	unsigned start_addr, end_addr;

	void action();

	Master(sc_module_name mn, unsigned start, unsigned end) : sc_module(mn), start_addr(start), end_addr(end) {

		SC_HAS_PROCESS(Master);
		SC_THREAD(action);

	}

};



#endif /* HEADERS_MASTER_H_ */
