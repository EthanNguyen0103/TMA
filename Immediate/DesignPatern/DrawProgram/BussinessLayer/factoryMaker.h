#pragma once

#include "shapeObject.h"
#include "abstractfactory.h"
#include "D3Shape/D3Factory.h"
#include "D2Shape/D2Factory.h"

enum FactoryType {
    D2 = 1,
    D3
};
class FactoryMaker {
public:
    AbstractFactory* getFactory(FactoryType type);
    
};
