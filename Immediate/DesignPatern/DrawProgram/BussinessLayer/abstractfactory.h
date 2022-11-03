#pragma once

#include "shapeObject.h"

class AbstractFactory {
public:
    //get Rec or Circle
    virtual ShapeObject* getShape(Shape type)=0;
    
};
