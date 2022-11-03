#pragma once
#include "../shapeObject.h"
#include <iostream>
class D3Rectangle: public ShapeObject {
    public:
        void showInfo(); 
        void addObject();
        D3Rectangle & getInfo();
    //     D3Rectangle(D3Rectangle &other) = delete;
    //     void operator=(const D3Rectangle &) = delete;
    //     static D3Rectangle *GetInstance();
    // protected:
    //     D3Rectangle();
    private:
        int X,Y, Z, Width, Height; 
        static D3Rectangle* instance;
};