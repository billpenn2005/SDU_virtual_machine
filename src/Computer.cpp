#include"../include/Computer.h"
#include"../include/types.h"
using namespace std;

Computer::Computer(DWORD size=200)
{
   _In=new In(); 
   _Out=new Out();
   _Memory=new Memory(size);
   _ALU=new ALU();
   _CU=new CU(_In,_Out,_ALU,_Memory,0);
}

void Computer::load_from_array(DWORD_PTR _array,DWORD size,DWORD entry_point)
{
   _CU->load_code(_array,size,entry_point); 
}

void Computer::load_from_file(string file_name,DWORD entry_point)
{
    /*
    File format:
    size
    code
    ...
    */
    ifstream is(file_name);
    DWORD size;
    is>>size;
    DWORD_PTR _array=(DWORD_PTR)malloc((size+10)*sizeof(DWORD));
    for(int i=0;i<size;++i)
        is>>*(_array+i);
    load_from_array(_array,size,entry_point);
    free(_array);
    is.close();
}

void Computer::run(DWORD addr)
{
    _CU->run(addr);
}

void Computer::run()
{
    _CU->run();
}