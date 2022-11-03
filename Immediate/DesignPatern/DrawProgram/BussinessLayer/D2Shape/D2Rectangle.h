#pragma once
#include "../shapeObject.h"
#include <iostream>
class D2Rectangle: public ShapeObject {
    public:
        void showInfo(); 
        void addObject();
        D2Rectangle& getInfo();
    //     D2Rectangle(D2Rectangle &other) = delete;
    //     void operator=(const D2Rectangle &) = delete;
    //     static D2Rectangle *GetInstance();
    // protected:
    //     D2Rectangle();
    private:
        int X,Y, Width, Height; 
        static D2Rectangle* instance;
};