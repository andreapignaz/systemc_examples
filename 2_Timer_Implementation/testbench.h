#ifndef TESTBENCH_H
#define TESTBENCH_H

SC_MODULE( Testbench ) 
{
	public :
	sc_out<bool> car ;
	sc_in<color> Main_road , Secondary_road ;
	
	SC_CTOR(Testbench)
	: car("car"), Main_road("Main"), Secondary_road("Secondary") {
		SC_THREAD(INPUT_GEN);
		
		SC_METHOD(OUTPUT_CHECK);
		sensitive << Main_road << Secondary_road;
		
		SC_METHOD(CAR_CHECK);
		sensitive << car;
	} 
	void INPUT_GEN ( )
	{ 
		car.write(false);
		wait(5 , SC_SEC);
		car.write(true);
		wait (1 , SC_SEC); // Do not wait for green light
		car.write(false);
		wait(30 , SC_SEC);
		car.write(true);
		while (Secondary_road.read() != GREEN)
		    wait(1, SC_SEC);
		car.write(false);
		wait(30 , SC_SEC);
		sc_stop();
	} 
	void OUTPUT_CHECK() 
	{ 
	    static const char *table[]= {"RED","YELLOW","GREEN"};
	    cout << "@" << sc_time_stamp() << " Main      road " << table[Main_road.read()] << std::endl;
	    cout << "@" << sc_time_stamp() << " Secondary road " << table[Secondary_road.read()] << std::endl;
	    cout << std::endl;
	}
	void CAR_CHECK() 
	{ 
	    cout << "@" << sc_time_stamp() << " car " << (car ? "arrives" : "leaves") << std::endl;
	    cout << std::endl;
	}
};

#endif
