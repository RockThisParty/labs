#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>

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

void kanon(unsigned int n, std::map<int, int> &rasl)
{	
	int s=getI(n);		//s=getI()-степень двойки
	if(s!=0)
	{	
		rasl[2]+=s;
		n>>=s;
	}
	int i=3;
	while(n>1)
	{
		while(n%i==0)
		{
			rasl[i]++;
			n/=i;
		}
		i+=2;	
	}
}
	

int luka(unsigned int n, int t)
{
	std::map<int, int> rasl;
	kanon(n-1, rasl);
	int flag;
	for(int i=0;i<t;++i)
	{
		std::map<int, int>::iterator it;
		int a=2+rand()%(n-3);
		for(it=rasl.begin();it!=rasl.end();++it)
		{	
			if(binaryDegree_RightToLeft(a, (n-1),n)==1 && binaryDegree_RightToLeft(a, (n-1)/(it->first), n)!=1)
			{
				flag=1;
			}
			else 
			{	
				flag=0;		
				break;
			}
		}
		if(flag) return 1;
	}
	return 0;
}

unsigned test(int k)
{
	unsigned num;
	do
	{
		num=gen(k);
	}
	while(luka(num,5)==0);
	return num;
}

int main()
{
	srand(time(0));
	/*for(int i=3;i<=32;++i)
	{
		std::cout<<i<<". "<<test(i)<<std::endl;
	}*/
	std::cout<<luka(133, 5)<<std::endl;
	
	//kanon(255, rasl);
}
