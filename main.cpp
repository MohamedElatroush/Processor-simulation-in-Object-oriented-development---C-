#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <thread>
#include <mutex>
#include <iomanip>
#include "InstructionMemory.hpp"
#include "InstructionMemory.cpp"
#include "DataMemory.cpp"
#include "DataMemory.hpp"
#include "processor.hpp"



using namespace std;

int main()
{
    //thread t;
    int run=1; //if run = 0 the processor will not work (acting as a power switch)
    string file = "";
    int no_of_files = 0;
    cout << "Press 1 to turn on the processor, or 0 to terminate: ";
    cin >> run;
    while(run!=0 && run!=1)
    {
        cout << "Press 1 to turn on the processor, or 0 to terminate: ";
        cin >> run;
    }

    if (run)
    {
        cout << "How many files would you like to execute?\n";
        cin >> no_of_files;
        while (no_of_files < 0)
        {
            cout <<"Invalid number of file(s) [Enter number of files: ]: ";
            cin >> no_of_files;
        }
        for (int i=0; i<no_of_files;i++)
        {
        cout << "File "<< i+1 <<" to execute: ";
        cin >> file;
        
        
        processor p(file,run,no_of_files,i+1);
        cout << "Executing " << file << endl;
        //t.detach();
        //processor p;
        //std::thread threadObj(&processor::proc,&p,file,run,no_of_files,i+1);
    //    std::thread t1(&processor::proc, this, file,run,no_of_files,i+1 );
    

        cout << "The file 'InstructionMemory"<< i+1<<".txt' has been created\n";
        //th.join();
        
       
        }
       // t.join();
       
    }
    
    
    
    return 0;
}
