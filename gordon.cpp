#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include "headers/getI.h"
#include "headers/gen.h"
#include "headers/degree.h"
#include "headers/tests.h"

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

unsigned int gordon(int k)
{
  bool flag=true;
  unsigned long long p0;
  //unsigned long long max=pow(2,32);
  do
  {
    unsigned s=test(k);
  	//std::cout<<"s= "<<s<<std::endl;
  	unsigned t=test(k);
  	//std::cout<<"t= "<<t<<std::endl;
    unsigned i0=1+rand()%7;
    //std::cout<<"i0= "<<i0<<std::endl;
    t<<=1;
    unsigned r=t*i0+1;
    do {
      unsigned tmp=r;
      r+=t;
      if(r<tmp)
      {
        flag=false;
      }
    	//std::cout<<"r= "<<r<<std::endl;
    } while(!miller_rabin(r, 3));
  	p0=2*(binaryDegree_RightToLeft(s,(r-2),r))*s-1;
  	//std::cout<<"p0= "<<p0<<std::endl;
  	unsigned j0=1+rand()%7;
  	//std::cout<<"j0= "<<j0<<std::endl;
    s*=(r<<1);
    p0+=(s*j0);
    while(!miller_rabin(p0,3))
    {
      unsigned long long p=p0;
      p0+=s;
      if(p0<p)
      {
        flag=false;
      }
      //std::cout<<p0<<"  ";
    }
    std::cout<<std::endl;
  	return p0;
  }
  while(flag);
}


int main()
{
	srand(time(NULL));
  int k=3+rand()%12;
  for(int i=0; i<10;++i)
  {
    std::cout<<i+1<<". "<<gordon(k)<<std::endl;
  }
}
