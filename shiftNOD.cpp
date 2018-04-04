#include <iostream>
#include <ctime>
#include <cstdlib>

unsigned int degree(unsigned int a)
{
    int degree=0;
    while(!a&1)
    {
      a>>=1;
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
      for(int i=1;i<degree(a);i++) {power<<=1;}
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
    //std::cout<<a<<"  "<<b<<std::endl;
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

int nod(int a, int b)
{
    while(a > 0 && b > 0)
 
        if(a > b)
            a %= b;
 
        else
            b %= a;
 
    return a+b;
}


int main()
{
    srand(time(NULL));
    int x, y, i=0, a, b;
    /*while(1)
    {
      //a=rand()+1;
      //b=rand()+1;
      a=1024;
      b=1000;
      x=nod(a,b);
      y=gcd(a,b);
      std::cout<<x<<"   "<<y<<std::endl;
      if(x==y)
      {
       i++;
       std::cout<<"+"<<"Count:"<<i<<std::endl;
      }
      else
      {
       std::cout<<"a:"<<a<<"  "<<"b:"<<b<<std::endl;
       return 0;
      }
    }*/

    
}
