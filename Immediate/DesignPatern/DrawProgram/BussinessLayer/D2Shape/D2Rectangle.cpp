#include "D2Rectangle.h"

D2Rectangle& D2Rectangle::getInfo(){
    return *this;
}




void D2Rectangle::showInfo(){
    std::cout << "2DRetangle: ";
    std::cout << '(' << X << ", " << Y <<"), ";
    std::cout << "W: " << Width <<", " << "H: " << Height << std::endl;
}

void D2Rectangle::addObject(){
    std::cout << "Enter x coordinate: ";
    std::cin >> this->X;
    std::cout << "Enter y coordinate: ";
    std::cin >> this->Y;
    std::cout << "Enter Width: ";
    std::cin >> this->Width;
    std::cout << "Enter Height: ";
    std::cin >> this->Height;
}

// D2Rectangle* D2Rectangle::instance = nullptr;

// D2Rectangle::D2Rectangle() {}
// D2Rectangle *D2Rectangle::GetInstance(){
//     if(instance ==nullptr){
//         instance = new D2Rectangle();
//     }
//     return instance;
// }
