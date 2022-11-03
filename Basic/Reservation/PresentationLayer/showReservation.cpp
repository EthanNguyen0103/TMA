#include "showReservation.h"


void showReservation::printMenu(){
  std::cout << "\nEnter your selection:";
  std::cout << "\n1. Reserve your tiket";
  std::cout << "\n2. Modify reservation";
  std::cout << "\n3. Cancel reservation";
  std::cout << "\n4. Search reservation information by passenger name ";
  std::cout << "\n5. Search reservation information by date of travel";
  std::cout << "\n6. Exit" << std::endl;
}

void showReservation::printCustomerMenu(){
  std::cout << "\nEnter your selection:";
  std::cout << "\n1. Reserve your tiket";
  std::cout << "\n4. Search reservation information by passenger name ";
  std::cout << "\n5. Search reservation information by date of travel";
  std::cout << "\n6. Exit" << std::endl;
}

void showReservation::printAccessMode(){
  std::cout << "\nEnter your selection:";
  std::cout << "\n1. Customer";
  std::cout << "\n2. Admin";
  std::cout << "\n3. Exit" << std::endl;
}

void showReservation::showInformation(class  passenger newPassenger, class  ticket newTicket){
    std::cout <<"\nInfomation:" << std::endl;
    std::cout << "Name: " << newPassenger.getName() <<" ||" << "Departure: " << newTicket.getDeparture() << " || " << "Destination: " 
    << newTicket.getDestination() << " || " <<"Day: " << newTicket.getDate() <<"-" <<newTicket.getMonth() <<"-" << newTicket.getYear() <<" || " << "Number of ticket: " << newTicket.getTickets()
    <<" || "<<"Seat Number: " << newPassenger.getSeatNum();  
    std::cout << std::endl;
}