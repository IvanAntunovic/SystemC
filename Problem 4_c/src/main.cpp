#include <systemc.h>
#include "Test.h"

int sc_main(int argc, char* argv[]) {

	Test test("Test");

	cout << "Start of simulation " << sc_time_stamp() << endl;

	sc_start();

	return 0;
}
