#ifndef _ADDER_MASTER_H_
#define _ADDER_MASTER_H_

#include "bus_if.h"

#define ADDER_INPUT1    1024
#define ADDER_INPUT2    1025
#define ADDER_OUTPUT    1026

#define SUM_RAM_START   64

#define RAM_OFFSET      16


class AdderMaster : public sc_module
{

public:
  sc_port<bus_if,1> initiator_port;
  unsigned start, end, id;

  void action();

  AdderMaster( sc_module_name mn, unsigned start_addr, unsigned end_addr, unsigned id = 0 )
  : sc_module( mn )
  {
	SC_HAS_PROCESS(AdderMaster);
    SC_THREAD(action);
    this->id = id;
    start = start_addr;
    end = end_addr;
  }

};

#endif
