#include <iostream>
#include "cube.hpp"
#include "colors.hpp"
#include "fridrich.hpp"

int main(int, char**) {
    std::cout << "CubeSolver running\n";

    //  Step 1: initialize Cube
    Cube cube;

    //  Step 2: scan Cube
    cube.scanCube();

    // std::cout << stringifyColor(cube.getColor(1, 2, 0))
    //  << stringifyColor(cube.getColor(4, 2, 2)) 
    //  << stringifyColor(cube.getColor(5, 0, 0)) << std::endl;

    //  Step 3: solve the cube via Fridrich Method
    Fridrich frd = Fridrich (cube);
    frd.solve();

    // // Step 3: Upper Cross
    // cube.execute("D' F F");
    // // cube.execute("F");
    // // cube.execute("F");

    // cube.printCube();

}
