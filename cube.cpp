#include "cube.hpp"
#include <iostream>

int intifyDirection(Direction d) {
    switch (d) {
        case (Direction::U): return 0; break;
        case (Direction::F): return 1; break;
        case (Direction::R): return 2; break;
        case (Direction::B): return 3; break;
        case (Direction::L): return 4; break;
        case (Direction::D): return 5; break;
    }
};

void Cube::setColor(Direction face, int x, int y, Color color) {
    

    faces[intifyDirection(face)][x][y] = color;
};

Color Cube::getColor(Direction face, int x, int y) {
    return faces[intifyDirection(face)][x][y];
};

void Cube::scanCube() {
    std::cout << 
    "Scanning the cube\n" << 
    "Scan one face after the other, each row by row beginning in the upper left corner.\n" <<
    "Enter the colors separated by a [space] in lowercase." << 
    std::endl; 

    char faceColorInput[9];
    std::cin >> faceColorInput;
    std::cout << faceColorInput[3] << std::endl;

};