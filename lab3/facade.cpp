#include "facade.h"

void Facade::moveFigure(double dx, double dy, double dz)
{
    Command *acommand = new MoveFigure(&bigFigure, &transform, dx, dy, dz);
    acommand->execute();
    delete acommand;
}

void Facade::rotateFigure(double dx, double dy, double dz)
{
    Command *acommand = new RotateFigure(&bigFigure, &transform, dx, dy, dz);
    acommand->execute();
    delete acommand;
}

void Facade::scaleFigure(double dx, double dy, double dz)
{
    Command *acommand = new ScaleFigure(&bigFigure, &transform, dx, dy, dz);
    acommand->execute();
    delete acommand;
}


void Facade::createFigure(FigureBuilder *figureBuilder, char *fileName){
    createFigureDirector.SetFigure(figureBuilder);
    figure = createFigureDirector.createFigure(fileName);
    bigFigure.add(figure);
}
