#ifndef FACADE_H
#define FACADE_H

#include <QApplication>

#include "transform.h"
#include "transform_command.h"
#include "director.h"
#include "figure_builder.h"
#include "compositefigure.h"


class Facade
{

public:
    CompositeFigure bigFigure;
    Figure *figure;
    Transform transform;
    Director createFigureDirector;

    void moveFigure(double, double, double);
    void rotateFigure(double, double, double);
    void scaleFigure(double, double, double);

    void createFigure(FigureBuilder *figureBuilder, char *fileName);
};

#endif // FACADE_H
