#include "Driver.h"

int main() {
    ShapePlotter plotter;
    plotter.convertSTLToDAT("cube.stl", "data.dat");  
    return 0;
}
