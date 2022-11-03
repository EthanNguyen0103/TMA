#include "drawProgram.h"

void drawProgram::AccessMenu(){
    int userChoice;
    showMenu::printMenu();
    std::cin >> userChoice;
    switch (userChoice)
    {
    case AddObject:{
        std::cin >> newObj;
        saveObjectA.addNewObj(newObj.getShapeObj());
        commands.push_back(userChoice);
        break;
    }
    case ShowObject:{
        saveObjectA.showAllObj();
        break;
    }
    case DeleteObject:{
        int index;
        std::cout << "Enter your index: ";
        std::cin >> index;
        saveObjectA.removeObj(index);
        commands.push_back(userChoice);
        break;
    }
    case ChangeObject:{
        int index;
        std::cout << "Enter your index: ";
        std::cin >> index;
        std::cin >> newObj;
        saveObjectA.changeObject(index, newObj.getShapeObj());
        commands.push_back(userChoice);
        break;
    }
    case Undo:{
        if(!commands.empty()){
        if(commands.back()== Undo){
            commands.pop_back();
        }
        saveObjectA.UNDOVar(commands);
        // commands.pop_back();
        commands.push_back(userChoice);
        break;
        }
        std::cout << "Nothing to UnDO" << std::endl;
        break;
    }
    case Redo:{
        if(!commands.empty()){
        if(commands.back()== Redo){
            commands.pop_back();
        }
            saveObjectA.REDOVar(commands);
            // commands.pop_back();
            commands.push_back(userChoice);

            break;
        }
        std::cout << "Nothing to Redo" << std::endl;
        break;
        }
        // commands.pop_back();
    case Exit:{
        exit(0);
        break;
    }
    default:{
        std::cout << "Undefine choice" << std::endl;
        break;
    }
    }
}