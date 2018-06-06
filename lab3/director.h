#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "figure.h"
#include "figure_builder.h"

class Director
{
public:
    void SetFigure(Builder*);
    Figure* createFigure(char*);
protected:
    Builder* builder;
};

#endif // DIRECTOR_H
