/*
 * Destination.h
 *
 *  Created on: Jun 23, 2018
 *      Author: ivan
 */

#ifndef HEADERS_DESTINATION_H_
#define HEADERS_DESTINATION_H_

#include <systemc.h>

class Destination : public sc_module {

public:
	sc_fifo_in<int> mInputPort;

	Destination(sc_module_name);
	void threadHandler(void);

};




#endif /* HEADERS_DESTINATION_H_ */
