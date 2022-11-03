#pragma once
#include "shapeObject.h"
#include <iostream>
#include <vector>
#include <stack>

enum userChoice{
  AddObject = 1,
  ShowObject,
  DeleteObject,
  ChangeObject,
  Undo,
  Redo,
  Exit
};


class saveObject{
  public:
  //remove Object in exactly index 
  int removeObj(int index);
  //add new Object to the Objects
  void addNewObj(ShapeObject *Object);
  // show all Object at the present
  int showAllObj();
  // change Object base on index
  int changeObject(int index, ShapeObject *Object);
  void REDOVar(std::vector <int> commands);
  void UNDOVar(std::vector <int> commands);
  private:
    std::vector<ShapeObject*> Objects;
    std::stack<ShapeObject*> UndoVar;
    std::stack<int> UndoVarIndex;
    std::stack<ShapeObject*> RedoVar;
    std::stack<int> RedoVarIndex;
    std::stack<ShapeObject*> reOder;
    ShapeObject* LastObject;
    int LastIndex;
};
