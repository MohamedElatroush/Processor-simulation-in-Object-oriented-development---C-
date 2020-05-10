#include "NEG.hpp"

NEG::NEG(){
    inst = "";
    in1 = "";
    in2 = "";
    address = "";
}

NEG::~NEG(){
    //Destructor
}


void NEG::execute(string inst, string in1, string in2, string address, ofstream& of, InstructionMemory& IM, DataMemory& DM)
{
string in_1;
string in_2;
int x = -1;
if (in1[0] == 'R')
{
    for (int i=1;i<in1.length();i++)
    {
        in_1+=in1[i];
    }
    try {
    if ((stoi(in_1) > 1023) || (stoi(in_1)<0))
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
    


    DM.datamem[stoi(in2)] = -1*DM.datamem[(stoi(in_1))]; //multiply -1 by the register number
    of << in2 << ": " << DM.datamem[stoi(in2)] << endl;
    
}
else
{
    try{
    if ((stoi(in2) > 1023) || (stoi(in2)<0)) //in2 here is the address
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
    
    DM.datamem[stoi(in2)] = -1*(stoi(in1)); //multiply -1 by a constant
    of << in2 << ": " << DM.datamem[stoi(in2)] << endl;
    
}    
                       
}