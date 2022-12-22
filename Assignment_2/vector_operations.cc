#include "learning_gem5/CA_Assign2/vector_operations.hh"

#include <iostream>
#include <bits/stdc++.h>
#include "base/trace.hh"
#include "debug/VECTOR.hh"
#include "debug/ADDRESULT.hh"
#include "debug/DOTRESULT.hh"
#include "debug/NORMALIZE.hh"
// #include "debug/VECTOR_OPERATIONS.hh"


namespace gem5
{
    int vec1[] = {20,40,60,80};
    int vec2[] = {10,30,50,70};
VectorOperations::VectorOperations(const VectorOperationsParams &params) :
    SimObject(params), eventv([this]{processEventv();}, name()),eventa([this]{processEventa();}, name()),eventd([this]{processEventd();}, name()),eventn([this]{processEventn();}, name()),latency1(params.time_to_wait1),latency2(params.time_to_wait2),latency3(params.time_to_wait3),latency4(params.time_to_wait4)
{
    DPRINTF(VECTOR, " 2020225 ASSIGNMENT2 CA BY PALLAV SINGLA\n");
    
}


void
VectorOperations::startup()
{
    schedule(eventv, latency1);
    schedule(eventa, latency2);
    schedule(eventd, latency3);
    schedule(eventn, latency4);
}
void
VectorOperations::processEventv()
{
    
    
    DPRINTF(VECTOR, "THIS IS MY VECTOR!\n");
    // for(int i=0;i<4;i++){
    //     // DPRINTF(VECTOR, "HI");
    //     DPRINTF(VECTOR,"%d\n", vec1[i],vec2[i]);
    // }
    DPRINTF(VECTOR, "First vector is %d %d %d %d\n", vec1[0],vec1[1],vec1[2],vec1[3]);
    DPRINTF(VECTOR, "Second vector is %d %d %d %d\n", vec2[0],vec2[1],vec2[2],vec2[3]);
    // DPRINTF(VECTOR, "\n[20  [10\n40   30\n60   50\n80]  70]\n");
}

void
VectorOperations::processEventa()
{

    DPRINTF(ADDRESULT, "ADDITION OF TWO VECTOR IS SHOWN HERE\n");
    DPRINTF(ADDRESULT, "%d %d %d %d\n", vec1[0]+vec2[0],vec1[1]+vec2[1],vec1[2]+vec2[2],vec1[3]+vec2[3]);
}

void
VectorOperations::processEventd()
{
    int answer =0;
    for(int i=0;i<4;i++){
        answer = answer + vec1[i]*vec2[i];
    }
    DPRINTF(DOTRESULT, "DOT PRODUCT OF TWO VECTOR IS SHOWN HERE\n");
    DPRINTF(DOTRESULT, "%d\n",answer);
}

void
VectorOperations::processEventn()
{
    double Normal=0;
    double vec1Norm[4];
    double vec2Norm[4];

    double val1=0;
    for(int i=0;i<4;i++){
        val1 += (double)vec1[i]*(double)vec1[i];
    }
    double val2=0;
    for(int i=0;i<4;i++){
        val2 += (double)vec2[i]*(double)vec2[i];
    }
    val1 = sqrt(val1);
    val2 = sqrt(val2);

    // for(int i=0;i<4;i++){
    //     vec1Norm[i] = vec1[i]/val1;
    //     vec2Norm[i] = vec2[i]/val2;
    // }
    vec1Norm[0] = (double)vec1[0]/val1;
    vec1Norm[1] = (double)vec1[1]/val1;
    vec1Norm[2] = (double)vec1[2]/val1;
    vec1Norm[3] = (double)vec1[3]/val1;

    vec2Norm[0] = (double)vec1[0]/val2;
    vec2Norm[1] = (double)vec1[1]/val2;
    vec2Norm[2] = (double)vec1[2]/val2;
    vec2Norm[3] = (double)vec1[3]/val2;


    DPRINTF(NORMALIZE, "NORMALISATIONS OF TWO VECTOR IS SHOWN HERE!\n");
    // DPRINTF(NORMALIZE, "\n[0.182  [0.109\n0.364   0.327\n0.547   0.545\n0.728]  0.763]\n");
    DPRINTF(NORMALIZE, "%f %f %f %f\n",vec1Norm[0],vec1Norm[1],vec1Norm[2],vec1Norm[3]);
    DPRINTF(NORMALIZE, "%f %f %f %f\n",vec2Norm[0],vec2Norm[1],vec2Norm[2],vec2Norm[3]);

}


} // namespace gem5