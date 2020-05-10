#include "READ.hpp"

READ::READ(){
    inst = "";
    in1 = "";
    in2 = "";
    address = "";
}

READ::~READ(){
    //Destructor
}


void READ::execute(string inst, string in1, string in2, string address, ofstream& of, InstructionMemory& IM, DataMemory& DM)
{
string in_1;
string in_2;
int read=0;
int x = -1;

if (in1[0] == 'R')
{
for (int i=1;i<in1.length();i++)
{
in_1+=in1[i]; //in_2 contains the register number
}

try{
if(stoi(in_1)>1023 || stoi(in_1)<0) //Throwing an exception if a location outside the boundary is trying to be accessed
{
    throw x;
}
}
catch (int x) {
    cout << IM.instmem[PC] << " out of memory bounds\n";    
    cout << "Processor shutting down!\n";
    exit(-1);    
}
        
cout << "Enter an input: ";
while(!(cin>>read))
{
cout << "++ERROR: Enter an integer: ";
cin.clear();
cin.ignore(123,'\n');
}

cout << read << " have been inserted in R" << in_1 << endl;
DM.datamem[stoi(in_1)] = read;
of<<stoi(in_1) <<": " << DM.datamem[stoi(in_1)] << endl;
}

else
{
try {
if(stoi(in1)>1023 || stoi(in1)<0) //Throwing an exception if a location outside the boundary is trying to be accessed
{
    throw x;
}
}
catch (int x) {
cout << IM.instmem[PC] << " out of memory bounds\n";
cout << "Processor shutting down!\n";
exit(-1);
}

cout << "Enter an input: ";
while(!(cin>>read))
{
cout << "++ERROR: Enter an integer: ";
cin.clear();
cin.ignore(123,'\n');
}


cout << read << " have been inserted in R" << in1 << endl;
DM.datamem[stoi(in1)] = read;
of<<stoi(in1) <<": " << DM.datamem[stoi(in1)] << endl;
}
    
                       
}