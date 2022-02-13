

#include <systemc.h>
#include "tlc.h"
#include "../Exercise_1/testbench.h"
#ifdef ABSTRACT_TIMER
#include "timer.h"
#else
#include "timer_clk.h"
#endif


int sc_main (int argc, char * argv[])
{
    sc_signal<bool> car ;
    sc_signal<color> M , S ;
    // timer signals
    sc_signal<bool> start , sec_5 ;

    TLC T1( "T1" );
    Testbench TB1("TB1");
#ifdef ABSTRACT_TIMER
    TIMER timer( "Timer1" );
#else
    TIMER_CLK timer("Timer1");
    sc_clock clk("clk", sc_time(1, SC_US)) ;
    timer.clk(clk) ;
#endif

     T1.M(M);
     T1.S(S);
     T1.car(car);
     T1.start( start );
     T1.sec_5(sec_5);

     // These connections must be valid for both timers
     timer.start(start);
     timer.sec_5(sec_5);

     TB1.Main_road(M);
     TB1.Secondary_road(S) ;
     TB1.car(car);

     sc_start();
     return 0 ;
}
