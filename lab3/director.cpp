#include "director.h"

void Director::SetFigure(Builder* obj){
    builder = obj;
}

Figure* Director::createFigure(char* fileName)
{
    builder->createFigure();

    std::ifstream file;
    file.open(fileName);
    if(file.is_open())
    {
        builder->setPolygons(file);
        file.close();
        file.open(fileName);
        builder->setPoints(file);
        file.close();
        return (builder->getFigure());
    }
    else
    {
        throw std::runtime_error("Ошибка создания фигуры");
    }

}
