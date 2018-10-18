#include <systemc.h>
#include <iostream>
#include "counter.h"
#include "register.h"
#include "watch.h"

int sc_main(int argc, char* argv[]) {

	sc_clock clk("clk",
			1, 		// clock period
			SC_SEC, // clock period time unit
			0.5,	// clock duty cycle
			0,		// 0 start time
			SC_NS); // start time unit

	Watch watch("watch");
	// How we can set clock to this guy, is it constructor?
	watch.mClock(clk);

	int runTime = 3600 * 24 + 10;
	sc_start(runTime, SC_SEC);

	cout << "Simulation finished" << endl;

	return 0;
}
