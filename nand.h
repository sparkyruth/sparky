#include<systemc.h>

SC_MODULE(nand_gate){
//input and output ports

sc_in<bool> x,y;
sc_out<bool> z;

void gate(void);

~nand_gate();


//constructor: where the processes are bound to simulation kernel
SC_CTOR(nand_gate){
	SC_METHOD(gate);
	sensitive << y<< x;
	
}
};


