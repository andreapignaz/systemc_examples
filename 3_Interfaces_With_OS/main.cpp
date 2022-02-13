#include <systemc.h>
#include "interfaces.h"
#include "tlm_tlc.h"
#include "os_drivers.h"
#include "color.h"

int sc_main (int argc, char * argv[])
{ 
	TLC_SW TLC("Controller") ;
	OS_DRIVERS os_drivers("OS drivers");
	
	TLC.car(os_drivers);
	TLC.traffic_light(os_drivers);
	TLC.timer(os_drivers);

	sc_start();
	return 0 ;
}
