 #include "handleFile.h"
 
void handleFile::printError(std::string msg){
  std::cerr << msg << std::endl;
  exit(0);
}



long handleFile::getFileSize(std::string filename){
  std::ifstream infile(filename, std::ifstream::ate| std::ifstream::binary);
  std::cout << infile.tellg();
  return infile.tellg();
}


 

std::string handleFile::handleFileName(std::string token2 ,int clientSocket){
  std::string fileName;
  std::istringstream iss(token2);
  iss>>fileName;
  if(!std::filesystem::exists("recv/"+fileName)){
    Object.insert({"recv/"+fileName,clientSocket});
    return fileName;
  }
  return "Error";
}

std::string handleFile::handleFileName(std::string token2){
  std::string fileName;
  std::istringstream iss(token2);
  iss>>fileName;
  if(!std::filesystem::exists("recv/"+fileName)){
    return "Error";
  }
  return "recv/"+fileName;
}

void handleFile::sendFile(int clientSocket, std::string filePath , long realSize){
  char buffer[BUFSIZE]; 
  ssize_t readFileReturn;
  int filefd = open(&filePath[0], O_RDONLY);
  if (filefd == -1) {
    perror("open");
    exit(EXIT_FAILURE);
  }
  long fileSize {0};
  std::cout << "Filesize: " << realSize <<std::endl;
  while (1) {
    readFileReturn = read(filefd, buffer, BUFSIZE );
    if (readFileReturn == 0)
      break;
    if (readFileReturn == -1) {
      this->printError("Read error");
    }
    if (send(clientSocket, buffer, readFileReturn, 0) == -1) {
      this->printError("Write error");
    }
    fileSize += readFileReturn;
    std::cout << "\rsend: " << fileSize;
  }
  std::cout << std::endl;
  close(filefd);
}

void handleFile::recvFile(std::string filePath, long fileSize, int clientSocket){
  std::string buffer[BUFSIZE];
  filefd = open(&filePath[0],O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  if (filefd == -1) {
    perror("open");
    exit(EXIT_FAILURE);
  }
  long readSize {0};
  std::cout << "Filesize: " << fileSize <<std::endl;
  while(readSize <fileSize){
    readFileReturn = recv(clientSocket, buffer, BUFSIZE, 0);       
    if (readFileReturn == -1) {
      perror("read");
      exit(EXIT_FAILURE);
    }
    readSize += readFileReturn;
    std::cout << "\rrecv: " << readSize;
    if (write(filefd, buffer, readFileReturn) == -1) {
      perror("write");
      exit(EXIT_FAILURE);
    }
  }
  bzero(&buffer[0], BUFSIZE-1);
  close(filefd);
  std::cout << std::endl;
}

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