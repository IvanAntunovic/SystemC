#include "src.h"

#define SC_INCLUDE_DYNAMIC_PROCESSES
#include <systemc>
#include <tlm.h>


using namespace sc_core;
using namespace tlm;
// <-- enter your implementation here

// <-- enter your implementation here

void src_unit::sendDataToT() {
    
    tlm_generic_payload trans;
    unsigned char* pData;
    sc_core::sc_time t;
    unsigned int data; 

    while(true) {
    
        data=data_buffer.read();
    
        pData = reinterpret_cast<unsigned char*>(&data);
        trans.set_data_ptr(pData);
        trans.set_data_length(4);
        trans.set_write();
        trans.set_response_status(TLM_INCOMPLETE_RESPONSE);
        trans.set_address(0x10000); 
        t = SC_ZERO_TIME;
        init_socket_transform->b_transport(trans,t);
        m_sent_data_count++;
        if(m_sent_data_count == m_data_size) break;
    }
    //send data to T per b_transport()
    std::cout << "end of the simulation @" << sc_time_stamp()<< std::endl;
}


