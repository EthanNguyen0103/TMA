#include "setupClient.h"

void setupClient::printError(std::string msg){
  std::cerr << msg << std::endl;
  exit(0);
}

void setupClient::sendMsgStream(){
  this->setupOneClient();
  while(1){
    buffer.resize(BUFSIZE);
    bzero(&buffer[0], BUFSIZE-1);
    
    n = recv(uSock, &buffer[0], BUFSIZE-1,0);
    if(n <0){
      this->printError("Error on reading");
    }
    std::cout << buffer << std::endl;
    if(strncmp("Bye", &buffer[0], 3) == 0){
      break;
    }
    bzero(&buffer[0], BUFSIZE-1);
    fgets(&buffer[0], BUFSIZE-1, stdin);
    n = send(uSock,  &buffer[0], BUFSIZE-1,0);
    if(n<0){
      this->printError("Error on writing");
    }
  
  }
  std::cout << "Client: "<< uPortNum << " Quited" << std::endl;
  close(uSock);
}

void setupClient::setupOneClient(){
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