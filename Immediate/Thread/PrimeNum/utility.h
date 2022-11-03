#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <vector>

void sumCountPrimes(int &sumCount, std::vector <int> allCounts){
    for(int i =0; i<allCounts.size();i++){
        sumCount+=allCounts[i];
    }
}

template<class T>
void printVector(std::vector<T> input) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    std::cout << n;
    if (count < input.size()) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}

#endif