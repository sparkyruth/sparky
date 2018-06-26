#include <systemc.h>
#include "nand.h"
#include "invertergate.h2"

SC_MODULE (dff) {
	sc_in <bool> clk;
	sc_in <bool> din;
	sc_out <bool> dout;
    sc_signal<bool>in,sig2,sig1,sig3,sig4,out;

    nand_gate nandg_1;
    nand_gate nandg_2;
    nand_gate nandg_3;
    nand_gate nandg_4;
    inverter_gate inverterg_1;
    
    void dff_method(void);
	~dff();

    SC_CTOR (dff) :


    nandg_1("gate_instance_1"),
    nandg_2("gate_instance_2"),
    nandg_3("gate_instance_3"),
    nandg_4("gate_instance_4"),

    inverterg_1("gate_instance"){

//interconnections
nandg_1.x(in);
nandg_1.y(clk);
nandg_1.z(sig2);

nandg_2.x(sig1);
nandg_2.y(clk);
nandg_2.z(sig3);

nandg_3.x(sig2);
nandg_3.y(sig4);
nandg_3.z(out);

nandg_4.x(out);
nandg_4.y(sig3);
nandg_4.z(sig4);

inverterg_1.w(sig1);
inverterg_1.x(in);



		SC_METHOD (dff_method);
			sensitive_pos << clk;
	}
};
