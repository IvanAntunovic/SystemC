// file adder.h
#ifndef _ADDER_H_
#define _ADDER_H_

#include "systemc.h"
SC_MODULE(Adder)
{
  sc_in<int> x;
  sc_in<int> y;
  sc_out<int> s;

  void add();
  SC_CTOR(Adder) : x("x"), y("y"), s("s")
  {
    SC_METHOD(add);
    sensitive << x << y;
  }
};

#endif
