#ifndef _ADDER_H_
#define _ADDER_H_

#include "systemc.h"
SC_MODULE(Adder)
{
  sc_fifo_in<int> mInputPort_1;
  sc_fifo_in<int> mInputPort_2;
  sc_fifo_out<int> mOutPort;

  void add(void);
  SC_CTOR(Adder)
  {
    SC_THREAD(add);
  }

};
#endif
