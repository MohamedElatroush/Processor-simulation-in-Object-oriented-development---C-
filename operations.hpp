#ifndef operations_hpp
#define operations_hpp

#include <stdio.h>
#include <iostream>
#include "InstructionMemory.hpp"
#include "DataMemory.hpp"


using namespace std; 

class operations 
{
public:
string inst;
    string in1,in2;
    string address;
    ofstream of; 
    InstructionMemory IM;
    DataMemory DM; 
    operations();
    operations(string, string,string,string,ofstream&,InstructionMemory&,DataMemory&);
    ~operations();
    virtual void execute(string, string,string,string,ofstream&,InstructionMemory&,DataMemory&);

};


#endif /* operations_hpp */
