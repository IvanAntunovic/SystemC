// file main.cpp
#include "systemc.h"
#include "counter.h"

int sc_main(int argc, char *argv[])  // cf. C++ main()
{
  Counter counter("cnt");
  sc_clock clk("clk", 10, SC_NS, 0, 0, SC_NS);

  counter.clk.bind( clk );

  sc_start(100, SC_NS);
  cout << "simulation finished" << endl;
  return 0;
}
