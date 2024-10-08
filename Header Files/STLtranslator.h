#pragma once
#include "Triangulations.h"
#include <vector>
#include <string>

class FileHandler {
private:
    std::string inputFile;

public:
    FileHandler(const std::string& input);
    void readSTLFile(Triangulation& triangulation);
    void writeVerticesToFile(const std::vector<Point>& vertices);

private:
    void parseSTLLine(const std::string& line, Triangulation& triangulation, std::vector<Point>& vertices);
};

