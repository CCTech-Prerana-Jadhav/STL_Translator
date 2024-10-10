#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include "Point.h"

using namespace std;

class Reader {
public:
    vector<Point> read_stl_file();
    vector<double> get_unique_points();

private:
    vector<double> unique_points;
};
