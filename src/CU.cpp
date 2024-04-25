#include"../include/CU.h"
#include"../include/types.h"
#include"../include/ALU.h"
#include"../include/In.h"
#include"../include/Out.h"
#include<bits/stdc++.h>
using namespace std;

CU::CU(In* inp,Out* ou,ALU* _main_alu,Memory* _main_memory,DWORD _entry_point):main_alu(_main_alu),main_memory(_main_memory),entry_point(_entry_point),PC(_entry_point),input_unit(inp),output_unit(ou)
{

}

void CU::load_code(DWORD_PTR code_space,DWORD size,DWORD addr)
{
    for(int i=0;i<size;++i)
        main_memory->write(addr+i,*(code_space+i));
}

DWORD CU::execute_code(DWORD op)
{
    DWORD nu=op%100;
    op/=100;
    switch (op)
    {
    case 10://input 
        main_memory->write(nu,input_unit->read_dword());
        break;
    case 11://output
        output_unit->output_dowrd(main_memory->read(nu));
        break;
    case 20://load
        main_alu->load(main_memory->read(nu));
        break;
    case 21://store
        main_memory->write(nu,main_alu->get());
        break;
    case 30://add
        main_alu->add(main_memory->read(nu));
        break;
    case 31://sub
        main_alu->sub(main_memory->read(nu));
        break;
    case 32:
        main_alu->mul(main_memory->read(nu));
        break;
    case 33:
        main_alu->div(main_memory->read(nu));
        break;
    case 40://br(jmp)
        PC=nu;
        return 0;
        break;
    case 43://halt
        return 1;
        break;
    default:
        puts("WARNING: Wrong Code.\nexiting...");
        exit(0);
        break;
    }
    PC+=1;
    return 0;
}

void CU::run(DWORD addr)
{
    PC=addr;
    while(execute_code(main_memory->read(PC))==0);
}

void CU::run()
{
    run(entry_point);
}