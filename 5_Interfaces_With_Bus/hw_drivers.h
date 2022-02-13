#ifndef HW_DRIVERS_H
#define HW_DRIVERS_H

#include "../Exercise_3/color.h"

SC_MODULE(HW_DRIVERS), virtual public car_if, virtual public light_if {
	sc_in<bool> car;
	sc_out<color> M,S;
	SC_CTOR(HW_DRIVERS) {}

	void set_main(color x) {
		M.write(x);		
	}

	void set_sec(color x) {
		S.write(x);
	}

	void wait_for_car() {
		while(!car);
	}
};

#endif
