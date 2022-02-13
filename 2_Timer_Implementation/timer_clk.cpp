#include "timer_clk.h"
using namespace sc_dt;
void TIMER_CLK::timer_waiting(void) {
  sec_5 = false; //Inizialize outputs at first execution of the thread
  for(;;) {
    wait(start.default_event()); //wait for any change on the start signal
    cout << "Timer Start at "<< sc_time_stamp() << endl;
    for(int count = 0; count < 5000000; count++) {
      wait(clk.posedge_event());
    }
    sec_5 = !sec_5; //when 5 sec arrived, the timer raises the sec_5 output...
    cout << "timer change at "<< sc_time_stamp() << sec_5 << endl;
  }
}
