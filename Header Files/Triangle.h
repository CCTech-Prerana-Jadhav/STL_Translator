#pragma once
#include <array>
#include "Point.h"

using namespace std;

class Triangle {
public:
    Triangle(const Point& p1, const Point& p2, const Point& p3);
    array<Point, 3> getVertices() const;
    ~Triangle();

private:
    array<Point, 3> vertices;
};
