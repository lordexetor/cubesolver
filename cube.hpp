#ifndef CUBE_HPP
#define CUBE_HPP

#include "colors.hpp"

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

//  A cube consists of 6 faces, with 9 colored cubieFaces each.
class Cube {

    public:
        //  Set the color of a cubieFace.
        //  - cubeFace: the face on which a color is set.
        //  - x: the x-coordinate of the cubieFace on the face  
        //  - y: the y-coordinate of the cubieFace on the face
        //  - color: the color to be set
        void setColor(Direction face, int x, int y, Color color);

        //  Returns the color of a cubieFace
        //  - cubeFace: the face which will be searched
        //  - x: the x-coordinate of the cubieFace on the face  
        //  - y: the y-coordinate of the cubieFace on the face
        Color getColor(Direction f, int x, int y);

        //  Requests user input to scan the cube.
        void scanCube();
    private:
        //  The faces of the cube with the follwing dimensions:
        //  - x: the face, according to the Colors enum.
        //  - y: the row of the face
        //  - z: the column of the face
        Color faces[6][3][3];
      
        // //  Returns a cubeFace based on its direction
        // int getCubeFace(Direction d);
};



#endif