#include"passenger.h"


std::string passenger::getName(){
    return this->nameOfPassenger;
}

int passenger::getSeatNum(){
    return seatNum;
}



void passenger::setName(std::string nameOfPassenger){
    this->nameOfPassenger = nameOfPassenger;
}

void passenger::setName(){
    std::cout << "\nEnter your name:";
    std::cin >> this->nameOfPassenger;      
}

void passenger::setSeatNum(int seatNum){
    this->seatNum = seatNum;
}

void passenger::setSeatNum(){
    std::cout << "Enter your number of ticket: ";
    std::cin >> this->seatNum;
}



void passenger::setNameAndTiket(){
 
    std::cout << "\nEnter your name:";
    std::cin >> this->nameOfPassenger;
    // std::cout << "Enter your number of tickets:";
    // std::cin >> this->numberOfTickets;

}

void passenger::setNameAndSeat(){
    std::cout << "\nEnter your name:";
    std::cin >> this->nameOfPassenger;
    std::cout << "Enter your number of seatNum:";
    std::cin >> this->seatNum;
}





