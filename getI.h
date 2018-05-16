#pragma once
#include<iostream>

int getI(int a)
{
  int i;
  for(i=0; !((a>>i)& 1); i++);
  return i;
}
