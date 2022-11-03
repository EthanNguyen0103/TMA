#include "AccessMode.h"
#include <iostream>

void AccessMode::getAccess(){
    std::cout << "Access Modify: " << std::endl;
    newUserPL.printAccessMode();
    std::cin >> ModeUser;
    switch (ModeUser)
    {
        case Customer:{
                newUserDL.openFile(passengers,tickets, usedChair);
                std::cout << "Welcome to Daewoo Reservation System "; 
                std::cout << "\nEnter your information:" << std::endl; 
                while (1)
                {
                    newUserPL.printCustomerMenu();
                    newUserBL.setUserChoice();
                    switch (newUserBL.getUserChoice())
                    {
                    case requestReserveTicket:
                        newUserBL.reserveTicket(usedChair,passengers,tickets);
                        break;
                    case requestSearchByName:
                        newUserBL.searchByName(passengers,tickets);
                        break;
                    case requestSearchByDate:
                        newUserBL.searchByDate(passengers, tickets);
                        break;
                    case requesteixtFromApplication:
                        newUserDL.saveData(passengers, tickets);
                        exit(0);            
                    default:
                        std::cout << "You made an illegal choice." << std::endl;
                        break;
                    }
                }
                break;
                }
        case Admin:{
                newUserDL.openFile(passengers,tickets, usedChair);
                std::cout << "Welcome to Daewoo Reservation System "; 
                std::cout << "\nEnter your information:" << std::endl; 
                while (1)
                {
                    newUserPL.printMenu();
                    newUserBL.setUserChoice();
                    switch (newUserBL.getUserChoice())
                    {
                    case requestReserveTicket:
                        newUserBL.reserveTicket(usedChair,passengers,tickets);
                        break;
                    case requestModifyReservation:
                        newUserBL.modifyReservation(passengers, tickets);
                        break;
                    case requestCancelReservation:
                        newUserBL.cancelReservation(passengers, usedChair, tickets);
                        break;
                    case requestSearchByName:
                        newUserBL.searchByName(passengers, tickets);
                        break;
                    case requestSearchByDate:
                        newUserBL.searchByDate(passengers, tickets);
                        break;
                    case requesteixtFromApplication:
                        newUserDL.saveData(passengers, tickets);
                        exit(0);            
                    default:
                        std::cout << "You made an illegal choice." << std::endl;
                        break;
                    }
                }
                break;
                }
        case exitChoice:{
            exit(0);
        }
        default:{
            std::cout << "You made an illegal choice." << std::endl;
            break;
        }
        }
  }

