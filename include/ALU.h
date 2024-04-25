#ifndef _ALU_H
#define _ALU_H
#include"types.h"
class ALU
{
    public:
    void load(DWORD);
    void add(DWORD);
    void sub(DWORD);
    void mul(DWORD);
    void div(DWORD);
    DWORD get();
    protected:
    private:
    DWORD num;
};
#endif