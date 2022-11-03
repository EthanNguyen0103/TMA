#include "../header/header.h"
#include "handleFile.h"

class Client{
  public:
    //send and recv msg to server
    void startingClient();

  private:
    void printError(std::string msg);
    //setup client
    void setupOneClient();
    int uSock, uPortNum, n;
    struct sockaddr_in servAddr;
    struct hostent *server;
    std::string buffer, getServer;
    handleFile myFile;
};
