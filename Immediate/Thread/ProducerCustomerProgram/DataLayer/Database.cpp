#include "Database.h"

void DataBase::producerThread(){
  std::unique_lock<std::mutex> ul(gMutex);
  //Do work, now we have lock
  A.setData(10);
  uData = A.getProducer();
  list.insertNode(uData);
  //Work done
  gReady = true;
  std::cout << "data: " << uData << "\n"; 
  std::this_thread::sleep_for (std::chrono::seconds(1));
  std::cout << "Product Work done" << std::endl;
  ul.unlock();
  gCondition.notify_one();
}

void DataBase::customerThread(){
  std::unique_lock<std::mutex> ul(gMutex);
  if(!gReady){
      gCondition.wait(ul);
    }
    uData =  A.getProducer();
    list.deleteNode(1);  
    std::cout << "receive data: " << uData << "\n";
    std::this_thread::sleep_for (std::chrono::seconds(1));
    std::cout << "Customer Work done" << std::endl;
    gReady = false;
}



void DataBase::runAcess(){
  std::thread t1(&DataBase::producerThread, this);
  std::thread t2(&DataBase::customerThread, this);
  t1.join();
  t2.join();
}