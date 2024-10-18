#pragma once
#include <fstream>
#include "Triangle.h"
#include <vector>

class Writer {
public:
    void writeToDAT(const std::string& outputFile, const std::vector<Triangle>& triangles, const std::vector<double>& uniqueCoordinates);
};
