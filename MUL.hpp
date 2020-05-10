#ifndef MUL_hpp
#define MUL_hpp

#include <stdio.h>
#include "operations.hpp"

class MUL: public operations {
    private:
    string inst;
    string in1,in2;
    string address;
    ofstream of; 
    InstructionMemory IM;
    DataMemory DM; 
    public: 
    MUL();
    ~MUL();
    virtual void execute(string, string,string,string,ofstream&,InstructionMemory&,DataMemory&);
};

#endif /* MUL_hpp */