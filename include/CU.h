#ifndef _CU_H
#define _CU_H
#include"ALU.h"
#include"CU.h"
#include"In.h"
#include"Out.h"
#include"Memory.h"
#include"types.h"
class CU
{
    public:
    CU(In*,Out*,ALU*,Memory*,DWORD);
    void load_code(DWORD_PTR,DWORD,DWORD);
    void run(DWORD);
    void run();
    protected:
    private:
    DWORD entry_point;
    Memory* main_memory;
    ALU* main_alu;
    DWORD PC;
    DWORD execute_code(DWORD);
    In* input_unit;
    Out* output_unit;
};
#endif