#include "Reader.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

vector<Point> Reader::read_stl_file(Triangulation& triangulation) {
    unordered_map<double, int> unique_value_map;
    ifstream myfile("cube-ascii.stl");
    string line;
    vector<Point> point_list;
    int index = 0;

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            istringstream iss(line);
            string vertex;
            double x, y, z;
            if (iss >> vertex >> x >> y >> z) {
                if (vertex == "vertex") {
                    int xIndex, yIndex, zIndex;

                    if (unique_value_map.find(x) == unique_value_map.end()) {
                        unique_value_map[x] = index++;
                        unique_points.push_back(x);
                    }
                    xIndex = unique_value_map[x];

                    if (unique_value_map.find(y) == unique_value_map.end()) {
                        unique_value_map[y] = index++;
                        unique_points.push_back(y);
                    }
                    yIndex = unique_value_map[y];

                    if (unique_value_map.find(z) == unique_value_map.end()) {
                        unique_value_map[z] = index++;
                        unique_points.push_back(z);
                    }
                    zIndex = unique_value_map[z];

                    Point p(xIndex, yIndex, zIndex);
                    point_list.push_back(p);
                    
                    if (point_list.size() % 3 == 0) {
                        triangulation.addTriangle(Triangle(point_list[point_list.size() - 3], 
                                                            point_list[point_list.size() - 2], 
                                                            point_list[point_list.size() - 1]));
                    }
                }
            }
        }
    }
    return point_list;
}

vector<double> Reader::get_unique_points() {
    return unique_points;
}
