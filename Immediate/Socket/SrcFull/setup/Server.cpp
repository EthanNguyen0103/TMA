#include "Server.h"
#include <fcntl.h>
#include <fstream>

void Server::startingServer(){
  int serverSocket = this->createSocket(SERVER_PORT, SERVER_BACKLOG);
  fd_set currentSockets, readySockets;
  //init my current set
  FD_ZERO(&currentSockets);
  FD_SET(serverSocket, &currentSockets);
  while(RUNNING_FLAG){
    readySockets = currentSockets;
    if(select(FD_SETSIZE, &readySockets, NULL, NULL, NULL) < 0){
      this->printError("Select error");
    }

    for(int i = 0; i < FD_SETSIZE; i++){
      if(FD_ISSET(i, &readySockets)){
        if(i==serverSocket){
          //this is new connection
          int clientSocket = this->acceptNewConnect(serverSocket);
          FD_SET(clientSocket, &currentSockets);
          std::string welcomeMsg = "Enter your command!\n";
          send(clientSocket, welcomeMsg.c_str(), welcomeMsg.size() + 1, 0);
        }
        else{
          //do whatever
          this->sendMsg(i , currentSockets);
        }
      }
    }
  }
  // //send msg to client server shutdown
  // std::string msg = "Server is shutting down. Goodbye";
  // for(int i =0; i <FD_SETSIZE;i++){
  //   if(FD_ISSET(i, &readySockets)){
  //     // Send the goodbye message
  //     send(i, msg.c_str(), msg.size() + 1, 0);
  //     // Remove it from the master file list and close the socket
  //     FD_CLR(i, &currentSockets);
  //     close(i);
  //   }
  // }
  FD_CLR(serverSocket, &currentSockets);
  close(serverSocket);
}

void Server::printError(std::string msg){
  std::cerr << msg << std::endl;
  exit(0);
}

