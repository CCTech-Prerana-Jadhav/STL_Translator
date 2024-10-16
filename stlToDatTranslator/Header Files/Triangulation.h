#pragma once
#include <vector>
#include "Triangle.h"

using namespace std;

class Triangulation {
public:
    void addTriangle(const Triangle& triangle);
    vector<Triangle> getTriangles() const;

private:
    vector<Triangle> triangles;
};
