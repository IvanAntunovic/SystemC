#include "adapter.h"

void Adapter::write(unsigned addr, unsigned  data) {

  switch(addr) {

	  case 1024 :
		x.write(data);
		start_addr1 = data;
		break;
	  case 1025 :
		y.write(data);
		start_addr2 = data;
		break;
	  case 1026:
		start_addr3 = data;
		break;
	  case 1027:
		block_size = data;
		break;
	  case 1028:
		if (data != 0) {

			// start addition
			additionEvent.notify();
			status = data;

		}
		break;
	  default :
		cout << "Adapter: write to invalid address" << endl;

  }

}

void Adapter::read( unsigned addr, unsigned &data) {

  switch(addr) {

  	  case 1024 :
		data = start_addr1;
		break;
	  case 1025 :
		data = start_addr2;
		break;
	  case 1026 :
		data = start_addr3;
		break;
	  case 1027:
        data = block_size;
		break;
	  case 1028:
		data = status;
		break;

	  default :
		cout << "Adapter: read from invalid address" << endl;
  }

}

void Adapter::additionThread(void) {

	unsigned readDataOne, readDataTwo;

	while (true) {

		wait(additionEvent);
		cout << "DMA triggered" << " at time: " << sc_time_stamp() << endl;

		for (int address = 0; address < block_size - 1; ++address) {

			cout <<  "Reading from address: " << start_addr1 + address << " & " << start_addr2 + address << ". Writing to "
			        << start_addr3 + address << " at time" << sc_time_stamp() << endl;

			initiator_port->read(start_addr1 + address , readDataOne, mId);
			initiator_port->read(start_addr2 + address , readDataTwo, mId);

			x.write(readDataOne);
			y.write(readDataTwo);
			wait(1, SC_NS); // Wait for addition to finish

			initiator_port->write(start_addr3 + address, s.read(), mId);

		}

		// Addition has been performed, reset the status
		status = 0;

	}
}
