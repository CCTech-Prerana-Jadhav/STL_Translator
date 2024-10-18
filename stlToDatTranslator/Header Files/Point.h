#pragma once

using namespace std;

class Point {
public:
    Point(int x = 0, int y = 0, int z = 0);
    int getX() const;
    int getY() const;
    int getZ() const;
    ~Point();

private:
    int x, y, z;
};
