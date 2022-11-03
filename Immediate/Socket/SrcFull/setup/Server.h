#include "../header/header.h"
#include "Map.h"
#include "handleFile.h"

class Server{
  public:
    //run server with multi client
    void startingServer();


  private:
    void* handle_connection(int clientSocket);
    //print error
    void printError(std::string msg);
    //setup one Server
    int createSocket(short port, int backLog);
    // show new connection 
    int acceptNewConnect(int serverSocket);
    // send msg to client
    int sendMsg(int &clientSocket, fd_set &currentSockets);
    //clien out command 
    void outComand(int clientSocket);
    //get number from client
    void command(std::string command,int m, int clientSocket);
    //get only string from client
    void command(std::string command, int clientSocket);
    //send file Command
    void fileCommand(std::string command, int clientSocket);


    void recvMsg(int &clientSocket, fd_set &currentSockets);
   
    std::string buffer;
    size_t bytesRead;
    bool RUNNING_FLAG = 1;
    Map Object;
    handleFile myFile;
};

