// file main.cpp
#include "systemc.h"
#include "testbench.h"

SC_MODULE(Buffer) {

	sc_buffer<int> buff;
	sc_fifo<int> fifo;
	sc_signal<int> signal;

	sc_out<int> port;

	sc_clock clk;


	void handler(void) {

		port.write(1);
		port.write(2);



	  cout << buff.read() << endl;
	  cout << buff.read() << endl;

	}

	SC_CTOR(Buffer) {

		SC_THREAD(handler);

		port.bind(buff);
	}
};

int sc_main(int argc, char *argv[])  // cf. C++ main()
{
  //Testbench tb("tb");
  Buffer buff("buffer");
  sc_start();

  cout << "simulation finished" << endl;
  return 0;
}
