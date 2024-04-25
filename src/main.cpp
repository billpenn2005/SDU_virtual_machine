#include<bits/stdc++.h>
#include"../include/ALU.h"
#include"../include/CU.h"
#include"../include/In.h"
#include"../include/Out.h"
#include"../include/Memory.h"
#include"../include/Computer.h"
using namespace std;
int main()
{
    Computer a(1024);
    string file_name;
    cin>>file_name;
    a.load_from_file(file_name,0);
    a.run(0);
    return 0;
}