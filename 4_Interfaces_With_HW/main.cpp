#include <systemc.h>
#include "interfaces.h"
#include "../Exercise_3/tlm_tlc.h"
#include "hw_drivers.h"
#include "../Exercise_1/testbench.h"
#include "../Exercise_3/color.h"

int sc_main (int argc, char * argv[])
{ 
	sc_signal<bool> car("car");
	sc_signal<color> M("Main"), S("Secondary");
	sc_clock clk("clk",sc_time(1, SC_US));

	TLC_SW TLC("Controller") ;
	HW_DRIVERS hw_drivers("HW driver");
	Testbench TB("Testbench");
	
	hw_drivers.car(car);
	hw_drivers.M(M);
	hw_drivers.S(S);
	hw_drivers.clk(clk);
    
	TLC.car(hw_drivers);
	TLC.traffic_light(hw_drivers);
	TLC.timer(hw_drivers);

	TB.Main_road(M);
	TB.Secondary_road(S) ;
	TB.car(car);

	sc_start();
	return 0 ;
}
