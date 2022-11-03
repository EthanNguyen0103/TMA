#pragma once
#include "../shapeObject.h"
#include <iostream>

class D3Circle: public ShapeObject {
    public:
        void showInfo(); 
        void addObject();
        D3Circle & getInfo();
    //     D3Circle(D3Circle &other) = delete;
    //     void operator=(const D3Circle &) = delete;
    //     static D3Circle *GetInstance();
    // protected:
    //     D3Circle();
    private:
        int X,Y, Z, Radius;
        static D3Circle* instance;
};