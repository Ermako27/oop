#ifndef TRANSFORM_COMMAND_H
#define TRANSFORM_COMMAND_H

#include "transform.h"

class MoveFigure : public Command
{
public:
    MoveFigure(CompositeFigure* f, Transform* t, double _x, double _y, double _z) : cfigure(f), ptrTransform(t), x(_x), y(_y), z(_z) {}
    void execute();
private:
    CompositeFigure *cfigure;
    Transform* ptrTransform;
    double x,y,z;
};

class RotateFigure : public Command
{
public:
    RotateFigure(CompositeFigure* f, Transform* t, double _x, double _y, double _z) : cfigure(f), ptrTransform(t), x(_x), y(_y), z(_z) {}
    void execute();
private:
    CompositeFigure *cfigure;
    Transform* ptrTransform;
    double x,y,z;
};

class ScaleFigure : public Command
{
public:
    ScaleFigure(CompositeFigure* f, Transform* t, double _x, double _y, double _z) : cfigure(f), ptrTransform(t), x(_x), y(_y), z(_z) {}
    void execute();
private:
    CompositeFigure *cfigure;
    Transform* ptrTransform;
    double x,y,z;
};

#endif // COMMAND_H
