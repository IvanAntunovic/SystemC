/*
 * TrafficLightController.h
 *
 *  Created on: Aug 17, 2018
 *      Author: ivan
 */

#ifndef HEADERS_TRAFFICLIGHTCONTROLLER_H_
#define HEADERS_TRAFFICLIGHTCONTROLLER_H_

#include <systemc.h>

class TrafficLightController : sc_module {

private:
	enum state { RED, YELLOW, GREEN };
	state m_state;
	sc_signal<int> toggle;

public:
	void thread() {


	TrafficLightController(sc_module_name mn, int _toggle) : sc_module_name( mn ), m_state( RED ), toggle(_toggle) {

		SC_HAS_PROCESS(TrafficLightController);
		SC_THREAD(thread);
	}

};

class TrafficLightSystem: sc_module {



public:
	TrafficLightSystem(sc_module_name mn) : sc_module_name( mn ) {

		SC_HAS_PROCESS(TrafficLightController);
	}

};



#endif /* HEADERS_TRAFFICLIGHTCONTROLLER_H_ */