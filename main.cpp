#include <iostream>
#include "cube.hpp"
#include "colors.hpp"

int main(int, char**) {
    std::cout << "CubeSolver running\n";

    //  Step 1: initialize Cube
    Cube cube;
    cube.setColor(1, 1, 1, Color::R);
    std::cout << stringifyColor(cube.getColor(1, 1, 1)) << std::endl;
   
    //  Step 2: scan Cube
    cube.scanCube();

    std::cout << stringifyColor(cube.getColor(1, 2, 0))
     << stringifyColor(cube.getColor(4, 2, 2)) 
     << stringifyColor(cube.getColor(5, 0, 0)) << std::endl;

    // Step 3: Upper Cross
    cube.execute("D' F F");
    // cube.execute("F");
    // cube.execute("F");

    cube.printCube();

}
