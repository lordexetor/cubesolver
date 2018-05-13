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

        //  create the 'White Cross' - position and orient the edges of the upper layer.
        void whiteCross();

        //  Position and orient the upper front edge.
        void edgeFrontUp();
};

#endif