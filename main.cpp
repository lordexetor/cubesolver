#include <iostream>
#include "cube.hpp"
#include "colors.hpp"

int main(int, char**) {
    std::cout << "CubeSolver running\n";

    //  Step 1: initialize Cube
    Cube cube;
    cube.setColor(Direction::F, 1, 1, Color::R);
    std::cout << stringifyColor(cube.getColor(Direction::F, 1, 1)) << std::endl;
   
    //  Step 2: scan Cube
    cube.scanCube();
}
