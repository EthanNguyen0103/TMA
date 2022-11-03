#pragma once
#include <iostream>
#include "../PresentationLayer/showMenu.h"
#include "getFactory.h"
#include "saveObject.h"


class drawProgram {
  public:
    void AccessMenu();
  private:
    saveObject saveObjectA;
    getFactory newObj;
    std::vector <int> commands; 
};