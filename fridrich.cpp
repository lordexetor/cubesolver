#include "fridrich.hpp"

Fridrich::Fridrich(Cube cube): cube(cube) {
    cube.printCube();
};

void Fridrich::solve() {
    whiteCross();
};

void Fridrich::whiteCross() {
    for (int i = 0; i < 4; i++) {
        edgeFrontUp();
        cube.execute("Y");
    }
};

void Fridrich::edgeFrontUp() {
    Color F = cube.getColor(1,1,1);
    Color U = cube.getColor(0,1,1);

    //  pFU F=F U=U
    if (cube.getColor(1,0,1) == F &&
        cube.getColor(0,2,1) == U
    ) { /*  Nothing happens  */ }
    //  pFD F=F D=U
    else if (
        cube.getColor(1,2,1) == F &&
        cube.getColor(5,0,1) == U
    ) {
        cube.execute("F F");
    }
    //  pFD F=U D=F
    else if (
        cube.getColor(1,2,1) == U &&
        cube.getColor(5,0,1) == F
    ) {
        cube.execute("D R F' R'");
    }
    //  pFU F=U U=F
    else if (
        cube.getColor(0,2,1) == F &&
        cube.getColor(1,0,1) == U
    ) {
        cube.execute("F F");
        edgeFrontUp();
    }

    //  pDR
    else if (cube.edgeAtPosition(F, U, 5,1,2, 2,2,1)) {
        cube.execute("D'");
        edgeFrontUp();
    }
    //  pDB
    else if (cube.edgeAtPosition(F,U, 5,2,1, 3,2,1)) {
        cube.execute("D D");
        edgeFrontUp();
    }
    //  pDL
    else if (cube.edgeAtPosition(F,U, 5,1,0, 4,2,1)) {
        cube.execute("D");
        edgeFrontUp();
    }

    //  pUL
    else if (cube.edgeAtPosition(F,U, 0,1,0, 4,0,1)) {
        cube.execute("L L D");
        edgeFrontUp();
    }
    //  pUB
    else if (cube.edgeAtPosition(F,U, 0,0,1, 3,0,1)) {
        cube.execute("B B D D");
        edgeFrontUp();
    }
    //  pUR
    else if (cube.edgeAtPosition(F,U, 0,1,2, 2,0,1)) {
        cube.execute("R R D'");
        edgeFrontUp();
    }

    //  pBL
    else if (cube.edgeAtPosition(F,U, 3,1,2, 4,1,0)) {
        cube.execute("L' D L");
        edgeFrontUp();
    }
    //  pBR
    else if (cube.edgeAtPosition(F,U, 3,1,0, 2,1,2)) {
        cube.execute("R D' R'");
        edgeFrontUp();
    }
    //  pFL
    else if (cube.edgeAtPosition(F,U, 1,1,0, 4,1,2)) {
        cube.execute("L D L'");
        edgeFrontUp();
    }
    //  pFR
    else if (cube.edgeAtPosition(F,U, 1,1,2, 2,1,0)) {
        cube.execute("R' D' R");
        edgeFrontUp();
    }


    // //  pFR F=U R=F 
    // else if (
    //     cube.getColor(1,1,2) == U &&
    //     cube.getColor(2,1,0) == F) {
    //         cube.execute("R' D' R");
    //         edgeFrontUp();
    //     } 
    // //  pFU U=F F=U
    // else if (
    //     cube.getColor(1,0,1) == U &&
    //     cube.getColor(0,2,1) == F) {
    //         cube.execute("F");
    //         edgeFrontUp();
    //     }
    // //  pFL F=U L=F
    // else if (
    //     cube.getColor(1,1,0) == U &&
    //     cube.getColor(4,1,2) == F) {
    //         cube.execute("F F");
    //         edgeFrontUp();
    //     }
    // //  pFD F=U D=F
    // else if (
    //     cube.getColor(1,2,1) == U &&
    //     cube.getColor(5,0,1) == F) {
    //         cube.execute("F'");
    //         edgeFrontUp();
    //     }
    // //  pFR F=F R=U
    // else if (
    //     cube.getColor(1,1,2) == F &&
    //     cube.getColor(2,1,0) == U) {
    //         cube.execute("F'");
    //     }
    // //  pFL F=F L=U
    // else if (
    //     cube.getColor(1,1,0) == F &&
    //     cube.getColor(4,1,2) == U) {
    //         cube.execute("F");
    //     }
    // //  pDR D=U R=F
    // else if (
    //     cube.getColor(5,1,2) == U &&
    //     cube.getColor(2,2,1) == F) {
    //         cube.execute("D'");
    //         edgeFrontUp();
    //     }
    // //  pDB D=U B=F
    // else if (
    //     cube.getColor(5,2,1) == U &&
    //     cube.getColor(3,2,1) == F) {
    //         cube.execute("D D");
    //         edgeFrontUp();
    //     }
    // //  pDL D=U L=F
    // else if (
    //     cube.getColor(5,1,0) == U &&
    //     cube.getColor(4,2,1) == F) {
    //         cube.execute("D");
    //         edgeFrontUp();
    //     }

    // //  pUR U=U R=F
    // else if (
    //     cube.getColor(0,1,2) == U &&
    //     cube.getColor(2,0,1) == F) {
    //         cube.execute("R R");
    //         edgeFrontUp();
    //     }
    // //  pUB U=U B=F
    // else if (
    //     cube.getColor(0,0,1) == U &&
    //     cube.getColor(3,0,1) == F) {
    //         cube.execute("B B");
    //         edgeFrontUp();
    //     }
    // )
    // //  pUL U=U L=F
    // else if (
    //     cube.getColor(0,0,1) == U &&
    //     cube.getColor(4,0,1) == F) {
    //         cube.execute("L L");
    //         edgeFrontUp();
    //     }
};