#include "thePrimeFuntor.h"


void thePrimeFuntor::operator() (int start, int end){
    for(int i = start; i<= end;i++){
        if(isPrime(i)){
            count++;
        }
    }
}

int thePrimeFuntor::getCount(){
    return this->count;
}
