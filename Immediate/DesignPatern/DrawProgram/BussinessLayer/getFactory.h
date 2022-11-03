#pragma once
#include "D3Shape/D3Factory.h"
#include "D2Shape/D2Factory.h"
#include "factoryMaker.h"
#include "shapeObject.h"
#include <iostream>
#include <vector>

class getFactory{
  public:
    getFactory(){
      typeFactory = D3;
      typeShape = Rectangle;
    }
    friend std::istream& operator>>(std::istream& in, getFactory& g);
    ShapeObject* getShapeObj();
    
  private:
    FactoryType typeFactory;
    Shape typeShape;
    ShapeObject* Object;
};










