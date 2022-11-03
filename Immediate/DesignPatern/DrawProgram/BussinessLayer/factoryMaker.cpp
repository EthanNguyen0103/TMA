#include "factoryMaker.h"

#include <iostream>

AbstractFactory* FactoryMaker::getFactory(FactoryType type) {
  AbstractFactory *factory = nullptr;
  switch (type)
  {
  case D3:
    // factory = new D3Factory();
    factory = D3Factory::GetInstance();
    break;
  case D2:
    // factory = new D2Factory();
    factory = D2Factory::GetInstance();
    break;
  default:
    std::cout << "Undefine" << std::endl;
      break;
  }
  return factory;
}