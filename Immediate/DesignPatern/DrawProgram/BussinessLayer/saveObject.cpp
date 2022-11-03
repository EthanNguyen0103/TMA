#include "saveObject.h"


//remove Object in exactly index 
int saveObject::removeObj(int index){
  if(Objects.empty() || index >= Objects.size()){
  std::cout << "Index out of range or empty";
  return 0;
  }
  //Push undoVar
  UndoVar.push(Objects[index]);
  UndoVarIndex.push(index);
  Objects.erase(Objects.begin() + index);
  return 1;
}
//add new Object to the Objects
void saveObject::addNewObj(ShapeObject *Object){
  LastObject = Object;
  LastIndex = 0;
  Object->addObject();
  Objects.push_back(Object);
  UndoVar.push(LastObject);
  UndoVarIndex.push(LastIndex);
    
}
// show all Object at the present
int saveObject::showAllObj(){
  if(Objects.empty()){
  std::cout << "Don't have anything to show" << std::endl;
  return 0;
  }
  std::cout << "\n";
  for(int i =0; i<Objects.size();i++){
  Objects[i]->showInfo();
  }
  return 1;
}
// change Object base on index
int saveObject::changeObject(int index, ShapeObject *Object){
  if(Objects.empty() || index >= Objects.size()){
  std::cout << "Index out of range or empty";
  return 0;
  }
  LastObject = Object;
  LastIndex = index;
  //Push undoVar
  UndoVar.push(Objects[index]);
  UndoVarIndex.push(index);
  Objects.erase(Objects.begin() + index);
  std::cout << "You are changing object in location: " << index << std::endl; 
  Object->addObject();
  Objects.insert(Objects.begin()+index, Object);
  // RedoVar.push(Objects[index]);
  // RedoVarIndex.push(index);
    return 1;
}
void saveObject::REDOVar(std::vector <int> commands){
  if (!RedoVar.empty())
  {
  //get Eltement
  ShapeObject* Object = RedoVar.top();
  int index = RedoVarIndex.top();
  //start
  if (commands.back() == AddObject){
      Objects.insert(Objects.begin()+index, Object);
  }
  else if(commands.back()==DeleteObject){
      Objects.erase(Objects.begin()+index);
  }
  else if(commands.back() == ChangeObject){
      Objects.erase(Objects.begin()+index);
      Objects.insert(Objects.begin()+index, LastObject);
  }
  else if(commands.back()==Undo){
      if(commands[commands.size()-2]==ChangeObject){
      Objects.erase(Objects.begin()+index);
      }
      Objects.insert(Objects.begin()+index, Object);
  }
  RedoVar.pop();
  RedoVarIndex.pop();
  UndoVar.push(LastObject);
  UndoVarIndex.push(index);
  LastObject = Object;
  LastIndex = index;
  }
}
void saveObject::UNDOVar(std::vector <int> commands){
  if(!UndoVar.empty()){
  //get Object and its index  
  ShapeObject* Object = UndoVar.top();
  int index = UndoVarIndex.top();
  
  // store back
  if(commands.back()==AddObject){
      Objects.pop_back();  
  }
  else if(commands.back()==DeleteObject){
      Objects.insert(Objects.begin()+index, Object);
  }
  else if(commands.back()==ChangeObject){
      Objects.erase(Objects.begin()+index);
      Objects.insert(Objects.begin()+index, Object);
  }
  else if(commands.back()==Redo){
      Objects.erase(Objects.begin()+index);
  }

  UndoVar.pop();
  UndoVarIndex.pop();
  RedoVar.push(LastObject);
  RedoVarIndex.push(index);
  LastObject = Object;
  LastIndex = index;
  }
}