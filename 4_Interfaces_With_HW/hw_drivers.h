#ifndef HW_DRIVERS_H
#define HW_DRIVERS_H

#include "../Exercise_3/color.h"

SC_MODULE(HW_DRIVERS), public car_if, public timer_if, public light_if {
	sc_in<bool> car;
	sc_out<color> M,S; 
	sc_in<bool> clk;

	SC_CTOR(HW_DRIVERS) {
	}

	void set_main(color x) {
		M.write(x);
	}

	void set_sec(color x) {
		S.write(x);	
	}

	void wait_for_car() {
		while(!car);
	}

	void wait_for_sec(unsigned int y) {
		for(unsigned int i=0; i < y*1000000; i++) {
			wait(clk.posedge_event());			
		} 
	}

};
// Here you must implement a module that implements all three interfaces
// and has 3 I/O signals for car, main and secondary

#endif
