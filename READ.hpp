#ifndef READ_hpp
#define READ_hpp

#include <stdio.h>
#include <iostream>
#include "operations.hpp"
using namespace std; 

class READ: public operations {
    private:
    string inst;
    string in1,in2;
    string address;
    ofstream of; 
    InstructionMemory IM;
    DataMemory DM; 
    public: 
    READ();
    ~READ();
    virtual void execute(string, string,string,string,ofstream&,InstructionMemory&,DataMemory&);
};


#endif /* READ_hpp */