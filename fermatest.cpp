#include <iostream>
#include <cstdlib>
#include <ctime>

unsigned long long int binaryDegree_RightToLeft(unsigned int x,unsigned int y,unsigned int m)
{
    unsigned long long int z, q;
    q=x;
    if(y&1) {z=x;}
    else    {z=1;}
    while(y>>=1)
    {
        q=(q*q)%m;
        if(y&1) {z=(z*q)%m;}
    }
    return z;
}

unsigned int fermaTest(unsigned int n, int t)
{
    unsigned int a;
    unsigned long long r;
    for(int i=0;i<t;++i)
    {
	a=2+rand()%(n-3);
	r=binaryDegree_RightToLeft(a, n-1, n);
	if(r!=1)
	{		
	    //std::cout<<"-Число составное"<<std::endl;
	    return 0;
	}
    }
    return 1; 
}

unsigned int genprim(int k)
{
    unsigned int num = rand();
    num |=(1<<(k-1));
    unsigned mask =~0;
    mask>>=(32-k);
    num&=mask;
    num|=1;
    return num;
}

unsigned int test(int k)
{
    unsigned int num;
    do
    {
	num=genprim(k);
	//std::cout<<"num: "<<num<<std::endl;
    } 
    while(fermaTest(num, 5)==0);
    return num;
}

int main()
{
    srand(time(0));
    for(int i=3;i<=32;++i)
    {
      std::cout<<i<<". "<<test(i)<<std::endl;
    }
}
