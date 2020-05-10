#ifndef ASS_hpp
#define ASS_hpp

#include <stdio.h>
#include <iostream>
#include "operations.hpp"
using namespace std; 

class ASS: public operations {
    private:
    string inst;
    string in1,in2;
    string address;
    ofstream of; 
    InstructionMemory IM;
    DataMemory DM; 
    public: 
    ASS();
    ~ASS();
    virtual void execute(string, string,string,string,ofstream&,InstructionMemory&,DataMemory&);
};


#endif /* ASS_hpp */
