#ifndef _RAM_H_
#define _RAM_H_

#include "bus_if.h"
#include "debug_if.h"

class Ram : public sc_module, public bus_if, public debug_if
{
public:
  sc_export<bus_if> target_export;

  unsigned mStart, mSize;
  unsigned *mMem;

  void write( unsigned addr, unsigned  data ) override;
  void read(  unsigned addr, unsigned &data ) override;
  void dump(ostream& os) override;

  Ram( sc_module_name mn, unsigned start_addr, unsigned size )
  : sc_module(mn)
  {
    target_export.bind(*this);
    mStart = start_addr;
    mSize = size;
    mMem = new unsigned[mSize];
  }
  ~Ram() { delete[] mMem; }
};

#endif
