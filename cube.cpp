#include "cube.hpp"
#include "colors.hpp"
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

std::string stringifyDirection(int d) {
    switch (d) {
        case (0): return "U"; break;
        case (1): return "F"; break;
        case (2): return "R"; break;
        case (3): return "B"; break;
        case (4): return "L"; break;
        case (5): return "D"; break;
        
    }
};

void Cube::setColor(int f, int x, int y, Color color) {
    faces[f][x][y] = color;
};

Color Cube::getColor(int f, int x, int y) {
    return faces[f][x][y];
};

void Cube::scanCube() {
    std::cout << 
    "Scanning the cube\n" << 
    "Scan one face after the other, each row by row beginning in the upper left corner.\n" <<
    "Enter the colors without separation in lowercase." << 
    std::endl; 

    for(int f = 0; f < 6; f++) {
        char faceColorInput[9];
        std::cout << "Scan face " << stringifyDirection(f) << std::endl;
        std::cin >> faceColorInput;

        int c = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                setColor(f, i, j, parseColor(faceColorInput[c]));
                c++;
            }
        }

        printFace(f);

        // setColor(face, 0, 0, parseColor(faceColorInput[0]));
        // setColor(face, 0, 1, parseColor(faceColorInput[1]));
        // setColor(face, 0, 2, parseColor(faceColorInput[2]));
        // setColor(face, 1, 0, parseColor(faceColorInput[3]));
        // setColor(face, 1, 1, parseColor(faceColorInput[4]));
        // setColor(face, 1, 2, parseColor(faceColorInput[5]));
        // setColor(face, 2, 0, parseColor(faceColorInput[6]));
        // setColor(face, 2, 1, parseColor(faceColorInput[7]));
        // setColor(face, 2, 2, parseColor(faceColorInput[8]));

    }

    std::cout << "Scan complete." << std::endl;
};

void Cube::printFace(int f) {
    std::string s;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            s += stringifyColor(faces[f][i][j]) + " ";
        }
        s += "\n";
    }
    std::cout << s;
};

void Cube::printCube() {
    for (int f = 0; f < 6; f++) {
        std::cout << "Face " + stringifyDirection(f) << std::endl;
        printFace(f);
        std::cout << std::endl;
    }
}

void Cube::F() {
    // Copy the colors of corner ful
    Color ufl = getColor(0,2,0);
    Color luf = getColor(4,0,2);
    // Copy the colors of edge uf
    Color uf = getColor(0,2,1);

    faceRotate(1);

    // Rotate the adjacent edges
    faces[0][2][1] = faces[4][1][2];
    faces[4][1][2] = faces[5][0][1];
    faces[5][0][1] = faces[2][1][0];
    faces[2][1][0] = uf;

    //  Rotate the adjacent corners
    faces[0][2][0] = faces[4][2][2];
    faces[4][2][2] = faces[5][0][2];
    faces[5][0][2] = faces[2][0][0];
    faces[2][0][0] = ufl;

    faces[4][0][2] = faces[5][0][0];
    faces[5][0][0] = faces[2][2][0];
    faces[2][2][0] = faces[0][2][2];
    faces[0][2][2] = luf;
};

void Cube::X() {
    //  Rotate the axis faces.
    faceRotate(2);
    for (int i = 0; i < 3; i++) {
        faceRotate(4);
    }

    //  Copy the front face.
    Face f = getCubeFace(1);
    //  Rotating the top and back faces about 180 degrees is necessary
    for (int i = 0; i < 2; i++) {
        faceRotate(0);
        faceRotate(3);
    }
    setCubeFace(1, getCubeFace(5));
    setCubeFace(5, getCubeFace(3));
    setCubeFace(3, getCubeFace(0));
    setCubeFace(0, f);
};

void Cube::Y() {
    //  Rotate the axis faces.
    faceRotate(0);
    for (int i = 0; i < 3; i++) {
        faceRotate(5);
    }

    //  Copy the front face.
    Face f = getCubeFace(1);

    setCubeFace(1, getCubeFace(2));
    setCubeFace(2, getCubeFace(3));
    setCubeFace(3, getCubeFace(4));
    setCubeFace(4, f);
};

void Cube::faceRotate(int f) {
    //  Copy the upper left corner face and upper edge face
    Color c_ul = faces[f][0][0];
    Color e_u = faces[f][0][1];

    //  Rotate the edge faces
    faces[f][0][1] = faces[f][1][0];
    faces[f][1][0] = faces[f][2][1];
    faces[f][2][1] = faces[f][1][2];
    faces[f][1][2] = e_u;

    //  Rotate the corner faces
    faces[f][0][0] = faces[f][2][0];
    faces[f][2][0] = faces[f][2][2];
    faces[f][2][2] = faces[f][0][2];
    faces[f][0][2] = c_ul;

};

Face Cube::getCubeFace(int f) {
    Face face;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            face.face[i][j] = faces[f][i][j];
        }
    }
    return face;
};

void Cube::setCubeFace(int f, Face face) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            faces[f][i][j] = face.face[i][j];
        }
    }
};