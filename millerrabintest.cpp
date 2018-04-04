#include <iostream>
#include <cstdlib>
#include <ctime>

int getI(int a)
{
int i;
for(i=0; !((a>>i)& 1); i++);
return i;
} 

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

int miller_rabin(unsigned n, int t)
{
    unsigned s=getI(n-1);
    //std::cout<<"s: "<<s<<std::endl;
    unsigned r=n>>s;
    //std::cout<<"r: "<<r<<std::endl;
    unsigned y, b;
    for(int i=0;i<t;++i)
    {
	b=2+rand()%(n-3);
    	y=binaryDegree_RightToLeft(b,r, n);
	if(y!=1 && y!=(n-1))
	{
	    int j =1;
	    while(j<s && y!=(n-1))
	    {
		y=(y*y)%n;
		if(y==1)
		{
		    //std::cout<<"-Число составное"<<std::endl;
		    return 0;
		}
		++j;
	    }
	    if(y!=(n-1))
	    {
		//std::cout<<"-Число составное"<<std::endl;
		return 0;
	    }
	}
    }
    //std::cout<<"-Число простое"<<std::endl;
    return 1;
}

unsigned int test(int k)
{
    unsigned int num;
    do
    {
	num=gen(k);
	//std::cout<<"num: "<<num<<std::endl;
    } 
    while(miller_rabin(num, 5)==0);
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
