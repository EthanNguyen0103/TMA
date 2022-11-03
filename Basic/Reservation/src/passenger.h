#pragma once

#include <iostream>

class passenger {
    private:
        int seatNum;
        std::string nameOfPassenger;
    public:

        //set and get name passenger
        void setName();
        void setName(std::string nameOfPassenger);
        std::string getName();

        //set and get name,seat of Passenger
        void setNameAndSeat();
        void setNameAndTiket();
        int getSeatNum();
        void setSeatNum(int seatNum);
        void setSeatNum();


};
