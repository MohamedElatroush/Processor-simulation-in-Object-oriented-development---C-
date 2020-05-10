#include "MUL.hpp"

MUL::MUL(){
    inst = "";
    in1 = "";
    in2 = "";
    address = "";
}

MUL::~MUL(){
    //Destructor
}

void MUL::execute(string inst, string in1, string in2, string address, ofstream& of, InstructionMemory& IM, DataMemory& DM)
{
string in_1;
string in_2;
int x = -1;
try {
if(stoi(address)>1023 || stoi(address)<0) //Throwing an exception if a location outside the boundary is trying to be accessed
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
    in_1="";
    in_2="";
    
    if (in1[0] == 'R' && in2[0] == 'R'){
        for (int i=1;i<in1.length();i++)
        {
            in_1+=in1[i];
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
        
        for (int i=1;i<in2.length();i++) // extracting register number and saving it to in_2
        {
            in_2+=in2[i];
        }
        try {
        if(stoi(in_2)>1023 || stoi(in_2)<0) //Throwing an exception if a location outside the boundary is trying to be accessed
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
        
        DM.datamem[stoi(address)] = DM.datamem[stoi(in_1)]*DM.datamem[stoi(in_2)];
        of << address << ": " <<DM.datamem[stoi(address)]<<endl;
    }
    
    else if(in1[0] == 'R' && in2[0]!='R'){
        for (int i=1;i<in1.length();i++) // extracting register number and saving it to in_1
        {
            in_1+=in1[i];
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
        DM.datamem[stoi(address)] = DM.datamem[stoi(in_1)] * stoi(in2); //adding two registers
        of << address << ": " <<DM.datamem[stoi(address)]<<endl;
    }
    
    else if(in1[0] != 'R' && in2[0]=='R'){
        for (int i=1;i<in2.length();i++) // extracting register number and saving it to in_1
        {
            in_2+=in2[i];
        }
        try {
        if(stoi(in_2)>1023 || stoi(in_2)<0) //Throwing an exception if a location outside the boundary is trying to be accessed
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
        DM.datamem[stoi(address)] = stoi(in1) * DM.datamem[stoi(in_2)]; //adding two registers
        of << address << ": " <<DM.datamem[stoi(address)]<<endl;
    }
    
    
    
    
    else{ //multiply constants
        DM.datamem[stoi(address)] = stoi(in1)*stoi(in2);
        of << address << ": " <<DM.datamem[stoi(address)]<<endl;
    }

}