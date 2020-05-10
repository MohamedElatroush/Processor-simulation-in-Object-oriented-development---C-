#include "JMP0.hpp"

JMP0::JMP0(){
    inst = "";
    in1 = "";
    in2 = "";
    address = "";
}

JMP0::~JMP0(){
    //Destructor
}


void JMP0::execute(string inst, string in1, string in2, string address, ofstream& of, InstructionMemory& IM, DataMemory& DM)
{
string in_1;
string in_2;
const int x = -1; //for handling exceptions
    if (in1[0] == 'R')
    {
        for (int i=1;i<in1.length();i++)
        {
            in_1+=in1[i]; //in_1 contains the register number
        }
        try {
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

        try{
        if(stoi(in2)>1023 || stoi(in2)<0) //Throwing an exception if a location outside the boundary is trying to be accessed
        {
            throw x;
        }
        }

        catch(int x) {
            cout << "Out of memory bounds\n";
            exit(-1);
        }

        if (DM.datamem[stoi(in_1)]==0)
        {
            PC = stoi(in2);
        }
        else{
            //continue normally
            PC+=1;
        }
    }
    else{
    

        if (stoi(in1)==0)
        {
            PC = stoi(in2);
        }
        else{
            PC+=1;
        }
    }                  
}