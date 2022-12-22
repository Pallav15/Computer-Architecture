
Firstly I have created Python class for our SIMOBJECT
In this I have created the class VECTOROPERATION as a simobject, simple object can have several parameters that i have controlled by other files, In this i have also created some variable that is used for my bonus part 

Next file is my header file:
In this I have created the instance of event in the EventFunctionWrapper and i have also called the startup functions which is used to schedule the event.

Next file is cc file:
Here I have the constructor of my class there i have passed all the parameter that i have to use in the methods. In this i have decleared the vector that i have to use and then i have created the events for each ie vector , addtion, dot product, normalize and then wrote the code in c++ for all the operation that i have to perform and in this i have also made the constructor of the starup() and then scheduled it using the latency variable that the user will enter while running the file. Then after writting the code for the functions i have printed using DPRINTF in c++ macro.

NextFile is my run_hello.py file:
which is also a python file that i have to write to run the proigram in this i have take the input for the user for my bonus part

Using this i have ran the different file by changing the variabke in[this] present in this with the keyWOrds that i have to use Like VECTOR, ADDRESULT, DOTRESULT, NORMALIZE

build/X86/gem5.opt --debug-flags=[this] src/learning_gem5/CA_Assign2/run_hello.py

below command i have used to build the project:
/usr/bin/env python3 $(which scons) build/X86/gem5.opt

starting part is not scons because i have used the remote excess
