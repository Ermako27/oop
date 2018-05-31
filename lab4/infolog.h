#ifndef INFOLOG_H
#define INFOLOG_H

#include <iostream>

class infolog {
private:

public:
    infolog() = default;
    ~infolog() = default;

    void printString(const char* text){
        std::cout << text << std::endl;
    }
    void printLevelMoveUp(int level){
        std::cout << "Лифт поднимается на " << level << " этаж" << std::endl;
    }
    void printLevelMoveDown(int level){
        std::cout << "Лифт спускается на " << level << " этаж" << std::endl;
    }
    void printLevelStop(int level){
        std::cout << "Лифт остановился на " << level << " этаже" << std::endl;
    }
    void printLevelCall(int level){
        std::cout << "Лифт вызван на " << level << " этаже" << std::endl;
    }
};

#endif // INFOLOG_H
