#include "../header/settup.h"
#include "../header/setmap.h"

class setupServer{
  public:
    void printError(std::string msg);
    //run server with multi client
    void accessServer();
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

  private:
    bool RUNNING_FLAG = 1;
    setMap Object;
};

