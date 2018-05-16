#pragma once
#include <map>
#include "getI.h"
#include "gen.h"
#include "degree.h"


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
	/*std::map<int, int>::iterator it;
	std::cout<<"1";
	for(it=rasl.begin();it!=rasl.end();++it)
	{
		std::cout<<"*"<<it->first<<"^"<<it->second;
	}
	std::cout<<std::endl;*/
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

int luka(unsigned int n, int t)
{
	std::map<int, int> rasl;
	kanon(n-1, rasl);
	int flag;
	for(int i=0;i<t;++i)
	{
		int a=2+rand()%(n-3);
		if(binaryDegree_RightToLeft(a, (n-1),n)!=1)
		{
			return 0;
		}
		std::map<int, int>::iterator it;
		for(it=rasl.begin();it!=rasl.end();++it)
		{
			if(binaryDegree_RightToLeft(a, (n-1)/(it->first), n)!=1)
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
