#pragma once
#include "../shapeObject.h"
#include "../abstractfactory.h"
#include "D3Factory.h"
#include "D3Rectangle.h"
#include "D3Circle.h"

class D3Factory: public AbstractFactory {
  public:
    ShapeObject* getShape(Shape type);
    D3Factory(D3Factory &other) = delete;
    void operator=(const D3Factory &) = delete;
    static D3Factory *GetInstance();
  protected:
    D3Factory();
  private:
    static D3Factory* instance;
};

