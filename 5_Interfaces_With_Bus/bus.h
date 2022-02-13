#ifndef BUS_H
#define BUS_H

SC_MODULE(BUS), virtual public bus_if {
  sc_port<bus_if> timer;

  SC_CTOR(BUS): timer("timer") {}

  virtual void write(sc_uint<32> addr, int data) {
    switch(addr) {
    case 100:
      timer -> write(0, data);
      break;
    case 104:
      timer -> write(1, data);
      break;
    case 108:
      timer -> write(2, data);
      break;
    default:
      SC_REPORT_ERROR(name(), "Address not defined in the bus");
    }
  }

  virtual sc_uint<32> read(sc_uint<32> addr) {
    sc_uint<32> result = 0;
    switch(addr) {
    case 100:
      result = timer -> read(0);
      break;
    case 104:
      result = timer -> read(1);
      break;
    case 108:
      result = timer -> read(2);
      break;
    default:
      SC_REPORT_ERROR(name(), "Address not defined in the bus");
    }
    return result;
  }

};

#endif
