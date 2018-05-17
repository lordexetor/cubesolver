#include "cube.hpp"
#include "colors.hpp"
#include <iostream>
#include <sstream>
#include <iterator>
#include <string>

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

void Cube::F(int n = 1) {
    for (int i = 0; i < n; i++) {

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
    }
};

void Cube::X(int n = 1) {
    for (int i = 0; i < n; i++) {
        
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
    }
};

void Cube::Y(int n = 1) {
    for (int i = 0; i < n; i++) {

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
    }
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

void Cube::execute(std::string movement) {
    //  Search for whitespaces
    auto whitespace = movement.find(" ");
    //  If whitespaces are found, split at the first whitespace and execute both halves separately.
    if (whitespace != std::string::npos) {
        std::string first = movement.substr(0, whitespace);
        execute(first);

        //  The second string without leading whitespace
        std::string second = movement.substr(whitespace);
        auto trimWhitespace = second.find_first_not_of(" ");
        if (trimWhitespace != std::string::npos) {
            std::string trimmedSecond = second.substr(trimWhitespace);
            execute(trimmedSecond);        
        }
    } else {

        //  Cube Rotations
        if (movement == "X") {
            X();
        } else if (movement == "X'") {
            X(3);
        } else if (movement == "Y") {
            Y();
        } else if (movement == "Y'") {
            Y(3);
        } else if (movement == "Z") {
            // X Y X'
            X(); Y(); X(3);
        } else if (movement == "Z'") {
            // X Y' X'
            X(); Y(3); X(3);
        } 
        
        //  Basic Face Rotations
        else if (movement == "F") {
            F();
        } else if (movement == "U") {
            //  X' F X
            X(3); F(); X();
        } else if (movement == "R") {
            // Y F Y'
            Y(); F(); Y(3);
        } else if (movement == "L") {
            // Y' F Y
            Y(3); F(); Y();
        } else if (movement == "B") {
            // Y2 F Y2
            Y(2); F(); Y(2);
        } else if (movement == "D") {
            //  X F X'
            X(); F(); X(3);
        }

        //  Basic Inverse Face Rotations
        else if (movement == "F'") {
            F(3);
        } else if (movement == "U'") {
            //  X' F' X
            X(3); F(3); X();
        } else if (movement == "R'") {
            //  Y F' Y'
            Y(); F(3); Y(3);
        } else if (movement == "L'") {
            //  Y' F' Y
            Y(3); F(3); Y();
        } else if (movement == "B'") {
            //  Y2 F' Y2
            Y(2); F(3); Y(2);
        } else if (movement == "D'") {
            // X F' X'
            X(); F(3); X(3);
        }
        
        std::cout << movement << " ";
    }
};

bool Cube::edgeAtPosition(Color c1, Color c2, int f1, int x1, int y1, int f2, int x2, int y2) {
    if ((faces[f1][x1][y1] == c1 && faces[f2][x2][y2] == c2) ||
        (faces[f1][x1][y1] == c2 && faces[f2][x2][y2] == c1)) {
            return true;
        }
    else return false;
};

bool Cube::edgeAtPosition(Color c1, Color c2, std::string face1, std::string face2) {
    if (
        (fc(face1, c1) && fc(face2, c2)) || 
        (fc(face1, c2) && fc(face2, c1))
        ) return true;
    else return false;
};

bool Cube::cornerAtPosition(Color c1, Color c2, Color c3, int f1, int x1, int y1, int f2, int x2, int y2, int f3, int x3, int y3) {
    Color fc1 = faces[f1][x1][y1];
    Color fc2 = faces[f2][x2][y2];
    Color fc3 = faces[f3][x3][y3];

    if (
        (fc1 == c1 && fc2 == c2 && fc3 == c3) ||
        (fc1 == c1 && fc2 == c3 && fc3 == c2) ||
        (fc1 == c2 && fc2 == c1 && fc3 == c3) ||
        (fc1 == c2 && fc2 == c3 && fc3 == c1) ||
        (fc1 == c3 && fc2 == c1 && fc3 == c2) ||
        (fc1 == c3 && fc2 == c2 && fc3 == c1) 
    ) {
        return true;
    } else return false;
};

bool Cube::cornerAtPosition(Color c1, Color c2, Color c3, std::string face1, std::string face2, std::string face3) {
    if (
        (fc(face1, c1) && fc(face2, c2) && fc(face3, c3)) ||
        (fc(face1, c1) && fc(face2, c3) && fc(face3, c2)) ||
        (fc(face1, c2) && fc(face2, c1) && fc(face3, c3)) ||
        (fc(face1, c2) && fc(face2, c3) && fc(face3, c1)) ||
        (fc(face1, c3) && fc(face2, c1) && fc(face3, c2)) ||
        (fc(face1, c3) && fc(face2, c2) && fc(face3, c1))
    ) return true; 
    else return false;
};

bool Cube::hasColor(Color c, int f, int x, int y) {
    if (faces[f][x][y] == c) return true;
    else return false;
};

Color Cube::f(std::string s) {
    if (s == "UBL")         return faces[0][0][0];
    else if (s == "UB")     return faces[0][0][1];
    else if (s == "UBR")    return faces[0][0][2];
    else if (s == "UL")     return faces[0][1][0];
    else if (s == "U")      return faces[0][1][1];
    else if (s == "UR")     return faces[0][1][2];
    else if (s == "UFL")    return faces[0][2][0];
    else if (s == "UF")     return faces[0][2][1];
    else if (s == "UFR")    return faces[0][2][2];

    else if (s == "FUL")    return faces[1][0][0];
    else if (s == "FU")     return faces[1][0][1];
    else if (s == "FUR")    return faces[1][0][2];
    else if (s == "FL")     return faces[1][1][0];
    else if (s == "F")      return faces[1][1][1];
    else if (s == "FR")     return faces[1][1][2];
    else if (s == "FDL")    return faces[1][2][0];
    else if (s == "FD")     return faces[1][2][1];
    else if (s == "FDR")    return faces[1][2][2];

    else if (s == "RUF")    return faces[2][0][0];
    else if (s == "RU")     return faces[2][0][1];
    else if (s == "RUB")    return faces[2][0][2];
    else if (s == "RF")     return faces[2][1][0];
    else if (s == "R")      return faces[2][1][1];
    else if (s == "RB")     return faces[2][1][2];
    else if (s == "RDF")    return faces[2][2][0];
    else if (s == "RD")     return faces[2][2][1];
    else if (s == "RDB")    return faces[2][2][2];

    else if (s == "BUR")    return faces[3][0][0];
    else if (s == "BU")     return faces[3][0][1];
    else if (s == "BUL")    return faces[3][0][2];
    else if (s == "BR")     return faces[3][1][0];
    else if (s == "B")      return faces[3][1][1];
    else if (s == "BL")     return faces[3][1][2];
    else if (s == "BDR")    return faces[3][2][0];
    else if (s == "BD")     return faces[3][2][1];
    else if (s == "BDL")    return faces[3][2][2];

    else if (s == "LUB")    return faces[4][0][0];
    else if (s == "LU")     return faces[4][0][1];
    else if (s == "LUF")    return faces[4][0][2];
    else if (s == "LB")     return faces[4][1][0];
    else if (s == "L")      return faces[4][1][1];
    else if (s == "LF")     return faces[4][1][2];
    else if (s == "LDB")    return faces[4][2][0];
    else if (s == "LD")     return faces[4][2][1];
    else if (s == "LDF")    return faces[4][2][2];

    else if (s == "DFL")    return faces[5][0][0];
    else if (s == "DF")     return faces[5][0][1];
    else if (s == "DFR")    return faces[5][0][2];
    else if (s == "DL")     return faces[5][1][0];
    else if (s == "D")      return faces[5][1][1];
    else if (s == "DR")     return faces[5][1][2];
    else if (s == "DBL")    return faces[5][2][0];
    else if (s == "DB")     return faces[5][2][1];
    else if (s == "DBR")    return faces[5][2][2];

    //  Signal that the string is wrong otherwise.
    else std::cout << "Failed to recognize string " << s << std::endl; return Color::W;
};

bool Cube::fc(std::string face, Color c) {
    if (f(face) == c) return true;
    else return false;
}