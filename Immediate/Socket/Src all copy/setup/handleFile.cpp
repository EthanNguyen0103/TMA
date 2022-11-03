#include "handleFile.h"

int handleFile::deleteFile(std::string token2, int clientSocket){
  if(Object.count("recv/"+token2)){
    if(Object["recv/"+token2]==clientSocket){
      try {
        if (std::filesystem::remove("recv/"+token2)){
          Object.erase("recv/"+token2);
          return 1;
        }
        else{
          return 0;
        }
      }
      catch(const std::filesystem::filesystem_error& err) {
        std::cout << "filesystem error: " << err.what() << '\n';
        return -1;
      }
    }
  }
  return -2;
}

void handleFile::putFileToServer(int uSock, std::string buffer, std::string token2){
    int n;
    buffer.resize(BUFSIZE);
    bzero(&buffer[0], BUFSIZE-1);
    buffer = this->sendFile(token2);
    n = send(uSock,  &buffer[0], BUFSIZE-1,0);
    if(n<0){
      std::cerr<<"Error on writing" << std::endl;
    }
}

std::string handleFile::sendFile(std::string token2){
  // Read from the text file
    std::istringstream iss(token2);
    std::string fileName;
    iss>>fileName;
    std::ifstream myFile;
    std::string line;
    std::stringstream ss;
    int currentLine = 0;
    
    myFile.open(fileName, std::ios::in);
    if(!myFile.is_open()){
      std::cout << "Can't open file" << std::endl;
      return "Error: file not found";
    }      
    while (!myFile.eof()){
      getline(myFile, line);
      ss << line << '\n';
      currentLine++;
    }
    myFile.close();
    std::string strOut = ss.str();
    return strOut;
}

int handleFile::recvFile(std::string &buffer, std::string token2,int clientSocket){
  //file
  buffer.erase(std::find(buffer.begin(), buffer.end(), '\0'), buffer.end());
  std::ofstream myfile;
  if(!std::filesystem::exists("recv/"+token2)){
    myfile.open("recv/"+token2, std::ios::out);
    myfile << buffer; 
    myfile.close();
    Object.insert({"recv/"+token2,clientSocket});
    return 0;
  }
  return -1;
}

int handleFile::recvFileClient(std::string &buffer, std::string token2){
  //file
  buffer.erase(std::find(buffer.begin(), buffer.end(), '\0'), buffer.end());
  std::ofstream myfile;
  if(!std::filesystem::exists("clientrecv/"+token2)){
    myfile.open("clientrecv/"+token2, std::ios::out);
    myfile << buffer; 
    myfile.close();
    return 0;
  }
  return -1;
}