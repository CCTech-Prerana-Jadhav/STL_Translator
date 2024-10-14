#include "Writer.h"

void Writer::writeToDAT(const std::string& outputFile, const std::vector<Triangle>& triangles, const std::vector<double>& uniqueCoordinates) {
    std::ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        throw std::runtime_error("Unable to open output file");
    }

    for (const auto& triangle : triangles) {
        const auto& vertices = triangle.getVertices();
        for (size_t j = 0; j < 3; ++j) {
            outFile << uniqueCoordinates[vertices[j].getX()] << " "
                    << uniqueCoordinates[vertices[j].getY()] << " "
                    << uniqueCoordinates[vertices[j].getZ()] << "\n";
        }
        // Repeat the first vertex of the triangle
        outFile << uniqueCoordinates[vertices[0].getX()] << " "
                << uniqueCoordinates[vertices[0].getY()] << " "
                << uniqueCoordinates[vertices[0].getZ()] << "\n";
    }

    outFile.close();
}
