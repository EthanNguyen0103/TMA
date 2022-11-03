#pragma once

#include "../src/passenger.h"
#include "../src/ticket.h"
#include <fstream>
#include <sstream>
#include <vector>

class saveReservation{
    public:
        int openFile();
        void processFile(std::ifstream &);
        void processFile(std::ifstream &myFile, std::vector <passenger> &passengers, std::vector <ticket> &tickets, std::vector <int> &usedChair);
        int openFile(std::vector <passenger> &passengers, std::vector <ticket> &tickets, std::vector <int> &usedChair);
        void saveData(std::vector <passenger> &passengers, std::vector <ticket> &tickets);
    private:
        passenger newPass;
        ticket newTicket;
};

