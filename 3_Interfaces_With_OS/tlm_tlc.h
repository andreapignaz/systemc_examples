#ifndef TLM_TLC_H
#define TLM_TLC_H

#include "color.h"

SC_MODULE(TLC_SW) {
	sc_port<car_if> car;
	sc_port<timer_if> timer;
	sc_port<light_if> traffic_light;
	
	SC_CTOR(TLC_SW) {
		SC_THREAD(controller);
	}

	void controller() {
		traffic_light -> set_main(GREEN);
		traffic_light -> set_sec(RED);
		while(1) {
			car -> wait_for_car();
			traffic_light -> set_main(YELLOW);
			timer -> wait_for_sec(5);
			traffic_light -> set_main(RED);
			traffic_light -> set_sec(GREEN);
			timer -> wait_for_sec(10);
			traffic_light -> set_sec(YELLOW);
			timer -> wait_for_sec(5);
			traffic_light -> set_sec(RED);
			traffic_light -> set_main(GREEN);
		}
	}


};



#endif
