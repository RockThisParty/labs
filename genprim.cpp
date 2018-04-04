#include <iostream>
#include <cstdlib>
#include <ctime>

unsigned gen(int k)
{
    unsigned num = rand();
    num |=(1<<(k-1));
    unsigned mask =~0;
    mask>>=(32-k);
    num&=mask;
    return num|1; 
}


int main()
{
   
srand(time(NULL));
   for(int i=1;i<=32;++i)
   {
     std::cout<<i<<". "<<gen(i)<<std::endl;
   }
}

