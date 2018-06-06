#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include <vector>

class Polygon
{
public:
    bool empty(){
        return polygonArray.empty();
    }
    void add(int num){
        polygonArray.push_back(num);
    }
    std::vector<int> polygonArray;
};

#endif // POLYGON_H
