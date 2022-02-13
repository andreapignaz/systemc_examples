#ifndef TIMER_DRIVER_H
#define TIMER_DRIVER_H

#include <interfaces.h>

using namespace sc_dt;

// Here you must implement the timer_driver, withhave a port of type bus.

SC_MODULE(TIMER_DRIVER), virtual public timer_if {
  sc_port<bus_if> bus;
   
  SC_CTOR(TIMER_DRIVER): bus("bus") {} 

  virtual void wait_for_sec(unsigned int sec) {
    bus -> write(104, sec * 1000000);
    bus -> write(108, 0);
    bus -> write(100, 0);
    while(!((bus->read(108))[2]))
	  wait(1, SC_MS);
  }
};

#endif
