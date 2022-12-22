#ifndef __LEARNING_GEM5_HELLO_OBJECT_HH__
#define __LEARNING_GEM5_HELLO_OBJECT_HH__

#include "params/VectorOperations.hh"
#include "sim/sim_object.hh"

namespace gem5
{


class VectorOperations : public SimObject
{
  private:
    void processEventv();

    EventFunctionWrapper eventv;
    // const Tick tick1;
    int latency1;

    // int v1;
    // int v2;
    // int v3;
    // int v4;
    // int v5;
    // int v6;
    // int v7;
    // int v8;

  private:
    void processEventa();

    EventFunctionWrapper eventa;
    // const Tick tick2;
    int latency2;


  private:
    void processEventd();

    EventFunctionWrapper eventd;
    // const Tick tick3;
    int latency3;

  private:
    void processEventn();

    EventFunctionWrapper eventn;
    // const Tick tick4;
    int latency4;
    

  public:
    VectorOperations(const VectorOperationsParams &p);
    
    void startup();

};

} // namespace gem5

#endif // __LEARNING_GEM5_HELLO_OBJECT_HH__