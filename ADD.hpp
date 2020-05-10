#ifndef ADD_hpp
#define ADD_hpp

#include <stdio.h>
#include <iostream>
#include "operations.hpp"
using namespace std; 

class ADD: public operations
{
    private:
    string inst;
    string in1,in2;
    string address;
    ofstream of; 
    InstructionMemory IM;
    DataMemory DM; 
    public: 
    ADD();
    ~ADD();
    virtual void execute(string, string,string,string,ofstream&,InstructionMemory&,DataMemory&);
};


#endif /* ADD_hpp */