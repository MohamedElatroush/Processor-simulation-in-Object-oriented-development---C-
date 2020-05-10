#include "WRITE.hpp"

WRITE::WRITE(){
    inst = "";
    in1 = "";
    in2 = "";
    address = "";
}

WRITE::~WRITE(){
    //Destructor
}


void WRITE::execute(string inst, string in1, string in2, string address, ofstream& of, InstructionMemory& IM, DataMemory& DM)
{
int x = -1;
string in_1;
string in_2;
if (in1[0] == 'R')
{
for (int i=1;i<in1.length();i++)
{
    in_1+=in1[i]; //in_1 contains the register number
}
try{
if(stoi(in_1)>1023 || stoi(in_1)<0) //Throwing an exception if a location outside the boundary is trying to be accessed
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

cout << "printing " << DM.datamem[stoi(in_1)] <<" on screen\n";
of <<"WRITE: "<<stoi(in_1) << endl;
}
else
{
try{
if(stoi(in1)>1023 || stoi(in1)<0) //Throwing an exception if a location outside the boundary is trying to be accessed
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


cout << "printing " << stoi(in1) <<" on screen\n";
of <<"WRITE: "<<stoi(in1) << endl;
}
PC+=1;
                       
}