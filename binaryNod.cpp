#include <iostream>
#include <ctime>

unsigned int degree(unsigned int a)
{
    int degree=0;
    while(a%2==0)
    {
      a/=2;
      degree++;
    }
    return degree;    
}

int power(unsigned int a)
{
    int power=2;
    if(degree(a)==0) 
    {
      power=0;
      return a;
    }
    else
    {
      for(int i=1;i<degree(a);i++) {power*=2;}
      return a/power;
    } 
}

unsigned int min(unsigned int a,unsigned int b)
{
    if(a<b) return a;
    else 
      return b;
}

unsigned int gcd(unsigned int a,unsigned int b)
{
    unsigned int c;
    a=power(a); 
    b=power(b);
    while(a!=b)
    {
      if(a<b)
      {
	int tmp=a;
	a=b;
	b=tmp;
      }
      c=a-b;
      a=power(c);
    }
    for(int i=0;i<min(degree(a), degree(b));i++)
    {
      a*=2;
    }
    return a;     
}


int main()
{
    unsigned int a=214773647, b=214748364;

    unsigned int start_nod=clock();
    std::cout<<nod(a, b)<<std::endl;
    unsigned int end_nod=clock();
    unsigned int time_nod=end_nod-start_nod;
    std::cout<<"Time:"<<time_nod<<std::endl;
}
