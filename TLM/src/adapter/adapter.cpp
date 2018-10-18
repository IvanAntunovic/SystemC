/*
 * adapter.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: ivan
 */

#include <adapter.h>


void Adapter::write(unsigned addr, unsigned data) {

	switch (addr) {

		case ADDER_FIRST_OUTPUT_ADDR:
			x_data = data;
			break;

		case ADDER_SECOND_OUTPUT_ADDR:
			y_data = data;
			break;

		case ADDER_READ_ONLY_ADDR:
			cout << "ERROR while writing to the Adder!" << addr << " is READ ONLY ADDRESS" << endl;
			break;

		case ADDER_START_ADDITION_ADDR:
			start_addition_event.notify();
			break;

		default:
			cout << "WARNING: Address out of range!" << endl;

	}


}

void Adapter::read(unsigned addr, unsigned& data) {


	switch (addr) {

		case ADDER_FIRST_INPUT_ADDR:
			data = x_data;
			break;

		case ADDER_SECOND_INPUT_ADDR:
			data = y_data;
			break;

		case ADDDER_RESULT_ADDR:
			data = sum_result;
			break;

		default:
			cout << "WARNING: Address out of range!" << endl;

	}

}

void Adapter::trigger_addition(void) {

	while (true) {

		wait ( start_addition_event );

		x.write(x_data);
		y.write(y_data);

		// Wait for adder to do the addition
		wait(1, SC_NS);

		sum_result = sum.read();

	}
}

