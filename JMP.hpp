#ifndef JMP_hpp
#define JMP_hpp

#include <stdio.h>
#include <iostream>
#include "operations.hpp"
using namespace std; 

class JMP: public operations {
    private:
    string inst;
    string in1,in2;
    string address;
    ofstream of; 
    InstructionMemory IM;
    DataMemory DM; 
    public: 
    JMP();
    ~JMP();
    virtual void execute(string, string,string,string,ofstream&,InstructionMemory&,DataMemory& );
};


#endif /* JMP_hpp */