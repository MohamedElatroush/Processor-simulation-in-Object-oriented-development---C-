#ifndef JMP0_hpp
#define JMP0_hpp

#include <stdio.h>
#include <iostream>
#include "operations.hpp"
using namespace std; 

class JMP0: public operations {
    private:
    string inst;
    string in1,in2;
    string address;
    ofstream of; 
    InstructionMemory IM;
    DataMemory DM; 
    public: 
    JMP0();
    ~JMP0();
    virtual void execute(string, string,string,string,ofstream&,InstructionMemory&,DataMemory&);
};


#endif /* JMP0_hpp */