#include "testbench.h"

void Testbench::stim()  // SC_THREAD
{

  cout << "Stim starting to run " << endl;

  mAdderInput_ch_1.write(3); mAdderInput_ch_2.write(4);   // first stimulus
  cout << sc_module::name() << ": 3 + 7" << endl;
  mMultiplierInput_ch.write(5);
  for (int i = 0; i < 10; ++i) {
	  mDecimatorInput_ch.write(i);
  }


  mAdderInput_ch_1.write(7); mAdderInput_ch_2.write(0);   // second stimulus
  cout << sc_module::name() << ": 7 + 0" << endl;
  mMultiplierInput_ch.write(6);
  for (int i = 10; i < 20; ++i) {
	  mDecimatorInput_ch.write(i);
  }

  mAdderInput_ch_1.write(8); mAdderInput_ch_2.write(-4);
  cout << sc_module::name() << ": 8 + -4" << endl;
  mMultiplierInput_ch.write(7);
  for (int i = 20; i < 30; ++i) {
	  mDecimatorInput_ch.write(i);
  }

  mAdderInput_ch_1.write(2); mAdderInput_ch_2.write(6);
  cout << sc_module::name() << ": 2 + 6" << endl;
  mMultiplierInput_ch.write(8);
  for (int i = 30; i < 40; ++i) {
	  mDecimatorInput_ch.write(i);
  }

}

void Testbench::check() // SC_METHOD
{
	int adderInputOne, adderInputTwo, adderOutput;
	int multiplierInput, mulitipilerOutput;
	int decimatorInput, decimatorOutput;

	while (true) {

		// Adder Check
		adderInputOne = mAdderInput_ch_1.read();
		adderInputTwo = mAdderInput_ch_2.read();
		adderOutput = mAdderOutput_ch.read();

		cout << adderInputOne << "+" << adderInputTwo << "=" << adderOutput << endl;  // debug output

		if( adderOutput != adderInputOne + adderInputTwo ) {
			cout << "Stopping the simulation" << endl;
			sc_stop();     // stop simulation
		}
		else cout << "Addition -> OK" << endl;

		// Multiplier Check
		multiplierInput = mMultiplierInput_ch.read();
		mulitipilerOutput = mMultiplierOutput_ch.read();

		cout << multiplierInput << "*" << uutMultiplier.K << "=" << mulitipilerOutput << endl;  // debug output

		if( mulitipilerOutput != multiplierInput * uutMultiplier.K) {
			cout << "Stopping the simulation" << endl;
			sc_stop();     // stop simulation
		}
		else cout << "Multiplication -> OK" << endl;

		// Decimator check
		// Multiplier Check
		decimatorInput = mDecimatorInput_ch.read();
		decimatorOutput = mDecimatorOutput_ch.read();

		cout << "Decimator input: " << decimatorInput << "Decimator output: " << decimatorOutput << endl;  // debug output


	}

}
