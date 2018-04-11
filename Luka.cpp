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

int getI(int a)
{
  int i;
  for(i=0; !((a>>i)& 1); i++);
  return i;
}

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

unsigned int gen(int k)
{
    unsigned int num = rand();
    num |=(1<<(k-1));
    unsigned mask =~0;
    mask>>=(32-k);
    num&=mask;
    num|=1;
    return num;
}

int kanon(unsigned int n)
{	
	if(n==1)
	{
		return n;
	}
	if((n&1)==0)
	{
		//for(int i=0;i<getI(n);++i)
		//{
		//	std::cout<<2<<"*";
		//}
		std::cout<<2<<"*";
		n>>=getI(n);
	}
	std::cout<<"n= "<<n<<std::endl;
		for(int i=3;i<=sqrt(n);i+=2)
		{
			//std::cout<<"Sqrt= "<<sqrt(n)<<std::endl;
			//std::cout<<"n1= "<<n<<std::endl;
			if((n%i)==0)
			{
				n/=i;
				std::cout<<i<<"*";
				//std::cout<<n/i<<std::endl;
				kanon(n/i);
			}	
		}
	return n;
}	

int luka(unsigned int a, int t)
{
	
}

int main()
{
	kanon(222);
}
