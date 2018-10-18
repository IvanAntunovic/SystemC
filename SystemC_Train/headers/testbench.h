#ifndef _TESTBENCH_H_
#define _TESTBENCH_H_

#include "systemc.h"
#include "ScThread.h"

class Testbench : public sc_module
{ 									// a top level module; no ports
public:

  ScThread mThread;
  sc_buffer<int> mChannel;

  void stim_th_1();
  void stim_th_2();// stimuli process
  void check();						// checking process

  Testbench(sc_module_name moduleName);
};

#endif

