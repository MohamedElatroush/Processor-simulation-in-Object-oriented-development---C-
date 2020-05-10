#include "JMP.hpp"

JMP::JMP(){
    inst = "";
    in1 = "";
    in2 = "";
    address = "";
}

JMP::~JMP(){
    //Destructor
}


void JMP::execute(string inst, string in1, string in2, string address, ofstream& of, InstructionMemory& IM, DataMemory& DM)
{
string in_1;
string in_2;
int x = -1;
try {
 if (stoi(in1)<0 || stoi(in1)>1024)
 {
    throw x;
 }
}
catch (int x)
{
        cout << IM.instmem[PC] << " out of memory bounds\n";
        cout << "Processor shutting down!\n";
        exit(-1);
}
    PC = stoi(in1);                 
}