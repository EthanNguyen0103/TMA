#include "D3Factory.h"

ShapeObject* D3Factory::getShape(Shape type) {
  ShapeObject *shape = nullptr;
  switch (type)
  {
  case Rectangle:
    // shape = D3Rectangle::GetInstance();
    shape = new D3Rectangle();
    break;
  
  case Circle:
    // shape = D3Circle::GetInstance();
    shape = new D3Circle();
    break;
  default:
      break;
  }
  return shape;
}

D3Factory* D3Factory::instance = nullptr;

D3Factory::D3Factory() {};
D3Factory *D3Factory::GetInstance(){
    if(instance ==nullptr){
        instance = new D3Factory();
    }
    return instance;
}
