//
//  DataMemory.cpp
//  sim
//
//  Created by Mohamed Hatem on 11/27/19.
//  Copyright © 2019 Mohamed Hatem. All rights reserved.
//

#include "DataMemory.hpp"




DataMemory::DataMemory()
{
initialize_datamem();
}

DataMemory::~DataMemory()
{
}

void DataMemory::initialize_datamem()
{

for(int i=0;i<1024;i++)
    {
        datamem[i] = 0;
    }
}

