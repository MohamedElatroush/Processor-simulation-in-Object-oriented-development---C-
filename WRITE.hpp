#ifndef WRITE_hpp
#define WRITE_hpp

#include <stdio.h>
#include <iostream>
#include "operations.hpp"
using namespace std; 

class WRITE: public operations {
    private:
    string inst;
    string in1,in2;
    string address;
    ofstream of; 
    InstructionMemory IM;
    DataMemory DM; 
    public: 
    WRITE();
    ~WRITE();
    virtual void execute(string, string,string,string,ofstream&,InstructionMemory&,DataMemory&);
};


#endif /* WRITE_hpp */