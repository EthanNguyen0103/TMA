#pragma once

#include <iostream>
#include <algorithm>
#include "../src/passenger.h"
#include "../src/ticket.h"
#include "../PresentationLayer/showReservation.h"


class setupReservation{
    private:
        ticket newTicket;
        passenger newPassenger;
        char userChoice;

    public:
        //set and set Information
        void setInformmation();
        void getInformmation();
        void setPassengerandTicket(std::vector<passenger> &passengers, std::vector<ticket> &tickets);
        std::vector <passenger> getPassenger();

        void setUsedChair(int seatNum, std::vector <int> &usedChair);
        std::vector <int> getUsedChair();
        void setUserChoice();
        int getUserChoice();
        int reserveTicket(std::vector <int> &usedChair, std::vector <passenger> &passengers, std::vector<ticket> &tickets);
        int modifyReservation(std::vector <passenger> &passengers, std::vector<ticket> &tickets);
        int cancelReservation(std::vector <passenger> &passengers, std::vector <int> &usedChair, std::vector<ticket> &tickets);
        int searchByName(std::vector <passenger> &passengers, std::vector<ticket> &tickets);
        int searchByDate(std::vector <passenger> &passengers, std::vector<ticket> &tickets);


        //file

};


