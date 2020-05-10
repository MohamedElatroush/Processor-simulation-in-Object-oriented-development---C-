#include "operations.hpp"
#include <thread>
#include "InstructionMemory.hpp"
#include "DataMemory.hpp"
#include "ADD.hpp"
#include "MUL.hpp"
#include "NEG.hpp"
#include "JMP.hpp"
#include "JMP0.hpp"
#include "ASS.hpp"
#include "LE.hpp"
#include "READ.hpp"
#include "WRITE.hpp"
#include "HALT.hpp"
operations::operations(){
}


operations::~operations(){
    //Destructor
}

operations::operations(string inst, string in1, string in2, string address, ofstream& of, InstructionMemory& IM, DataMemory& DM){
    execute(inst,in1,in2,address,of,IM,DM);
}


void operations::execute(string inst, string in1, string in2, string address, ofstream& of, InstructionMemory& IM, DataMemory& DM)
{
                mutex datamem_lock;
                lock_guard<mutex>lock(datamem_lock);
                if (inst == "ADD")
                {
                    ADD a;
                    a.execute(inst,in1,in2,address,of,IM,DM);
                    PC+=1;
                }
                        
                if(inst=="MUL")
                {
                    MUL m; 
                    m.execute(inst,in1,in2,address,of,IM,DM);
                    PC+=1;
                }
                        
                if(inst=="LE")
                {
                    LE L; 
                    L.execute(inst,in1,in2,address,of,IM,DM);
                    PC+=1;
                }
                        
                if (inst=="NEG") //in2 here acts as the address
                {
                    NEG n;
                    n.execute(inst,in1,in2,address,of,IM,DM);
                    PC+=1;
                }
                    
                if (inst=="JMP0") //in2 is the address
                {
                    JMP0 J0;
                    J0.execute(inst,in1,in2,address,of,IM,DM);
                }
                
                if(inst=="ASS") //in2 is the address in datamemory
                {
                    ASS AS;
                    AS.execute(inst,in1,in2,address,of,IM,DM);
                    PC+=1;
                }
                
                if(inst=="JMP")
                {
                    JMP J;
                    J.execute(inst,in1,in2,address,of,IM,DM);
                    
                }
                
                if(inst=="HALT")
                {
                    HALT H;
                    H.execute(inst,in1,in2,address,of,IM,DM);
                    of<<"PROGRAM HALTED"<<endl;
                }
                
                if (inst=="READ"){
                    READ R;
                    R.execute(inst,in1,in2,address,of,IM,DM);
                    PC+=1;
                }
                
                if (inst=="WRITE"){
                    WRITE W;
                    W.execute(inst,in1,in2,address,of,IM,DM);
                }
}
