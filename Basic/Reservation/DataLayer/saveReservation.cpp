#include "saveReservation.h"

void saveReservation::processFile(std::ifstream &myFile, std::vector <passenger> &passengers,std::vector <ticket> &tickets, std::vector <int> &usedChair){
    std::string line, word;
    std::vector<std::string> words;
    std::istringstream iss;
    int currentLine = 0;
    while (!myFile.eof()){
        getline(myFile, line);
        if(myFile.good()){
            iss.clear();
            iss.str(line);
            while(iss>>word){
                words.push_back(word);
            }
            currentLine++;
        }
    }
    int count = 0;
    int num;
    for(int i =0; i <currentLine;i++){
        //get each Object
        newPass.setName(words[count]);
        newTicket.setDepartureCity(words[count+1]);
        newTicket.setDestinationCity(words[count+2]);
        newTicket.setDay(std::stoi(words[count+3]), std::stoi(words[count+4]), std::stoi(words[count+5]));
        newTicket.setTicket(std::stoi(words[count+6]));
        newPass.setSeatNum(std::stoi(words[count+7]));
        
        //push to vector
        usedChair.push_back(newPass.getSeatNum());
        passengers.push_back(newPass);
        tickets.push_back(newTicket);
        count=count+8;
    }
        myFile.close();

}



int saveReservation::openFile(std::vector <passenger> &passengers, std::vector <ticket> &tickets, std::vector <int> &usedChair){
    std::ifstream myfile;
    myfile.open("Daewoorecord.txt", std::ios::in);
    if(!myfile){
        std::cout << "Can't open file" << std::endl;
        return 1;
    }            
    this->processFile(myfile,passengers,tickets, usedChair);
    return 0;
}

void saveReservation::saveData(std::vector <passenger> &passengers,  std::vector <ticket> &tickets){
    if(!passengers.empty() && !tickets.empty()){
    std::ofstream myfile;
    myfile.open("Daewoorecord.txt", std::ios::out);
    for(int i =0; i<passengers.size();i++){
        myfile << passengers[i].getName() << ' ';
        myfile << tickets[i].getDeparture() << ' ';
        myfile << tickets[i].getDestination() << ' ';                
        myfile << tickets[i].getDate() << ' ';
        myfile << tickets[i].getMonth() << ' ';  
        myfile << tickets[i].getYear() << ' ';
        myfile << tickets[i].getTickets() << ' ';
        myfile << passengers[i].getSeatNum();
        myfile << '\n';
    }  
    myfile.close();
    }
    std::cout << "Thanks you for using our service" << std::endl;
}