/*
 * master.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: ivan
 */

#include "master.h"

void Master::action() {

	unsigned data;

	wait(10, SC_NS);

	for (unsigned  addr = start_addr; addr < end_addr; ++addr) {

		data = rand() % 100;
		initiator_port->write(addr, data);
		cout << name() << " write(" << addr << ", " << data << ")"
			 << " at " << sc_time_stamp() << endl;

		wait(1, SC_NS);
	}

	cout << endl;

	for (unsigned addr = start_addr; addr < end_addr; ++addr) {

		initiator_port->read(addr, data);
		cout << name() << " read(" << addr << ", " << data << ")"
			 << " at " << sc_time_stamp() << endl;

		wait(1, SC_NS);
	}


}



