#include <iostream>
#include <thread>
#include <vector>
#include "thePrimeFuntor.h"

int isPrime(int num);
void sumCountPrimes(int &sumCount, std::vector <thePrimeFuntor*> functors);

int main(){
    //numberOfThreads = m
    int n {0}, m{0},sumCount {0}, lastElemant {0};

    std::cout << "Enter number n:";
    std::cin >> n;
    std::cout << "Enter number m: ";
    std::cin >> m;
    while(m>n){
        std::cout << "m must be smaller or equal n" << std::endl;
        std::cout << "Enter number n:";
        std::cin >> n;
        std::cout << "Enter number m: ";
        std::cin >> m;
    }


    std::vector<std::thread> threads;
    std::vector<thePrimeFuntor*> functors;

    for (int i = 0; i < m; i++) {
        if(i==(m-1)){
            lastElemant=n;
        }
        else{
            lastElemant = (n/m)*(i+1);
        }
        thePrimeFuntor *functor = new thePrimeFuntor();
        threads.push_back(std::thread(std::ref(*functor),(n/m * i)+1, lastElemant));
        functors.push_back(functor);
    }

    for(std::thread &t : threads){
        if(t.joinable()){
            t.join();
        }
    }   
    

    std::thread lastThread (sumCountPrimes,std::ref(sumCount), functors);
    lastThread.join();
    std::cout << "From 1" << " to " << n<<" devide by " << m <<" threads have: " << sumCount << " numbers"<< std::endl;
    for(int i = 0;sumCount.size();i++){
        std::cout << sumCount[i] << " ";
    }


    return 0;
}

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


void sumCountPrimes(int &sumCount, std::vector <thePrimeFuntor*> functors){
    sumCount = 0;
    for(int i =0; i<functors.size();i++){
        sumCount +=functors[i]->getCount();
    }
}

