//
//  InstructionMemory.hpp
//  sim
//
//  Created by Mohamed Hatem on 11/27/19.
//  Copyright © 2019 Mohamed Hatem. All rights reserved.
//

#ifndef InstructionMemory_hpp
#define InstructionMemory_hpp

#include <string>
#include <fstream>
#include <stdio.h>
#include <thread>
#include <sstream>
#include <iostream>


using namespace std;

const int MEMSIZE = 1024;
int PC = 0;

class InstructionMemory{
private:
    string filename;
    int number_of_files;
    int file_numb;

    public:
    string instmem[MEMSIZE];
    InstructionMemory(); //constructor{}
    ~InstructionMemory(); //destructor{}
    void Set_INSTMEM_Size();
    void init_instmem(string instmem[], int MEMSIZE);
    void load_instructions(string filename,int , int);
    void del_instmem();

};

#endif /* InstructionMemory_hpp */
