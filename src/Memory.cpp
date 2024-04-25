#include"../include/Memory.h"
#include"../include/types.h"
#include<bits/stdc++.h>
using namespace std;

Memory::Memory(int size=1)
{
    memory_space=(DWORD_PTR)malloc(size*sizeof(DWORD));
    max_range=size-1;
}

DWORD Memory::read(DWORD addr)
{
    if(addr>max_range||addr<0)
    {
        puts("WARNING: Address out of range.\nexiting...");
        exit(0);
    }
    DWORD ret=*(memory_space+addr);
    return ret;
}

DWORD Memory::write(DWORD addr,DWORD data)
{
    if(addr>max_range||addr<0)
    {
        puts("WARNING: Address out of range.\nexiting...");
        exit(0);
    }
    *(memory_space+addr)=data;
    return data;
}

Memory::~Memory()
{
    free(memory_space);
}