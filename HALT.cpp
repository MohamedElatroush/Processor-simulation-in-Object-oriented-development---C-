#include "HALT.hpp"

HALT::HALT(){
    inst = "";
    in1 = "";
    in2 = "";
    address = "";
}

HALT::~HALT(){
    //Destructor
}


void HALT::execute(string inst, string in1, string in2, string address, ofstream& of, InstructionMemory& IM, DataMemory& DM)
{
PC=-1;                      
}