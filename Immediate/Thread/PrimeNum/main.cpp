#include <iostream>
#include <thread>
#include <vector>
#include "checkPrime.h"
#include "utility.h"


int main(){
    //numberOfThreads = m
    int n {0}, m{0},sumCount {0}, lastElemant {0};
    std::vector<std::thread> threads;

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

    std::vector <int> all_counts(m);

    for (int i = 0; i < m; i++) {
       if(i==(m-1)){
            lastElemant=n;
        }
        else{
            lastElemant = (n/m)*(i+1);
        }

        threads.push_back(std::thread(countPrimes, std::ref(all_counts[i]), (n/m * i)+1, lastElemant));   
    }

    for(std::thread &t : threads){
        if(t.joinable()){
            t.join();
        }
    }   

    printVector(all_counts);
    std::thread lastThread (sumCountPrimes,std::ref(sumCount),all_counts);
    lastThread.join();
    std::cout << "From 1" << " to " << n<<" devide by " << m <<" threads have: " << sumCount << " numbers"<< std::endl;


    return 0;
}