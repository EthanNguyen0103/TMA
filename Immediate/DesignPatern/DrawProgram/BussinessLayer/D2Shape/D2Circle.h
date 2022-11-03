#pragma once
#include <iostream>
#include "../abstractfactory.h"
#include <vector>

class D2Circle: public ShapeObject {
    public:
        void showInfo(); 
        void addObject();
        D2Circle & getInfo();
    //     D2Circle(D2Circle &other) = delete;
    //     void operator=(const D2Circle &) = delete;
    //     static D2Circle *GetInstance();
    // protected:
    //     D2Circle();
    private:
        int X,Y, Radius;
        static D2Circle* instance;
};