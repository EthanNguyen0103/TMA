#include "getFactory.h"


ShapeObject* getFactory::getShapeObj(){
  FactoryMaker *choiceFactory = new FactoryMaker();
  AbstractFactory* factory = choiceFactory->getFactory(typeFactory);
  ShapeObject *Object = factory->getShape(typeShape);
  return Object;
}

std::istream& operator>>(std::istream& in, getFactory& g){
    int userChoiceD;
    int userChoiceShape;
    checkD:
    std::cout << "Enter 3D or 2D: \n";
    std::cout << "1. 2D\n"; 
    std::cout << "2. 3D\n"; 
    std::cin >> userChoiceD;
    switch (userChoiceD)
    {
      case D2:{
        g.typeFactory = D2;
        break;
      }
      case D3:{
        g.typeFactory = D3;
        break;
      }
      default:{
        std::cout << "Undefine D" << std::endl;
        goto checkD;
        break;
      }
    }
    checkShape:
    std::cout << "Enter Rectangle or Circle: \n";
    std::cout << "1. Rectangle\n"; 
    std::cout << "2. Circle\n";
    std::cin >> userChoiceShape;
    switch (userChoiceShape)
    {
    case Rectangle:{
      g.typeShape = Rectangle;
      break;
    }
    case Circle:{
      g.typeShape = Circle;
      break;
    }
    default:
      std::cout << "Undefine shape" << std::endl;
      goto checkShape;
      break;
    }

    return in;
  }
  




