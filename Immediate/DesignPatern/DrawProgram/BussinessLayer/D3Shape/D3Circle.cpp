#include "D3Circle.h"

D3Circle& D3Circle::getInfo(){
    return *this;
}


void D3Circle::showInfo(){
    std::cout << "3DCircle: ";
    std::cout << '(' << X << ", " << Y << ", " << Z <<") ";
    std::cout << "R: " << Radius << std::endl;
}

void D3Circle::addObject(){
    std::cout << "Enter x coordinate: ";
    std::cin >> this->X;
    std::cout << "Enter y coordinate: ";
    std::cin >> this->Y;
    std::cout << "Enter z coordinate: ";
    std::cin >> this->Z;
    std::cout << "Enter Radius: ";
    std::cin >> this->Radius;
}

// D3Circle* D3Circle::instance = nullptr;

// D3Circle::D3Circle() {
//     X = 0;
//     Y = 0;
//     Z = 0;
//     Radius = 0;
// }
// D3Circle *D3Circle::GetInstance(){
//     if(instance ==nullptr){
//         instance = new D3Circle();
//     }
//     return instance;
// }
