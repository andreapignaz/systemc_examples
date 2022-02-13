#ifndef TLC_H
#define TLC_H

enum color{ RED , YELLOW , GREEN };
SC_MODULE(TLC)
{ 
	public :
	sc_in<bool> car ;
	sc_out<color> M , S ;
	SC_CTOR(TLC)  // Constructor
	: car("car"), M("Main"), S("Secondary") {
		SC_THREAD( TLC_run ) ;
	} 
	void TLC_run ( ) 
	{ 
		M.write(GREEN); // initialization
		S.write(RED);   
		while (1) 
		{ 	
			wait (10 , SC_SEC);
			if (!car) // wait until car arrives at Secondary
			    wait(car.posedge_event()) ;
			wait(5,SC_SEC);  
			M.write(YELLOW);
			wait (5,SC_SEC);
			M.write(RED);
			S.write(GREEN);
			wait(10,SC_SEC);
			S.write(YELLOW);
			wait(5,SC_SEC);
			S.write(RED);
			M.write(GREEN);
		} 
	}
};

#endif
