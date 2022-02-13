#ifndef OS_DRIVERS_H
#define OS_DRIVERS_H

#include "color.h"

SC_MODULE(OS_DRIVERS), public light_if, timer_if, car_if {
	
	SC_CTOR(OS_DRIVERS){
	}

	void set_main(color x) {
		static const char *table[] = {"GREEN","YELLOW","RED"};
		printf("MAIN %s \n", table[x]);
	}
	
	void set_sec(color x) {
		static const char *table[] = {"GREEN","YELLOW","RED"};
		printf("SECONDARY %s \n", table[x]);
	}

	void wait_for_sec(unsigned int y) {
		sleep(y);
		wait(y, SC_SEC);
	} 

	void wait_for_car() {
		char tmp;
		printf("Waiting for car... Press ENTER to simulate\n");
		scanf("%c", &tmp);
	}
	
};

#endif
