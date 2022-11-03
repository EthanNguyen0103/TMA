#include "Client.h"

void Client::printError(std::string msg){
  std::cerr << msg << std::endl;
  exit(0);
}

void Client::setupOneClient(){
  if((uSock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    this->printError("Error openning socket");
  }
  if((server = gethostbyname("127.0.0.1")) == nullptr){
    this->printError("Error no such host");
  }
  //setup Socket
  bzero((char*) &servAddr, sizeof(servAddr));
  servAddr.sin_family = AF_INET;
  bcopy((char*) server->h_addr, (char*) &servAddr.sin_addr.s_addr, server->h_length);
  servAddr.sin_port = htons(SERVER_PORT);
  if(connect(uSock, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0){
    this->printError("Connection Failded");
  }
  else{
    std::cout << "Connection success" << std::endl;
  }
}

void Client::recvMsg(){
  buffer.resize(BUFSIZE);
  bzero(&buffer[0], BUFSIZE-1);
  n = recv(uSock, &buffer[0], BUFSIZE-1,0);
  if(n <0){
    this->printError("Error on reading");
  }
}

void Client::sendMsgByUser(){
  bzero(&buffer[0], BUFSIZE-1);
  fgets(&buffer[0], BUFSIZE-1, stdin);
  n = send(uSock,  &buffer[0], BUFSIZE-1,0);
  if(n<0){
    this->printError("Error on writing");
  }
}

void Client::startingClient(){
  this->setupOneClient();
  while(1){
    recvBuffer:
    this->recvMsg();
    std::cout << buffer << std::endl;
    if(buffer[0] =='\\'){
      std::istringstream iss(buffer);
      std::string token1, token2, token3;
      std::getline(iss, token1, ' ');
      std::getline(iss, token2, ' ');
      std::getline(iss, token3, ' ');
      if(token1 == "\\Bye"){
        break;
      }
      if(token1 == "\\GETFILEPROCESSING"){
        //get file info
        long fileSize = stol(token3);
        std::string fileName;
        std::istringstream iss(token2);
        iss>>fileName;
        //send accept command
        std::string strOut = "OK";
        send(uSock, strOut.c_str(), strOut.size() + 1, 0);
        //recv data 
        myFile.recvFile("clientrecv/"+fileName, fileSize, uSock);
      }
      if(token1 == "\\PUTFILEPROCESSING"){
        std::istringstream iss(token2);
        std::string fileName;
        iss>>fileName;
        myFile.sendFile(uSock,"clientsend/"+fileName, stol(token3));
        goto recvBuffer;
      }
    }
    this->sendMsgByUser();
  }
  std::cout << "Client: "<< uPortNum << " Quited" << std::endl;
  close(uSock);
}