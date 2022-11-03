#pragma once

enum Shape {
    Rectangle = 1,
    Circle
};
class ShapeObject {
public:    
    virtual void addObject()=0;
    virtual void showInfo()=0;
    virtual ShapeObject &getInfo()=0;
};
