#ifndef _TICKET_
#define _TICKET_

#include <iostream>
#include <string>

struct dateOfTime{
    int date,month,year;
    bool operator==(const dateOfTime &dot){
        if(this->date == dot.date && this->month == dot.month && this->year == dot.year){
            return true;
        }
        else
            return false;
    }
};

class ticket{
    public:
        //get and set departure
        std::string getDeparture();
        void setDepartureCity(std::string departureCity);
        void setDepartureCity();

        //get and set destination
        std::string getDestination();
        void setDestinationCity(std::string destinationCity);
        void setDestinationCity();

        //get and get ticket number
        int getTickets();
        void setTicket(int numberOfTickets);
        void setTicket();
        
        //get and set seat number
        int getSeatNum();
        void setSeatNum(int seatNum);
        void setSeatNum();

        //get and set day travel
        
        dateOfTime getDay();
        int getDate();
        int getMonth();
        int getYear();
        void setDay();       
        void setDay(int date, int month, int year);

        
    private:
        std::string departureCity;
        std::string destinationCity;
        dateOfTime timeOfTravel;
        int numberOfTickets;
};


#endif