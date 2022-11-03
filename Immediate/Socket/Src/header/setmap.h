#pragma once
#include <map>
#include <iostream>

class setMap{
  public:
    int getMap(int key){
      if(Object.count(key)){
        std::cout << "GET: "<< Object[key].second << std::endl;
        return Object[key].second; 
      }
      return -1;
    }
    int putMap(int key, int value, int clientSocket){
      if(!Object.count(key)){
        Object.insert({key, {clientSocket, value}});
        return 0;
      }
      return -1;
    }
    int delOneMap(int key, int clientSocket){
      if(Object.count(key)){
        if(Object[key].first == clientSocket){
          Object.erase(key);
          return 0;
        }
        return -1;
      }
      return -2;
    }
    void delALLMap(int clientSocket){
      if(!Object.empty()){
        for(int i =0; i <Object.size(); i++){
          if(Object[i].first == clientSocket){
            Object.erase(i);
          }
        }
      }
    }
  private:
    std::map <int, std::pair<int,int>> Object;
};