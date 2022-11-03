#include "D2Circle.h"

D2Circle& D2Circle::getInfo(){
    return *this;
}

void D2Circle::showInfo(){
    std::cout << "2DCircle: ";
    std::cout << '(' << X << ", " << Y <<"), ";
    std::cout << "R: " << Radius << std::endl;
}

void D2Circle::addObject(){
    std::cout << "Enter x coordinate: ";
    std::cin >> this->X;
    std::cout << "Enter y coordinate: ";
    std::cin >> this->Y;
    std::cout << "Enter Radius: ";
    std::cin >> this->Radius;
}

// D2Circle* D2Circle::instance = nullptr;

// D2Circle::D2Circle() {}
// D2Circle *D2Circle::GetInstance(){
//     if(instance ==nullptr){
//         instance = new D2Circle();
//     }
//     return instance;
// }

