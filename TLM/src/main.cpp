#include <systemc.h>
//#include "TLM_PV.h"
//#include "TLM_CX.h"
#include "TLM_CA.h"

int sc_main(int argc, char* argv[]) {

	//TLM_PV tlm_pv("tlm_pv");
	//TLM_CX tlm_cx("tlm_cx");
	TLM_CA tlm_ca("tlm_ca");

	sc_start();

	return 0;
}