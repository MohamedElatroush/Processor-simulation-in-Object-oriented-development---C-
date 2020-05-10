//
//  InstructionMemory.cpp
//  sim
//
//  Created by Mohamed Hatem on 11/27/19.
//  Copyright © 2019 Mohamed Hatem. All rights reserved.
//

#include "InstructionMemory.hpp"

InstructionMemory::InstructionMemory()
{
    Set_INSTMEM_Size();
}

InstructionMemory::~InstructionMemory() //destructor
{
}

void InstructionMemory::Set_INSTMEM_Size()
{
init_instmem(instmem, MEMSIZE);
}

void InstructionMemory::init_instmem(string instmem[], int MEMSIZE)
{
    for (int i=0;i<MEMSIZE;i++)
    {
        instmem[i] = "";
    }
}

void InstructionMemory::load_instructions(string filename, int nofiles, int filenum)
{
        string line;
        ifstream in;
        int x = -1;
        int pc_checker=-1;
        stringstream ss; 
        ss<<filenum;
        string s;
        ss>>s;
        string file_name = "instruction_memory"+s+".txt";
        ofstream outfile (file_name);
        string inst;
        in.open(filename);
        
        if(!in.is_open())
        {
            cerr << "Can't open file!\n";
            exit(-1);
        }
        cout << "InstMem: \n";
        PC=0;
        while(!in.eof())
        {
            getline(in, line);
            instmem[PC] = line;
            cout << instmem[PC] << endl;
            if (instmem[PC]=="HALT")
            {
                pc_checker = PC;
            }
            outfile <<"Location "<< PC << " in instruction memory: " <<line <<endl;
            PC=PC+1;
        }

        try {

            if (pc_checker==-1)
            {
                throw x;
            }
        }
        catch (int x){
            cerr <<"++Last instruction should be HALT++\n";
        }
        in.close();
        outfile.close();
}

void InstructionMemory::del_instmem()
{
    for (int i=0;i<MEMSIZE;i++)
    {
        if (instmem[i] != "")
        {
            instmem[i] = "";
        }
        else
        {
            //do nothing
        }
    }
}



