/*
 * ram.cpp
 *
 *  Created on: Jun 23, 2018
 *      Author: ivan
 */
#include "ram.h"

void Ram::write( unsigned addr, unsigned  data )
{
  if( (addr < start) || (addr >= start + this->size) )
    cout << name() << " write(" << addr << ", __) : ERROR address out of range"
    << endl;
  else
    mem[addr-start] = data;
}

void Ram::read(  unsigned addr, unsigned &data )
{
  if( (addr < start) || (addr >= start + this->size) )
    cout << name() << " read(" << addr << ", __) : ERROR address out of range"
    << endl;
  else
    data = mem[addr-start];
}


void Ram::dump(ostream& os) {

	for (unsigned i = 0; i < this->size; i++) {

		os << "Memory[" << i << "]: " << this->mem[i] << endl;

	}
}



