#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include "bus_if.h"

class Adapter : public sc_module, public bus_if
{
public:
  sc_out<int> x;
  sc_out<int> y;
  sc_in<int>  s;

  unsigned start_addr1;
  unsigned start_addr2;
  unsigned start_addr3;
  unsigned block_size;
  unsigned status;

  // Adapter master port
  sc_port<ext_bus_if, 1> initiator_port;

  // Event to trigger execution
  sc_event additionEvent;

  unsigned mId;

  void write( unsigned addr, unsigned  data );
  void read(  unsigned addr, unsigned &data );
  void additionThread(void);

  Adapter( sc_module_name mn, unsigned id = 0 ) : sc_module(mn)
  {
	SC_HAS_PROCESS(Adapter);
	SC_THREAD(additionThread);

	mId = id;

    return; // alternative: export the bus_if here
  }

};

#endif
