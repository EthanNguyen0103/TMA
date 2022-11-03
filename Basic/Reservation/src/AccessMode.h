#pragma once


#include "../PresentationLayer/showReservation.h"
#include "../BussinessLayer/setupReservation.h"
#include "../DataLayer/saveReservation.h"

#include <iostream>


enum ModeUser{Admin = '2', 
            Customer = '1',
            exitChoice = '3'
};
enum Choices{
    requestReserveTicket = '1',
    requestModifyReservation = '2',
    requestCancelReservation = '3',
    requestSearchByName = '4',
    requestSearchByDate = '5',
    requesteixtFromApplication = '6'
};

class AccessMode{
    public:
        void getAccess();

    private:
        char ModeUser;
        showReservation newUserPL;
        setupReservation newUserBL;
        saveReservation newUserDL;
        std::vector <passenger> passengers;
        std::vector <ticket> tickets;
        std::vector<int> usedChair;
};



