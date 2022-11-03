#include "ticket.h"


std::string ticket::getDeparture(){
    return departureCity;
}
std::string ticket::getDestination(){
    return destinationCity;
}
int ticket::getTickets(){
    return numberOfTickets;
}

dateOfTime ticket::getDay(){
  return timeOfTravel;
}

int ticket::getDate(){
    return timeOfTravel.date;
}        
int ticket::getMonth(){
    return timeOfTravel.month;
}        
int ticket::getYear(){
    return timeOfTravel.year;
}

void ticket::setDay(int date, int month, int year){
  timeOfTravel.date = date;
  timeOfTravel.month = month;
  timeOfTravel.year = year;
}

void ticket::setDay(){
  std::cout << "Enter your time of travel: ";
    std::cout << "\nDay: ";
    std::cin >> timeOfTravel.date;
    while(timeOfTravel.date>31 ||timeOfTravel.date <0){
        std::cin.clear();
        std::cout << "Error syntax: enter your date again: ";
        std::cin >> timeOfTravel.date;
    }
    std::cout << "Month: ";
    std::cin >> timeOfTravel.month;
    while(timeOfTravel.month>12 ||timeOfTravel.month <1){
        std::cin.clear();
        std::cout << "Error syntax: enter your month again: ";
        std::cin >> timeOfTravel.month;
    }
    std::cout << "Year: ";
    std::cin >> timeOfTravel.year;
    while(timeOfTravel.year>2025 ||timeOfTravel.year <0){
        std::cin.clear();
        std::cout << "Error syntax: enter your year again: ";
        std::cin >> timeOfTravel.year;
    }
}




void ticket::setDepartureCity(std::string departureCity){
    this->departureCity = departureCity;
}
void ticket::setDestinationCity(std::string destinationCity){
    this->destinationCity = destinationCity;
}

void ticket::setTicket(int numberOfTickets){
    this->numberOfTickets = numberOfTickets;
}

void ticket::setDepartureCity(){
    std::cout << "Enter your departure city: " ;
    std::cin >> this->departureCity;
}
void ticket::setDestinationCity(){
    std::cout << "Enter your destination city: " ;
    std::cin >> this->destinationCity;
}

void ticket::setTicket(){
    std::cout << "Enter your number of ticket: " ;
    std::cin >> this->numberOfTickets;
}