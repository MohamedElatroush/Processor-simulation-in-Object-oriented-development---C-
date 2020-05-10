#ifndef NEG_hpp
#define NEG_hpp

#include <stdio.h>
#include <iostream>
#include "operations.hpp"
using namespace std; 

class NEG: public operations {
    private:
    string inst;
    string in1,in2;
    string address;
    ofstream of; 
    InstructionMemory IM;
    DataMemory DM; 
    public: 
    NEG();
    ~NEG();
    virtual void execute(string, string,string,string,ofstream&,InstructionMemory&,DataMemory&);
};


#endif /* NEG_hpp */