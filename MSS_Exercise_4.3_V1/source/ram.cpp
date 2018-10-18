#include "ram.h"

void Ram::write( unsigned addr, unsigned  data )
{
  if( (addr < mStart) || (addr >= mStart + mSize) )
    cout << name() << " write(" << addr << ", __) : ERROR address out of range"
    << endl;
  else
    mMem[addr-mStart] = data;
}

void Ram::read(  unsigned addr, unsigned &data )
{
  if( (addr < mStart) || (addr >= mStart + mSize) )
    cout << name() << " read(" << addr << ", __) : ERROR address out of range"
    << endl;
  else
    data = mMem[addr-mStart];
}
  
void Ram::dump(ostream& os) {

	for (unsigned i = 0; i < mSize; i++) {

		os << "Memory[" << i << "]: " << this->mMem[i] << endl;

	}
}


