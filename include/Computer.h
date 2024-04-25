#ifndef _COMPUTER_H
#define _COMPUTER_H
#include"ALU.h"
#include"CU.h"
#include"In.h"
#include"Out.h"
#include"Memory.h"
#include"types.h"
#include<bits/stdc++.h>
class Computer
{
    public:
    Computer(DWORD);
    void load_from_array(DWORD_PTR,DWORD,DWORD);
    void load_from_file(std::string,DWORD);
    void run(DWORD);
    void run();
    protected:
    private:
    ALU* _ALU;
    CU* _CU;
    In* _In;
    Out* _Out;
    Memory* _Memory;
};
#endif