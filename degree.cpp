#include <iostream>


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

int nlz(unsigned int x)
{
    int n=0;
    if((x>>16)==0) {n+=16;x<<=16;}
    if((x>>24)==0) {n+=8;x<<=8;}
    if((x>>28)==0) {n+=4;x<<=4;}
    if((x>>30)==0) {n+=2;x<<=2;}
    if((x>>31)==0) n++;
   return n;
}


unsigned long long int LeftToRightDone(unsigned int x,unsigned int y,unsigned int m)
{
    unsigned long long int z=x;
    int n=nlz(y), i=0;
    n++;
    y<<=n;
    int tmp =0;
    while(sizeof(y)*8-n)
    {
	std::cout<<"tmp:"<<tmp<<std::endl;
	std::cout<<"z:"<<z<<std::endl;
	i++;
	z=(z*z)%m;
	if(y>>(sizeof(y)*8-i)&1) {z=(z*x)%m;}
	n++;
	tmp++;
    }
    return z;
}

int main()
{
	unsigned int x,y,m;
	std::cout<<binaryDegree_RightToLeft(54,36319,36319)<<std::endl;
	//std::cout<<"n:"<<nlz(36319)<<std::endl;
	std::cout<<LeftToRightDone(54,36319,36319)<<std::endl;
}
