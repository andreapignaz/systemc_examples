#ifndef TIMER_PERIPHERAL_H
#define TIMER_PERIPHERAL_H

SC_MODULE(TIMER_PERIPHERAL), virtual public bus_if {
  int counter ;
  int max_value;
  int control;
  
  SC_CTOR(TIMER_PERIPHERAL) {
    SC_THREAD(count);
  }

  void count() {
    while(1) {
      wait(1, SC_US);
      counter++;
      if (counter >= max_value) {
	counter = 0;
	control = control | 4;
      }
    }
  }

  void write(sc_uint<32> addr, int data) {
    switch(addr) {
    case 0:
      counter = data;
      break;
    case 1:
      max_value = data;
      break;
    case 2:
      control = data;
      break;
    default:
      SC_REPORT_ERROR(name(), "error");
      break;
    }
  }

  sc_uint<32> read(sc_uint<32> addr){
    sc_uint<32> result;
    switch(addr) {
    case 0:
      result = counter;
      break;
    case 1:
      result = max_value;
      break;
    case 2:
      result = control;
      control = 0;
      break;
    default:
      SC_REPORT_ERROR(name(), "error");
      break;
    }
    return result;
  }

};

#endif
