#include "transform_command.h"

void MoveFigure::execute()
{
    for (auto figure : cfigure->children){
       ptrTransform->moveFigure(figure, x, y, z);
    }
}

void RotateFigure::execute()
{
    for (auto figure : cfigure->children){
       ptrTransform->rotateFigure(figure, x, y, z);
    }
}

void ScaleFigure::execute()
{
    for (auto figure : cfigure->children){
       ptrTransform->scaleFigure(figure, x, y, z);
    }
}
