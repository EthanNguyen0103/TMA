#pragma once

#include <iostream>
#include <mutex>
#include <thread>
#include "../BussinessLayer/Producer.h"
#include "../BussinessLayer/Customer.h"
#include "../LinkList/linklist.h"
#include "../LinkList/node.h"
#include <condition_variable>

class DataBase{

  public:
    void producerThread();
    void customerThread();
    void runAcess();
  private:
    Producer A;
    Customer B;
    int uData;
    std::mutex gMutex;
    bool gReady = false;
    Linkedlist list;
    std::condition_variable gCondition;
};


