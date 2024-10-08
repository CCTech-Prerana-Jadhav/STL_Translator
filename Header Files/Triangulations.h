#pragma once
#include "Triangle.h"
#include <vector>

class Triangulation {
public:
    std::vector<Triangle> triangles;

    void addTriangle(const Triangle& triangle);
};

