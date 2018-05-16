#pragma once

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
