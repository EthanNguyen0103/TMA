#include "setupReservation.h"


void setupReservation::setInformmation(){
    newPassenger.setName();
    newTicket.setDepartureCity();
    newTicket.setDestinationCity();
    newTicket.setDay();
    newTicket.getTickets();
}

void setupReservation::getInformmation(){
    newPassenger.getName();
    newTicket.getDeparture();
    newTicket.getDestination();
    newTicket.getDay();
    newPassenger.getSeatNum();
}



void setupReservation::setPassengerandTicket( std::vector<passenger> &passengers, std::vector<ticket> &tickets){
    passengers.push_back(newPassenger);
    tickets.push_back(newTicket);
}

void setupReservation::setUsedChair(int seatNum, std::vector <int> &usedChair){
    usedChair.push_back(seatNum);
}


void setupReservation::setUserChoice(){
    std::cin >> userChoice;
    this->userChoice = userChoice;
}

int setupReservation::getUserChoice(){
    return this->userChoice;   
}


int setupReservation::reserveTicket(std::vector <int> &usedChair, std::vector <passenger> &passengers, std::vector<ticket> &tickets){
    int seatNum = 0;
    if(!usedChair.empty()){
       std::sort(usedChair.begin(),usedChair.end());
        for(int i = 0; i < usedChair.size();i++){
        if(seatNum!=usedChair[i]){
            this->setInformmation();
            newPassenger.setSeatNum(seatNum);
            std::cout << "Your seat number:" << seatNum << std::endl;
            passengers.push_back(newPassenger);
            tickets.push_back(newTicket);
            usedChair.push_back(seatNum);
            showReservation::showInformation(newPassenger, newTicket);
            return 1;
        }
            seatNum++;
        }
    }
    this->setInformmation();
    newPassenger.setSeatNum(seatNum);
    passengers.push_back(newPassenger);
    tickets.push_back(newTicket);
    usedChair.push_back(seatNum);
    showReservation::showInformation(newPassenger, newTicket);
    return 0;
}

int setupReservation::modifyReservation(std::vector <passenger> &passengers, std::vector<ticket> &tickets){
    if(!passengers.empty()){
        newPassenger.setNameAndSeat();
        for(int i = 0; i < passengers.size(); i++){
            if(newPassenger.getName() == passengers[i].getName() && newPassenger.getSeatNum() == passengers[i].getSeatNum()){
                std::cout << "Your last inforamtion: " <<std::endl; 
                showReservation::showInformation(passengers[i], tickets[i]);
                std::cout << "You are changing information" << std::endl;
                passengers[i].setName();
                tickets[i].setDepartureCity();
                tickets[i].setDestinationCity();
                tickets[i].setDay();
                tickets[i].getTickets();
                std::cout << "Your new information: "<< std::endl;
                showReservation::showInformation(passengers[i], tickets[i]);
                return 1;
            }
        }
        std::cout << "Don't have passenger information" << std::endl;
        return 0;
    }
    else
        std::cout << "Don't have information passenger to search" << std::endl;

    return 0;
}

int setupReservation::cancelReservation(std::vector <passenger> &passengers, std::vector <int> &usedChair, std::vector<ticket> &tickets){
    if(!passengers.empty()){
        newPassenger.setName();
        newTicket.setTicket();
        for(int i = 0; i < passengers.size(); i++){
            if(newPassenger.getName() == passengers[i].getName() && newTicket.getTickets() == tickets[i].getTickets()){
                passengers.erase(passengers.begin()+i);
                tickets.erase(tickets.begin()+i);
                std::cout << "You are deleted information" << std::endl;
                for(int j = 0;j<usedChair.size();j++){
                    if(usedChair[j] == passengers[j].getSeatNum()){
                        usedChair.erase(usedChair.begin()+j);
                    }
                }
                return 1;
            }
        }
        std::cout << "Don't have passenger information" << std::endl;  
        return 0;
    };
    return 0;
}

int setupReservation::searchByName(std::vector <passenger> &passengers, std::vector<ticket> &tickets){
    if(!passengers.empty()){
        int count = 0;
        newPassenger.setName();
        for(int i = 0; i<passengers.size();i++){
            if(passengers[i].getName() == newPassenger.getName()){
                std::cout <<"\nInfomation:" << std::endl;
                showReservation::showInformation(passengers[i], tickets[i]);
                count++;
            }
        }
        if(count !=0){
            return 1;
        }

        std::cout << "Don't have passenger information" << std::endl;
        return 0;
    };
    return 0;
}

int setupReservation::searchByDate(std::vector <passenger> &passengers, std::vector<ticket> &tickets){
    if(!passengers.empty()){
        int count = 0;
        newTicket.setDay();
        for(int i = 0; i<passengers.size();i++){
            if(tickets[i].getDay() == newTicket.getDay()){
                showReservation::showInformation(passengers[i], tickets[i]);
                count++;
            }
        }
        if(count != 0){
            return 1;
        }
        std::cout << "Don't have passenger information" << std::endl;
        return 0;
    };
    
    return 0;
}

