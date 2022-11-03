#ifndef CHECKPRIME_H
#define CHECKPRIME_H

#include <iostream>

int isPrime(int num){
   if (num <= 1){
        return 0;
   }
   for (int i = 2; i <= num/2; i++){
    if (!(num % i)){ 
        return 0; 
    }
   }
   return 1;
}
void countPrimes(int &count,int strt,int end){
    count = 0;
    for(int i=strt;i<=end;i++){
        if(isPrime(i))
        { 
            std::cout << i << " ";
            count++; 
        }
    }
    std::cout <<'\n';
}




#endif