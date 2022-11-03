#pragma once

#include <iostream>
#include "../src/passenger.h"
#include "../src/ticket.h"

class showReservation{
    public:
        void printAccessMode();
        void printMenu();
        void printCustomerMenu();
        static void showInformation(class passenger const newPassenger, class ticket const newTicket);
    
};

