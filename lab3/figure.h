#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>

#include "point.h"
#include "polygon.h"

class Figure
{
public:
    void add_polygons(Polygon p){
        polygonsArray.push_back(p);
    }
    void add_points(Point p){
        pointsArray.push_back(p);
    }
    std::vector<Point> pointsArray;
    std::vector<Polygon> polygonsArray;
};

#endif // FIGURE_H
