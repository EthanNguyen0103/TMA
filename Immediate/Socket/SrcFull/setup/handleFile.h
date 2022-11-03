#pragma once
#include "../header/header.h"

class handleFile{
public:
  //get size of file
  long getFileSize(std::string filename);
  
  //handle File with name client 
  std::string handleFileName(std::string token2 ,int clientSocket);
  std::string handleFileName(std::string token2);
  
  void sendFile(int clientSocket, std::string filePath , long realSize);

  void recvFile(std::string filePath, long fileSize, int clientSocket);
  
  int deleteFile(std::string token2, int clientSocket);
  private:
    //printError
    void printError(std::string msg);
    int filefd;
    int readFileReturn;
    std::map <std::string, int> Object;
};
