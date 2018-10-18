/*
 * TLM_PV.h
 *
 *  Created on: Aug 18, 2018
 *      Author: ivan
 */

#ifndef HEADERS_TLM_PV_H_
#define HEADERS_TLM_PV_H_

#include <systemc.h>
#include <master.h>
#include <ram.h>
#include <bus.h>

SC_MODULE(TLM_PV) {

	Master master_1, master_2;
	Ram ram_1, ram_2;
	Bus bus;

	TLM_PV(sc_module_name mn) :
		    sc_module(mn),
			master_1("master_1", 0, 17),
			master_2("master_2", 20, 31),
			ram_1("ram_1", 0, 16),
			ram_2("ram_2", 16, 16),
			bus("bus")
	{

		master_1.initiator_port.bind( bus.bus_export );
		master_2.initiator_port.bind( bus.bus_export );
		bus.bus_port.bind( ram_1.target_export );
		bus.bus_port.bind( ram_2.target_export );

	}
};


#endif /* HEADERS_TLM_PV_H_ */
