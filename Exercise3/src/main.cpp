// file main.cpp
#include "systemc.h"
#include "testbench.h"

SC_MODULE(Test) {

	sc_signal<int> x, y;
	sc_int<16> i;

	void p1() {

		cout << "p1; " << i << "\t"<< "delta: " << sc_delta_count() <<"\t"<<sc_time_stamp()  << endl;
		i = 10;
		cout << "p1; " << i << "\t"<< "delta: " << sc_delta_count() <<"\t"<<sc_time_stamp()  << endl;
		wait(10, SC_NS);

		cout << "p1; " << i << "\t"<< "delta: " << sc_delta_count() <<"\t"<<sc_time_stamp()  << endl;
		x = 10;
		wait(10, SC_NS);


	}

	void p2() {

		wait ( x.value_changed_event() & y.value_changed_event() );

		if (x.event() && y.event())
			cout << "p2 " << sc_time_stamp() << endl;

	}

	SC_CTOR(Test) {

		SC_THREAD(p1);
		SC_THREAD(p2);

	}
};

class Register {

private:
	int state;
protected:
	int protected_fild;
public:
	void reset(){ cout << "Register::reset()" << endl; }
	void load(int x){ cout << "Register::load()" << endl;}
	int read(){ cout << "Register::read()" << endl; }
};

class Counter : protected Register {
private:
	int state;
protected:
	int cnt_protected_f;
public:
	void reset(){cout << "Counter::reset()" << endl;

		cout << this->protected_fild << endl;
		this->read();
	}
	void set_mod(int x) { cout << "Counter::set_mod()" << endl;}
};

class UpCnt : protected Counter {

public:
	void m() {
		this->cnt_protected_f;
	}
};

int sc_main(int argc, char *argv[])  // cf. C++ main()
{
  //Testbench tb("tb");
	//Test test("t");

	Counter cnt;

  sc_start();
  cout << "simulation finished" << endl;
  return 0;
}
