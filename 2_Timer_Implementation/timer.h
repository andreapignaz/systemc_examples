#include <systemc.h>
#include <iostream>
#include <string>
SC_MODULE(TIMER) {
  sc_out<bool> sec_5;
  sc_in<bool> start;
  
  SC_CTOR(TIMER) {
    SC_THREAD(timer_waiting);
    sensitive << start;
  }

  void timer_waiting(void);
};
