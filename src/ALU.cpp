#include"../include/ALU.h"
#include"../include/types.h"
#include<bits/stdc++.h>
using namespace std;

void ALU::add(DWORD b)
{
    num+=b;
}
void ALU::sub(DWORD b)
{
    num-=b;
}
void ALU::load(DWORD b)
{
    num=b;
}
void ALU::mul(DWORD b)
{
    num*=b;
}
void ALU::div(DWORD b)
{
    num/=b;
}
DWORD ALU::get()
{
    return num;
}