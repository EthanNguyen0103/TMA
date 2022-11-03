#include "../header/settup.h"


class setupClient{
  public:
    void printError(std::string msg);
    //send and recv msg to server
    void sendMsgStream();
    //setup client
    void setupOneClient();
  private:
    int uSock, uPortNum, n;
    struct sockaddr_in servAddr;
    struct hostent *server;
    std::string buffer, getServer;
};
