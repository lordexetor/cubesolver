#ifndef CUBE_HPP
#define CUBE_HPP

#include "colors.hpp"
#include <string>

struct Face {
    Color face[3][3];
};

//  The directions of the cube:
//  - U meaning up
//  - F meaning front
//  - R meaning right
//  - B meaning back
//  - L meaning left
//  - D meaning down
enum class Direction {
    U, F, R, B, L, D
};

//  Returns the integer value of a direction.
int intifyDirection(Direction d);
//  Returns a string representation of the direction.
std::string stringifyDirection(int d);

//  A cube consists of 6 faces, with 9 colored cubieFaces each.
class Cube {

    public:
        //  Set the color of a cubieFace.
        //  - cubeFace: the face on which a color is set.
        //  - x: the x-coordinate of the cubieFace on the face  
        //  - y: the y-coordinate of the cubieFace on the face
        //  - color: the color to be set
        void setColor(int f, int x, int y, Color color);

        //  Returns the color of a cubieFace
        //  - cubeFace: the face which will be searched
        //  - x: the x-coordinate of the cubieFace on the face  
        //  - y: the y-coordinate of the cubieFace on the face
        Color getColor(int f, int x, int y);

        //  Requests user input to scan the cube.
        void scanCube();

        //  Rotate the front layer 90 degrees clockwise
        void F();
        //  Rotate the whole cube 90 degrees clockwise on the R-L-axis
        void X();
        //  Rotate the whole cube 90 degrees clockwise on the U-D-axis
        void Y();

        //  Print the face to the console.
        void printFace(int f);
        //  Print the whole cube.
        void printCube();
    private:
        //  The faces of the cube with the follwing dimensions:
        //  - x: the face, according to the Colors enum.
        //  - y: the row of the face
        //  - z: the column of the face
        Color faces[6][3][3];
      
        //  Rotate all cubieFaces of the given face 90 degrees clockwise.
        //  THIS IS NOT A VALID MOVE
        void faceRotate(int f);
        
        //  Returns a cubeFace.
        Face getCubeFace(int f);
        //  Set a cube face.
        void setCubeFace(int f, Face face);
};



#endif