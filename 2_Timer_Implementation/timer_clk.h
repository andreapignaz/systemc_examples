#include <systemc.h>
#include <iostream>
#include <string>
SC_MODULE(TIMER_CLK) {
  sc_out<bool> sec_5;
  sc_in<bool> start;
  sc_in<bool> clk;

  SC_CTOR(TIMER_CLK) {
    SC_THREAD(timer_waiting);
    sensitive << start;
  }

  void timer_waiting(void);
};
