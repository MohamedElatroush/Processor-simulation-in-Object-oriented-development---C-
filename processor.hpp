//
//  processor.hpp
//  sim
//
//  Created by Mohamed Hatem on 11/27/19.
//  Copyright © 2019 Mohamed Hatem. All rights reserved.
//

#ifndef processor_hpp
#define processor_hpp

#include <string>
#include <sstream>
#include <fstream>
#include <thread>
#include "ADD.cpp"
#include "MUL.cpp"
#include "NEG.cpp"
#include "JMP.cpp"
#include "JMP0.cpp"
#include "ASS.cpp"
#include "LE.cpp"
#include "READ.cpp"
#include "WRITE.cpp"
#include "HALT.cpp"
#include "operations.cpp"
using namespace std;


class processor{
    public:
    string inst;
    string in1,in2;
    string address;
    string file;
    int no_of_files;
    int file_number;
    int run;
    string line;
       
        processor(string filename, int r,int nooffiles,int file_no){
            line="";
            inst="";
            in1="";
            in2="";
            address="";
            file = filename;
            run = r;
            no_of_files = nooffiles;
            file_number = file_no;
            if (r==0)
            {
                cout <<"Please set run to 1 for the processor to work (set run = 1)\n";
                exit(0);
            }
            else{
        
            InstructionMemory IM;
            IM.load_instructions(file,no_of_files,file_number); //loads instruction from a file to instruction memory    
            DataMemory DM;
            parser(IM,DM);
            }
        }
    
        ~processor()
        {
            //
        }
        
        void parser(InstructionMemory& IM, DataMemory& DM) {
            inst= "";
            in1 = "";
            in2 = "";
            address = "";
            string line;
            ofstream of("Data_Memory.txt");
            PC=0;
    
            
            for (int count=0;count<=1024;count++){
                if (PC==-1)
                {
                    break;
                }
               // getline(in, line); //contains the full instruction
                    string in_1="";
                    string in_2="";
                    line = IM.instmem[PC];
                    stringstream stream(line);

                while((getline(stream, inst, ' ')) && (getline(stream, in1, ',') && (getline(stream, in2, ',')) && (getline(stream, address, '\n')))){}//PARSE THE INSTRUCTIONS
                try{
                   if (inst != "ADD" && inst != "NEG" && inst != "MUL" && inst != "JMP" && inst != "JMP0" && inst != "ASS" && inst != "LE" && inst != "READ" && inst != "WRITE" && inst != "HALT")
                   {
                       if (inst=="")
                       {
                           //cout << IM.instmem[--PC] << endl;
                           if (IM.instmem[PC+1] == "" && IM.instmem[PC+2] == "" && IM.instmem[PC+3] == "" && IM.instmem[PC+4] == ""  )
                           {
                           count=1024;
                           break;
                           }
                           else {
                               PC++;
                           }
                       }
                       else{
                       cerr <<"No instruction named: " <<inst << endl;
                       exit(0);
                       }
                   }
                }
                catch (int x)
                {
                    cout << inst << " doesn't exist\n";
                    cout << "Processor shutting down until the input file is fixed!\n";
                    exit(-1);
                }
                
                operations op(inst,in1,in2,address,of,IM,DM);
                
            }

             
            
            of.close();
        }
    };
    
#endif /* processor_hpp */

