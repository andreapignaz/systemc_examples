#include <cstdio>
#include "systemc.h"
#include "tlc.h"
#include "testbench.h"

int sc_main(int argc, char * argv[])
{ 
    sc_signal<bool> car("car");
    sc_signal<color> M("Main"), S("Secondary");

    TLC T1 ( "Controller" ) ;
    Testbench TB1 ("Testbench") ;

    T1.M(M);
    T1.S(S);
    T1.car(car) ;

    TB1.Main_road(M) ;
    TB1.Secondary_road(S) ;
    TB1.car(car);

    sc_start();
    return 0;

}
