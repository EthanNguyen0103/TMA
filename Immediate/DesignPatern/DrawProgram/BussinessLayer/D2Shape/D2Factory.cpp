#include "D2Factory.h"


ShapeObject* D2Factory::getShape(Shape type) {
  ShapeObject *shape = nullptr;
  switch (type)
  {
  case Rectangle:
    // shape = D2Rectangle::GetInstance();
    shape = new D2Rectangle();
    break;
  case Circle:
    // shape = D2Circle::GetInstance();
    shape = new D2Circle();
    break;
  default:
      break;
  }
  return shape;
}

D2Factory* D2Factory::instance = nullptr;

D2Factory::D2Factory() {};
D2Factory *D2Factory::GetInstance(){
    if(instance ==nullptr){
        instance = new D2Factory();
    }
    return instance;
}
