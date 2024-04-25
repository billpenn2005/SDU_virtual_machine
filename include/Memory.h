#ifndef _MEMORY_H
#define _MEMORY_H
#include"types.h"
class Memory
{
    public:
    Memory(int);
    DWORD read(DWORD);
    DWORD write(DWORD,DWORD);
    ~Memory();
    protected:
    private:
    DWORD_PTR memory_space;
    DWORD max_range;
};
#endif