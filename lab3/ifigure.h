#ifndef IFIGURE_H
#define IFIGURE_H
#include <memory>
#include "figure.h"

class IFigure
{
public:
    virtual void add(Figure* f) = 0;
    virtual ~IFigure(){}
};



#endif // IFIGURE_H
