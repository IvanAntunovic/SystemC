#include "testbench.h"
void Testbench::stim()  // SC_THREAD
{

  sc_signal<int> s;
  sc_buffer<int> b;

  cout << "s: " << s << "\tb: " << b << endl;


  /*
  cout << "Ch_x: " << ch_x << "\tCh_y: " << ch_y << endl;
  wait(10, SC_NS);
  ch_x = 3; ch_y = 4;   // first stimulus
  cout << "Ch_x: " << ch_x << "\tCh_y: " << ch_y << endl;
  wait(10, SC_NS);      // wait for 10 ns

  cout << "Ch_x: " << ch_x << "\tCh_y: " << ch_y << endl;
  ch_x = 7; ch_y = 0;   // second stimulus
  cout << "Ch_x: " << ch_x << "\tCh_y: " << ch_y << endl;
  wait(10, SC_NS);      // wait (no sensitivity!)
  cout << "Ch_x: " << ch_x << "\tCh_y: " << ch_y << endl;

  ch_x = 8; ch_y = -4;
  wait(0, SC_NS);                      // further stimuli
  cout << "Zero sleep: Ch_x: " << ch_x << "\tCh_y: " << ch_y << endl;

  wait(10, SC_NS);
  ch_x = 8; ch_y = -4;
  wait(10, SC_NS); */
}
void Testbench::check() // SC_METHOD
{
  //cout << ch_x << "+" << ch_y << "=" << ch_s;  // debug output
  //if( ch_s != ch_x+ch_y ) sc_stop();     // stop simulation
  //else cout << " -> OK" << endl;
}
