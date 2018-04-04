#include <iostream>
#include <cstdlib>
#include <ctime>

unsigned int sqrt(unsigned int a)
{
    unsigned int a0=a;
    unsigned int a1=a0;
    while(1)
    {
      a0=(((a/a0)+a0))>>1;
      if(a0>=a1) return a1;
      else a1=a0;
    }
}

int main()
{
    srand(time(NULL));
    unsigned int a, i;
    std::cin>>a;
    std::cout<<sqrt(a)<<std::endl;
    /*while(sqrt(a)*sqrt(a)<=a && a<((sqrt(a)+1)*(sqrt(a)+1)))
    {
      a=rand()+1;
      std::cout<<"a: "<<a<<std::endl;
      sqrt(a);
      ++i;
      std::cout<<"Count: "<<i<<std::endl;
    }*/
    
}
