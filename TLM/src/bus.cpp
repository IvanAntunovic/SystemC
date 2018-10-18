/*
 * bus.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: ivan
 */
#include "bus.h"

void Bus::write(unsigned addr, unsigned data) {

	bus_port[ decode_address(addr) ]->write(addr, data);


}

void Bus::read(unsigned addr, unsigned& data) {

	bus_port[ decode_address(addr) ]->read(addr, data);

}


unsigned Bus::decode_address(unsigned addr) {

	for( int slave_device_num = 0; slave_device_num < bus_port.size(); slave_device_num++ )
	{
		if( (addr >= starts[slave_device_num]) && (addr <= ends[slave_device_num]) ) return slave_device_num;
	}

	cout << "Bus ERROR: address " << addr << " not found" << ""<<endl;

	return 0;
}

void Bus::end_of_elaboration() {

	unsigned i, slave_start, slave_end;
	ifstream mem_map("mem_map.txt");
	unsigned slaves = bus_port.size();
	starts = new unsigned[slaves];
	ends = new unsigned[slaves];

	mem_map >> i;
	while( mem_map ) {

		mem_map >> slave_start >> slave_end;

		if( i >= slaves ) {
			cout << "Bus ERROR: slave number does not exist" << endl;
			sc_stop();

		} else {
			starts[i] = slave_start;
			ends[i] = slave_end;
			cout << "Bus slave " << i << " starts "
					<< slave_start << " ends " << slave_end << endl;
		}

		mem_map >> i;
	}

	cout << endl;

}


