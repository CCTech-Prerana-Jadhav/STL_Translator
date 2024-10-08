#include "STLtranslator.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

FileHandler::FileHandler(const std::string& input) : inputFile(input) {}

void FileHandler::readSTLFile(Triangulation& triangulation) {
    std::ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        throw std::runtime_error("Unable to open STL file");
    }

    std::string line;
    std::vector<Point> vertices;

    while (getline(inFile, line)) {
        parseSTLLine(line, triangulation, vertices);
    }

    inFile.close();
    writeVerticesToFile(vertices); // Write all vertices after reading
}

void FileHandler::writeVerticesToFile(const std::vector<Point>& vertices) {
    std::ofstream dataFile("data.dat");
    if (!dataFile.is_open()) {
        throw std::runtime_error("Unable to open data.dat");
    }

    for (const auto& vertex : vertices) {
        dataFile << vertex.x << " " << vertex.y << " " << vertex.z << "\n";
    }

    dataFile.close();
}

void FileHandler::parseSTLLine(const std::string& line, Triangulation& triangulation, std::vector<Point>& vertices) {
    std::stringstream ss(line);
    std::string word;

    if (ss >> word && word == "vertex") {
        float x, y, z;
        if (ss >> x >> y >> z) {
            Point vertex(static_cast<int>(x), static_cast<int>(y), static_cast<int>(z));
            vertices.push_back(vertex); // Store every vertex read

            // Create triangles (assuming 3 vertices per triangle)
            if (vertices.size() % 3 == 0) {
                triangulation.addTriangle(Triangle(vertices[vertices.size() - 3],
                    vertices[vertices.size() - 2],
                    vertices[vertices.size() - 1]));
            }
        }
    }
}

