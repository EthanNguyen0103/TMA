#pragma once
#include "../shapeObject.h"
#include "../abstractfactory.h"
#include "D2Factory.h"
#include "D2Rectangle.h"
#include "D2Circle.h"

class D2Factory: public AbstractFactory {
    public:
      ShapeObject* getShape(Shape type);
      D2Factory(D2Factory &other) = delete;
      void operator=(const D2Factory &) = delete;
      static D2Factory *GetInstance();
    protected:
      D2Factory();
    private:
      static D2Factory* instance;
};

