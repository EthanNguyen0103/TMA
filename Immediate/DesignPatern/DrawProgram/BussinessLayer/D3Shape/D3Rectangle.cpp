#include "D3Rectangle.h"


D3Rectangle& D3Rectangle::getInfo(){
    return *this;
}


void D3Rectangle::showInfo(){
    std::cout << "3DRetangle: ";
    std::cout << '(' << X << ", " << Y <<", " << Z<<") ";
    std::cout << "W: " << Width <<", " << "H: " << Height << std::endl;
}

void D3Rectangle::addObject(){
    std::cout << "Enter x coordinate: ";
    std::cin >> this->X;
    std::cout << "Enter y coordinate: ";
    std::cin >> this->Y;
    std::cout << "Enter y coordinate: ";
    std::cin >> this->Z;
    std::cout << "Enter Width: ";
    std::cin >> this->Width;
    std::cout << "Enter Height: ";
    std::cin >> this->Height;
}

// D3Rectangle* D3Rectangle::instance = nullptr;

// D3Rectangle::D3Rectangle() {
//     X = 0;
//     Y = 0;
//     Z = 0;
//     Width = 0;
//     Height = 0;
// }
// D3Rectangle *D3Rectangle::GetInstance(){
//     if(instance ==nullptr){
//         instance = new D3Rectangle();
//     }
//     return instance;
// }
