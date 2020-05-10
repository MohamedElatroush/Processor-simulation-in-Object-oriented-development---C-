#ifndef LE_hpp
#define LE_hpp

#include <stdio.h>
#include <iostream>
#include "operations.hpp"
using namespace std; 

class LE: public operations {
    private:
    string inst;
    string in1,in2;
    string address;
    ofstream of; 
    InstructionMemory IM;
    DataMemory DM; 
    public: 
    LE();
    ~LE();
    virtual void execute(string, string,string,string,ofstream&,InstructionMemory&,DataMemory&);
};


#endif /* LE_hpp */