/*
 * Adapter.h
 *
 *  Created on: Jun 24, 2018
 *      Author: ivan
 */

#ifndef HEADERS_ADAPTER_H_
#define HEADERS_ADAPTER_H_

#include <systemc.h>

class Adapter : public sc_module {

public:
	Adapter(sc_module_name moduleName) : sc_module(moduleName) {

	}
};



#endif /* HEADERS_ADAPTER_H_ */