int Server::createSocket(short port, int backLog){
  int serverSocket, clientSocket, addrSize;
  struct sockaddr_in servAddr;
  //create Socket
  if((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    this->printError("Error openning socket");
  }

  servAddr.sin_family = AF_INET;
  servAddr.sin_addr.s_addr = INADDR_ANY;
  servAddr.sin_port = htons(port);

  if(bind(serverSocket, (struct sockaddr*) &servAddr, sizeof(servAddr)) < 0){
    this->printError("Binding Failed");
  }

  if(listen(serverSocket, backLog) < 0){
    this->printError("Listenning Error");
  }
  return serverSocket;
}

int Server::acceptNewConnect(int serverSocket){
  int addrSize = sizeof(sockaddr_in);
  int clientSocket;
  sockaddr_in clientAddr;
  if((clientSocket = accept(serverSocket, (struct sockaddr*) &clientAddr,(socklen_t*) &addrSize)) < 0){
    this->printError("Accept Failed");
  }
  std::cout << "Got connection from " << inet_ntoa(clientAddr.sin_addr) << ", port: " <<ntohs(clientAddr.sin_port) << std::endl;
  return clientSocket;
}

void Server::fileCommand(std::string command, int clientSocket){
  std::stringstream ss;
  ss << command;
  std::string strOut = ss.str();
  send(clientSocket, strOut.c_str(), strOut.size() + 1, 0);
}

void Server::outComand(int clientSocket){
  std::stringstream ss;
  ss << "\\Bye" << '\n';
  std::string strOut = ss.str();
  send(clientSocket, strOut.c_str(), strOut.size() + 1, 0);
}

void Server::command(std::string command,int m, int clientSocket){
  std::stringstream ss;
  ss << "SOCKET #" << clientSocket << ": "<< command << m << '\n';
  std::string strOut = ss.str();
  send(clientSocket, strOut.c_str(), strOut.size() + 1, 0);
}

void Server::command(std::string command, int clientSocket){
  std::stringstream ss;
  ss << "SOCKET #" << clientSocket << ": "<< command << '\n';
  std::string strOut = ss.str();
  send(clientSocket, strOut.c_str(), strOut.size() + 1, 0);
}

void Server::recvMsg(int &clientSocket, fd_set &currentSockets){
  buffer.resize(BUFSIZE);
  bzero(&buffer[0], BUFSIZE);
  if((bytesRead = recv(clientSocket, &buffer[0], BUFSIZE,0))<0){
    FD_CLR(clientSocket,&currentSockets);
    this->printError("Error on reading");
  }
}



int Server::sendMsg(int &clientSocket, fd_set &currentSockets){
  this->recvMsg(clientSocket, currentSockets);
  std::cout << "Client "<<clientSocket << " reply: " << buffer << std::endl;

  // detect \\ command
  if(buffer[0] == '\\'){
    std::istringstream iss(buffer);
    std::string token1, token2, token3;
    std::getline(iss, token1, ' ');
    std::getline(iss, token2, ' ');
    std::getline(iss, token3, ' ');
    
    if(token1 == "\\QUIT"){
      // RUNNING_FLAG = 0;
      Object.delALLMap(clientSocket);
      this->outComand(clientSocket);
      FD_CLR(clientSocket, &currentSockets);
      return 0;
    }
    if(token1 == "\\QUITSERVER"){
      this->outComand(clientSocket);
      RUNNING_FLAG = 0;
      return 0;
    }
    if(token1 == "\\GET"){
      int m = Object.getMap(stoi(token2));
      if(m !=-1){
        this->command("GET: ", m, clientSocket);
        return 0;
      }
      this->command("Do not have infomation of getting object", clientSocket);
      return 0;
    }
    if(token1 == "\\PUT"){
      if(Object.putMap(stoi(token2), stoi(token3), clientSocket) !=-1){
        this->command("PUT OK", clientSocket);
        return 0;
      }
      else
        this->command("Key was used", clientSocket);
        return 0;
    }
    if(token1 == "\\DEL"){
      int n = Object.delOneMap(stoi(token2), clientSocket);
      if(n == -1){
        this->command("You do not have permission to DEL", clientSocket);
        return 0;
      }
      if(n == -2){
        this->command("Dont have this Key", clientSocket);
        return 0;
      }
      if(n == 0){
        this->command("DEL OK", clientSocket);
        return 0;
      }
    }
    if(token1 == "\\GETFILE"){
      //send command if file not found
      std::string checkFile;
      checkFile = myFile.handleFileName(token2);
      if(checkFile == "Error"){
        this->command("File doesn't exis", clientSocket);
        return 0;
      }
      //send command
      long fileSize = myFile.getFileSize(checkFile);
      this->fileCommand("\\GETFILEPROCESSING "+ token2 +" "+ std::to_string(fileSize), clientSocket);
      //get accept command
      this->recvMsg(clientSocket, currentSockets);
      //send file
      myFile.sendFile(clientSocket, checkFile, fileSize);
      return 0;
    }
    if(token1 == "\\PUTFILE"){
      //send command if exis file
      std::string checkFile;
      checkFile = myFile.handleFileName(token2, clientSocket);
      if(checkFile == "Error"){
        this->command("File exis", clientSocket);
        return 0;
      }
      //send command
      long fileSize = myFile.getFileSize("clientsend/"+checkFile);
      this->fileCommand("\\PUTFILEPROCESSING "+token2+" "+std::to_string(fileSize), clientSocket);
      //get file da
      myFile.recvFile("recv/"+checkFile, fileSize, clientSocket);
      this->command("PUT OK", clientSocket);
      return 0;
    }
    if(token1 == "\\DELFILE"){
      int n;
      n = myFile.deleteFile(token2, clientSocket);
      if(n == 1){
        this->command("file "+token2+ " deleted", clientSocket);
      }
      if(n == 0){
        this->command("file "+token2+ " notfound", clientSocket);
      }
      if(n == -1){
        this->command("filesystem error", clientSocket);
      }
      if(n == -2){
        this->command("You do not have permission to del or file not found", clientSocket);
      }
      return 0;
    }
  }
  this->command("UNKNOWN", clientSocket);
  return 0;
}

