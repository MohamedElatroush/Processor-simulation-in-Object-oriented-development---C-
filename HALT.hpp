#ifndef HALT_hpp
#define HALT_hpp

#include <stdio.h>
#include <iostream>
#include "operations.hpp"
using namespace std; 

class HALT:public operations {
    private:
    string inst;
    string in1,in2;
    string address;
    ofstream of; 
    InstructionMemory IM;
    DataMemory DM; 
    public: 
    HALT();
    ~HALT();
    virtual void execute(string, string,string,string,ofstream&,InstructionMemory&,DataMemory& );
};


#endif /* HALT_hpp */