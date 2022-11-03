#pragma once
#include "../header/header.h"


class handleFile{
public:
  int deleteFile(std::string token2, int clientSocket);
  void putFileToServer(int uSock, std::string buffer, std::string token2);
  std::string sendFile(std::string token2);
  int recvFileClient(std::string &buffer, std::string token2);
  int recvFile(std::string &buffer, std::string token2,int clientSocket);
  private:
    std::map <std::string, int> Object;
};
