#ifndef THEPRIMEFUNTOR_H
#define THEPRIMEFUNTOR_H


#include <iostream>
#include <vector>

extern int isPrime(int num);

class thePrimeFuntor{
  public:
    int count = 0;
  public:
    void operator() (int start, int end);
    int getCount();
};


#endif

