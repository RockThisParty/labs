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

int jacobi(unsigned int a,unsigned int n)
{
    int s;
    if(a==0) return 0;
    if(a==1) return 1;
    int k=getI(a);
    int r=a>>k;
    if((k&1)==0) 
	{ 
		s=1;
	}
    else if((n&7)==1 || (n&7)==7)
	{ 
		s=1;
	}
    else 
	{
		s=-1;
	}
    if((n&3)==3 && (r&3)==3) 
	{
		s=-s;
	}
    if(r==1) 
	{
		return s;
	}
    return s*jacobi(n%r, r);  
}

unsigned int sstest(unsigned n,int t)
{
  int r, a, s;
	for(int i=0;i<t;++i)
	{
		a=2+rand()%(n-3);
		//std::cout<<"a="<<a<<std::endl;
    	r=binaryDegree_RightToLeft(a,((n-1)>>1), n);
		//std::cout<<"r="<<r<<std::endl;
		if(r!=1 && r!=n-1)
		{
		  //std::cout<<"Sostavnoe"<<std::endl;
		  return 0;
		}
		s=jacobi(a,n);
		//std::cout<<"s="<<s<<std::endl;
		if(r==n-1)
		{
			r=-1;
		}
		if(r!=s)
		{
		  //std::cout<<"Sostavnoe"<<std::endl;
		  return 0;
    	}
	}
  //std::cout<<"Prostoe"<<std::endl;
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
    while(sstest(num, 5)==0);
    return num;
}

int main()
{
	srand(time(0));
	int num;
	/*for(int i=0;i<5;++i){
	num = 3+rand()%1000;
	std::cout<<"num= "<<num<<" ";
	std::cout<<sstest(num,3)<<std::endl;}*/
    for(int i=3;i<=32;++i)
    {
    	std::cout<<test(i)<<std::endl;
    }
}















