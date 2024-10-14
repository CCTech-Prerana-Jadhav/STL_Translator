#include "Driver.h"
#include "Reader.h"
#include "Writer.h"
#include "Triangulation.h"
#include "Triangle.h"
#include <stdexcept>

void ShapePlotter::convertSTLToDAT(const std::string& inputFile, const std::string& outputFile) {
    Reader reader;
    std::vector<Point> points = reader.readSTLFile(inputFile);
    Triangulation triangulation;

    for (size_t i = 0; i < points.size(); i += 3) {
        if (i + 2 < points.size()) {
            Triangle triangle(points[i], points[i + 1], points[i + 2]);
            triangulation.addTriangle(triangle);
        }
    }

    Writer writer;
    writer.writeToDAT(outputFile, triangulation.getTriangles(), reader.getUniqueCoordinates());
}
