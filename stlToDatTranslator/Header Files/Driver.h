#pragma once
#include "Reader.h"
#include "Writer.h"
#include "Triangulation.h"
#include "Triangle.h"

class ShapePlotter {
public:
    void convertSTLToDAT(const std::string& inputFile, const std::string& outputFile);
};
