#include "adder.h"
void Adder::add()
{
  s.write( x.read() + y.read() );
}
