#include <iostream>
#include <fstream>
#include "Reader.h"
#include "Triangle.h"
#include "Triangulations.h"

using namespace std;

int main() {
    try {
        Reader reader;
        vector<Point> points = reader.read_stl_file();
        Triangulation triangulation;

        for (size_t i = 0; i < points.size(); i += 3) {
            if (i + 2 < points.size()) {
                Triangle triangle(points[i], points[i + 1], points[i + 2]);
                triangulation.addTriangle(triangle);
            }
        }

        ofstream outFile("data.dat");
        if (!outFile.is_open()) {
            throw runtime_error("Unable to open output file");
        }

        for (const auto& triangle : triangulation.getTriangles()) {
            const auto& vertices = triangle.getVertices();
            for (size_t j = 0; j < 3; ++j) {
                outFile << vertices[j].getX() << " "
                    << vertices[j].getY() << " "
                    << vertices[j].getZ() << "\n";
            }
            // Repeat the first vertex of the triangle
            outFile << vertices[0].getX() << " "
                << vertices[0].getY() << " "
                << vertices[0].getZ() << "\n";
        }

        outFile.close();
        cout << "Data successfully written to data.dat" << endl;

    }
    catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
    }
    return 0;
}
