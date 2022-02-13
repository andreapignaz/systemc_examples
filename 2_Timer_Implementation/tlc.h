#ifndef TLC_H
#define TLC_H

enum color{ RED , YELLOW , GREEN };
SC_MODULE(TLC)
{ 
	public :
	sc_in<bool> car ;
	sc_out<color> M , S ;
	sc_in<bool> sec_5;
	sc_out<bool> start;
	
	SC_CTOR(TLC)  // Constructor
	: car("car"), M("Main"), S("Secondary") {
		SC_THREAD( TLC_run ) ;
		sensitive << car << sec_5;
	} 
	void TLC_run ( ) 
	{ 
		M.write(GREEN); // initialization
		S.write(RED);   
		while (1) 
		{ 	
		  start = !start;
		  wait(sec_5.default_event());
		  start = !start;
		  wait(sec_5.default_event());
		  if (!car) // wait until car arrives at Secondary
			wait(car.posedge_event()) ;
		  start = !start;
		  wait(sec_5.default_event());		  
		  M.write(YELLOW);
		  start = !start;
		  wait(sec_5.default_event());
		  M.write(RED);
		  S.write(GREEN);
		  start = !start;
		  wait(sec_5.default_event());
		  start = !start;
		  wait(sec_5.default_event());
		  S.write(YELLOW);
		  start = !start;
		  wait(sec_5.default_event());
		  S.write(RED);
		  M.write(GREEN);
		} 
	}
};

#endif
