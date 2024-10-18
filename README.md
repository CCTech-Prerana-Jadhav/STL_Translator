# 3D Shape Plotter

## Overview
The **3D Shape Plotter** is a C++ application that converts 3D objects from STL files into DAT format for visualization using Gnuplot. The application reads the STL file, processes the vertices into unique points, forms triangles, and writes the actual 3D coordinates to a `data.dat` file that can be visualized in Gnuplot.

## Features
- **STL to DAT Conversion**: Converts 3D shapes from STL files into a format that can be visualized in Gnuplot.
- **Unique Point Handling**: Efficiently handles unique points by storing them as indices but outputs actual (x, y, z) coordinates in the `data.dat` file for accurate visualization.
- **Supports Gnuplot Visualization**: The generated DAT file can be directly used in Gnuplot for 3D rendering of the object.

## Prerequisites
Before running the project, ensure you have the following installed on your system:
- **GNU C++ Compiler (g++)**
- **Gnuplot** for visualization
- **STL File**: A valid STL file (ASCII or Binary) for conversion

## Project Structure
3D_Shape_Plotter/ │ 
├── src/ │ 
├── Driver.cpp # Main program logic │ 
├── Reader.cpp # STL file reader │ 
├── Writer.cpp # DAT file writer │ 
├── Point.cpp # Point class │ 
├── Triangle.cpp # Triangle class │ 
├── Triangulation.cpp # Triangulation class │ 
└── main.cpp # Entry point │ 
├── include/ │ 
├── Driver.h # Driver class header │ 
├── Reader.h # Reader class header │ 
├── Writer.h # Writer class header │ 
├── Point.h # Point class header │ 
├── Triangle.h # Triangle class header │ 
└── Triangulation.h # Triangulation class header │ 
├── data/ │ 
└── cube-ascii.stl # Example STL file (you can replace this with your own) │
└── data.dat # Output DAT file for visualization


## Compilation and Execution

### 1. **Clone or Download the Repository**
First, clone or download the project:
```bash
git clone https://github.com/your-repo/3D_Shape_Plotter.git
cd 3D_Shape_Plotter
