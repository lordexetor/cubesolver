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

        //  Returns true, if one of the two cubieFaces equals the first color, and the other the second (or vice versa)
        bool edgeAtPosition(Color c1, Color c2, int f1, int x1, int y1, int f2, int x2, int y2);

        //  Returns true, if one of the two cubieFaces equals the first color, and the other the second (or vice versa)
        bool edgeAtPosition(Color c1, Color c2, std::string face1, std::string face2);

        //  Returns true, the given colors equal the cubeFacies, one each, no matter which.
        bool cornerAtPosition(Color c1, Color c2, Color c3, int f1, int x1, int y1, int f2, int x2, int y2, int f3, int x3, int y3);

        //  Returns true, the given colors equal the cubeFacies, one each, no matter which.
        bool cornerAtPosition(Color c1, Color c2, Color c3, std::string face1, std::string face2, std::string face3);

        //  Returns true, if the given cubieFace has the given color
        bool hasColor(Color c, int f, int x, int y);

        //  Requests user input to scan the cube.
        void scanCube();

        //  Rotate the front layer 90 degrees clockwise
        void F(int n);
        //  Rotate the whole cube 90 degrees clockwise on the R-L-axis
        void X(int n);
        //  Rotate the whole cube 90 degrees clockwise on the U-D-axis
        void Y(int n);

        //  Returns the color of the given face.
        //  Face can be e.g. "FUR", "RU", "B"
        Color f(std::string face);

        //  Returns true if the given face has the given color.
        bool fc(std::string face, Color c);

        //  Execute the movements given in notation.
        void execute(std::string movement);

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