#ifndef FRIDRICH_HPP
#define FRIDRICH_HPP

#include "cube.hpp"
#include "colors.hpp"

//  Computes a solution for the cube with the Fridrich Method
class Fridrich {
    public:
        //  Initializes a new Fridrich's solution on the given cube.
        Fridrich(Cube cube);
        //  Solves the cube with the Fridrich Method.
        void solve();
    private:
        //  The cube to be solved.
        Cube cube;

        //  create the 'White Cross' - position and orient the edges of the first layer.
        void whiteCross();

        //  completes the first two layers
        void FTL();

        //  Position and orient the upper front edge.
        void edgeFrontUp();

        //  One Operation for the FTL (deprecated)
        void FTLcorner();

        //  Position and orient a corner in the first layer
        void whiteCorner();

        //  Position and orient the front right edge.
        void edgeFrontRight();

        //  create the 'Yellow Cross' - orient the edges of the third layer.
        void yellowCross();

        //  position the edges of the third layer.
        void positionYellowEdges();

        //  position the corners of the third layer.
        void positionYellowCorners();

        //  orient the corners of the third layer.
        void orientYellowCorners();
};

#endif