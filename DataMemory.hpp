//
//  DataMemory.hpp
//  sim
//
//  Created by Mohamed Hatem on 11/27/19.
//  Copyright © 2019 Mohamed Hatem. All rights reserved.
//

#ifndef DataMemory_hpp
#define DataMemory_hpp

#include <stdio.h>
#include <iostream>



class DataMemory{
public:
    int datamem[1024];
    DataMemory();
    ~DataMemory();

    void initialize_datamem();
};

#endif /* DataMemory_hpp */
