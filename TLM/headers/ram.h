/*
 * ram.h
 *
 *  Created on: Aug 18, 2018
 *      Author: ivan
 */

#ifndef HEADERS_RAM_H_
#define HEADERS_RAM_H_

#include <systemc.h>
#include "bus_if.h"

class Ram : public sc_module, public bus_if {

public:
	sc_export<bus_if> target_export;
	unsigned* memory;
	unsigned memory_size, start_addr;

	void write(unsigned addr, unsigned data);
	void read(unsigned addr, unsigned& data);

	Ram(sc_module_name mn, unsigned _start_addr, unsigned mem_size) : sc_module(mn), memory_size(mem_size), start_addr(_start_addr)  {

		target_export.bind( *this );
		memory = new unsigned[memory_size];
	}

	~Ram() { delete[] memory; }
};



#endif /* HEADERS_RAM_H_ */
