#pragma once
#include <map>
#include <iostream>

class Map{
  public:
    //get from map
    int getMap(int key);
    //put to map
    int putMap(int key, int value, int clientSocket);
    //del elemtent in Map
    int delOneMap(int key, int clientSocket);
    //del element when exis the map
    void delALLMap(int clientSocket);
  private:
    std::map <int, std::pair<int,int>> Object;
};