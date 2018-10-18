/*
 * Master_ca.h
 *
 *  Created on: Aug 18, 2018
 *      Author: ivan
 */

#ifndef HEADERS_MASTER_CA_H_
#define HEADERS_MASTER_CA_H_

#include "master.h"

class Master_ca : public Master {

public:
	unsigned id;
	Master_ca( sc_module_name mn, unsigned start_addr, unsigned end_addr, unsigned _id = 0 ) :
		Master(mn, start_addr, end_addr),
		id(_id)

	{

	}
};



#endif /* HEADERS_MASTER_CA_H_ */
