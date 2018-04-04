#include <iostream>
#include <ctime>

int nod(int a, int b)
{
    while(a > 0 && b > 0)
 
        if(a > b)
            a %= b;
 
        else
            b %= a;
 
    return a + b;
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
