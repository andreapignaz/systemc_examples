#include "timer.h"
using namespace sc_dt;

void TIMER::timer_waiting(void) {
  sec_5 = false; //Inizialize outputs at first execution of the thread
  for(;;) {
    wait(start.default_event()); //wait for any change on the start signal
    cout << "Timer Start" << endl;
    wait(5, SC_SEC); //if start signal changed, the timer will start counting time
    sec_5 = !sec_5; //when 5 sec arrived, the timer raises the sec_5 output...
    cout << "timer change "<< sec_5 << endl;
  }
}
