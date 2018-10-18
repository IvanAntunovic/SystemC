#ifndef _RAM_H_
#define _RAM_H_

#include "bus_if.h"
#include "debug_if.h"

class Ram : public sc_module, public bus_if, public debug_if
{
public:
  sc_export<bus_if> target_export;
  void write( unsigned addr, unsigned  data );
  void read(  unsigned addr, unsigned &data );
  unsigned start, size;
  unsigned *mem;

  void dump(ostream& os) override;

  Ram( sc_module_name mn, unsigned start_addr, unsigned size ) : sc_module(mn)
  {
    target_export.bind(*this);
    start = start_addr;
    this->size = size;
    mem = new unsigned[size];
  }

  ~Ram() { delete[] mem; }


};

#endif
