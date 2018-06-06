#ifndef COMPOSITEFIGURE_H
#define COMPOSITEFIGURE_H
#include "ifigure.h"
#include <list>

class CompositeFigure : IFigure
{
public:
    void add(Figure* f){
        children.push_back(f);
    }
    std::list<Figure*> children;
    virtual ~CompositeFigure(){}
};


#endif // COMPOSITEFIGURE_H
