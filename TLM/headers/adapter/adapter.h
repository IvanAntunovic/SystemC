/*
 * adapter.h
 *
 *  Created on: Aug 18, 2018
 *      Author: ivan
 */

#ifndef HEADERS_ADAPTER_H_
#define HEADERS_ADAPTER_H_

#include <systemc.h>
#include <bus_if.h>

#define ADDER_FIRST_OUTPUT_ADDR 	1024
#define	ADDER_FIRST_INPUT_ADDR  	1024
#define ADDER_SECOND_OUTPUT_ADDR 	1025
#define	ADDER_SECOND_INPUT_ADDR  	1025
#define ADDDER_RESULT_ADDR			1026
#define ADDER_READ_ONLY_ADDR	 	1026
#define ADDER_START_ADDITION_ADDR   1027

class Adapter : public sc_module, public bus_if {

public:
	sc_export<bus_if> adapter_export;
	sc_out<int> x, y;
	sc_in<int> sum;
	sc_event start_addition_event;

    unsigned x_data, y_data, sum_result;

	void write(unsigned addr, unsigned data);
	void read(unsigned addr, unsigned& data);

	void trigger_addition(void);

	Adapter(sc_module_name mn) : sc_module(mn), x_data(0), y_data(0), sum_result(0) {

		adapter_export.bind( *this );
	}




};



#endif /* HEADERS_ADAPTER_H_ */