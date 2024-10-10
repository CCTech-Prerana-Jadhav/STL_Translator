#include "Triangle.h"

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) : vertices({ p1, p2, p3 }) {}

array<Point, 3> Triangle::getVertices() const {
    return vertices;
}

Triangle::~Triangle(){}