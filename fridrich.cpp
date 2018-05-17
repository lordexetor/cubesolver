#include "fridrich.hpp"
#include <iostream>

Fridrich::Fridrich(Cube cube): cube(cube) {
    cube.printCube();
};

void Fridrich::solve() {
    std::cout << std::endl << "Fridrich Solution:" << std::endl;
    whiteCross();
    std::cout << std::endl;
    FTL();
};

void Fridrich::whiteCross() {
    for (int i = 0; i < 4; i++) {
        edgeFrontUp();
        std::cout << std::endl;
        cube.execute("Y");
        std::cout << std::endl;
    }
};

void Fridrich::edgeFrontUp() {
    Color F = cube.f("F");
    Color U = cube.f("U");

    //  pFU F=F U=U
    if (cube.fc("FU", F) && 
        cube.fc("UF", U)
    ) { /*  Nothing happens  */ }
    //  pFD F=F D=U
    else if (
        cube.fc("FD", F) &&
        cube.fc("DF", U)
    ) {
        cube.execute("F F");
    }
    //  pFD F=U D=F
    else if (
        cube.fc("DF", F) &&
        cube.fc("FD", U)
    ) {
        cube.execute("D R F' R'");
    }
    //  pFU F=U U=F
    else if (
        cube.fc("FU", U) &&
        cube.fc("UF", F)
    ) {
        cube.execute("F F");
        edgeFrontUp();
    }

    //  pDR
    else if (cube.edgeAtPosition(F, U, "DR", "RD")) {
        cube.execute("D'");
        edgeFrontUp();
    }
    //  pDB
    else if (cube.edgeAtPosition(F,U, "DB", "BD")) {
        cube.execute("D D");
        edgeFrontUp();
    }
    //  pDL
    else if (cube.edgeAtPosition(F,U, "DL", "LD")) {
        cube.execute("D");
        edgeFrontUp();
    }

    //  pUL
    else if (cube.edgeAtPosition(F,U, "UL", "LU")) {
        cube.execute("L L D");
        edgeFrontUp();
    }
    //  pUB
    else if (cube.edgeAtPosition(F,U, "UB", "BU")) {
        cube.execute("B B D D");
        edgeFrontUp();
    }
    //  pUR
    else if (cube.edgeAtPosition(F,U, "UR", "RU")) {
        cube.execute("R R D'");
        edgeFrontUp();
    }

    //  pBL
    else if (cube.edgeAtPosition(F,U, "BL", "LB")) {
        cube.execute("L' D L");
        edgeFrontUp();
    }
    //  pBR
    else if (cube.edgeAtPosition(F,U, "BR", "RB")) {
        cube.execute("R D' R'");
        edgeFrontUp();
    }
    //  pFL
    else if (cube.edgeAtPosition(F,U, "FL", "LF")) {
        cube.execute("F'");
        edgeFrontUp();
    }
    //  pFR
    else if (cube.edgeAtPosition(F,U, "FR", "RF")) {
        cube.execute("F");
        edgeFrontUp();
    }
};

void Fridrich::FTL() {
    for (int i = 0; i < 4; i++) {
        whiteCorner();
        std::cout << std::endl;
        cube.execute("Y");
        std::cout << std::endl;
    }
};

void Fridrich::whiteCorner() {
    Color F = cube.f("F");
    Color U = cube.f("U");
    Color R = cube.f("R");

    // FUR F=F
    if (cube.cornerAtPosition(F,U,R,"FUR", "RUF", "UFR") && cube.fc("UFR", U)) {
        // do nothing
    } 
    //  FDR U=D
    else if (cube.cornerAtPosition(F,U,R,"FDR", "RDF", "DFR") && cube.fc("DFR", U)) {
        cube.execute("D R D' R R D R");
    }
    //  FDR U=R
    else if (cube.cornerAtPosition(F,U,R,"FDR", "RDF", "DFR") && cube.fc("RDF", U)) {
        cube.execute("D F D' F'");
    }
    //  FDR U=F
    else if (cube.cornerAtPosition(F,U,R,"FDR", "RDF", "DFR") && cube.fc("FDR", U)) {
        cube.execute("D' R' D R");
    }

    //  Everything else: first position to FDR, then run again
    //  FDL
    else if (cube.cornerAtPosition(F,U,R,"FDL", "LDF", "DFL")) {
        cube.execute("D");
        whiteCorner();
    }
    //  BDL
    else if (cube.cornerAtPosition(F,U,R,"BDL", "LDB", "DBL")) {
        cube.execute("D D");
        whiteCorner();
    }
    //  BDR
    else if (cube.cornerAtPosition(F,U,R,"BDR", "RDB", "DBR")) {
        cube.execute("D'");
        whiteCorner();
    }
    //  UFL
    else if (cube.cornerAtPosition(F,U,R,"UFL", "LUF", "FUL")) {
        cube.execute("L D L'");
        whiteCorner();
    }
    //  UFR
    else if (cube.cornerAtPosition(F,U,R,"UFR", "FUR", "RUF")) {
        cube.execute("R' D' R D");
        whiteCorner();
    }
    //  UBL
    else if (cube.cornerAtPosition(F,U,R,"UBL", "LUB", "BUL")) {
        cube.execute("L' D D L");
        whiteCorner();
    }
    //  UBR
    else if (cube.cornerAtPosition(F,U,R,"UBR", "RUB", "BUR")) {
        cube.execute("R D R' D D");
        whiteCorner();
    }
};

// void Fridrich::FTLcorner() {
//    //  FR and FDR already correct
//     if (cube.hasColor(F,1,1,2) && cube.hasColor(R,2,1,0) && cube.hasColor(F,1,2,2) && cube.hasColor(R,2,2,0) && cube.hasColor(D,5,0,2)) {
//         //  do nothing
//     }
    
//     //  1st: Easy cases
//     else if (cube.hasColor(F,1,0,2) && cube.hasColor(R,0,2,2) && cube.hasColor(D,2,0,0) && cube.hasColor(F,0,0,1) && cube.hasColor(R,3,0,1)) {
//         cube.execute("R U R'");
//     }
//     else if (cube.hasColor(D,1,0,2) && cube.hasColor(F,0,2,2) && cube.hasColor(R,2,0,0) && cube.hasColor(F,4,0,1) && cube.hasColor(R,0,1,0)) {
//         cube.execute("F' U' F");
//     }
//     else if (cube.hasColor(F,1,0,1) && cube.hasColor(R,0,2,1) && cube.hasColor(F,1,0,2) && cube.hasColor(R,0,2,2) && cube.hasColor(D,2,0,0)) {
//         cube.execute("U' F' U F");
//     }
//     else if (cube.hasColor(D,1,0,2) && cube.hasColor(F,0,2,2) && cube.hasColor(R,2,0,0) && cube.hasColor(F,0,1,2) && cube.hasColor(R,2,0,1)) {
//         cube.execute("U R U' R'");
//     }

//     //  2nd: Corner in bottom, edge in top
//     else if (cube.hasColor(F,1,0,1) && cube.hasColor(R,0,2,1) && cube.hasColor(F,1,2,2) && cube.hasColor(D,5,0,2) && cube.hasColor(R,2,2,0)) {
//         cube.execute("U R U' R' U' F' U F");
//     }
//     else if (cube.hasColor(F,0,1,2) && cube.hasColor(R,2,0,1) && cube.hasColor(F,1,2,2) && cube.hasColor(D,5,0,2) && cube.hasColor(R,2,2,0)) {
//         cube.execute("U' F' U F U R U' R'");
//     }
//     else if (cube.hasColor(F,1,0,1) && cube.hasColor(R,0,2,1) && cube.hasColor(F,5,0,2) && cube.hasColor(R,1,2,2) && cube.hasColor(D,2,2,0)) {
//         cube.execute("F' U F U' F' U F");
//     } 
//     else if (cube.hasColor(F,0,1,2) && cube.hasColor(R,2,0,1) && cube.hasColor(F,5,0,2) && cube.hasColor(R,1,2,2) && cube.hasColor(D,2,2,0)) {
//         cube.execute("R U R' U' R U R'");
//     }
//     else if (cube.hasColor(F,0,1,2) && cube.hasColor(R,2,0,1) && cube.hasColor(D,1,2,2) && cube.hasColor(F,2,2,0) && cube.hasColor(R,5,0,2)) {
//         cube.execute("R U' R' U R U' R'");
//     }
//     else if (cube.hasColor(F,1,0,1) && cube.hasColor(R,0,2,1) && cube.hasColor(D,1,2,2) && cube.hasColor(F,2,2,0) && cube.hasColor(R,5,0,2)) {
//         cube.execute("F' U' F U F' U' F");
//     }

//     //  3rd: Corner in top, edge in middle
//     else if (cube.hasColor(F,1,1,2) && cube.hasColor(R,2,1,0) && cube.hasColor(D,0,2,2) && cube.hasColor(R,1,0,2) && cube.hasColor(F,2,0,0)) {
//         cube.execute("R U R' U' R U R' U' R U R'");
//     }
//     else if (cube.hasColor(F,1,1,2) && cube.hasColor(R,2,1,0) && cube.hasColor(D,2,0,0) && cube.hasColor(F,1,0,2) && cube.hasColor(R,0,2,2)) {
//         cube.execute("U F' U F U F' U U F");
//     }
//     else if (cube.hasColor(R,1,1,2) && cube.hasColor(F,2,1,0) && cube.hasColor(D,0,2,2) && cube.hasColor(F,2,0,0) && cube.hasColor(R,1,0,2)) {
//         //  TODO: translate U Y' to d
//         cube.execute("R U' R' U Y' R' U R");
//     }
//     else if (cube.hasColor(R,1,1,2) && cube.hasColor(F,2,1,0) && cube.hasColor(D,2,0,0) && cube.hasColor(F,1,0,2) && cube.hasColor(R,0,2,2)) {
//         //  TODO: translate U' Y to d'
//         cube.execute("U F' U' F U' Y F U F'");
//     }
//     else if (cube.hasColor(F,1,1,2) && cube.hasColor(R,2,1,0) && cube.hasColor(D,1,0,2) && cube.hasColor(F,0,2,2) && cube.hasColor(R,2,0,0)) {
//         cube.execute("U' R U' R' U' R U U R'");
//     }
//     else if (cube.hasColor(R,1,1,2) && cube.hasColor(F,2,1,0) && cube.hasColor(D,1,0,2) && cube.hasColor(F,0,2,2) && cube.hasColor(R,2,0,0)) {
//         //  TODO: translate U Y' to d
//         cube.execute("U' R U R' U Y' R' U' R");
//     }

//     //  4th Corner pointing outwards, edge top
//     else if (cube.hasColor(F,2,0,1) && cube.hasColor(R,0,1,2) && cube.hasColor(D,2,0,0) && cube.hasColor(F,1,0,2) && cube.hasColor(R,0,2,2)) {
//         //  TODO: translate U Y' to d
//         cube.execute("R U' R' U U Y' R' U' R");
//     }
//     else if (cube.hasColor(F,0,2,1) && cube.hasColor(R,1,0,1) && cube.hasColor(D,1,0,2) && cube.hasColor(F,0,2,2) && cube.hasColor(R,2,0,0)) {
//         //  TODO: translate U' Y to d'
//         cube.execute("F' U F U' U' Y F U F'");
//     } 
//     else if (cube.hasColor(R,0,0,1) && cube.hasColor(F,3,0,1) && cube.hasColor(D,2,0,0) && cube.hasColor(F,1,0,2) && cube.hasColor(R,0,2,2)) {
//         cube.execute("U F' U U F U F' U U F");
//     }
//     else if (cube.hasColor(F,0,1,0) && cube.hasColor(R,4,0,1) && cube.hasColor(D,1,0,2) && cube.hasColor(F,0,2,2) && cube.hasColor(R,2,0,0)) {
//         cube.execute("U' R U U R' U' R U U R'");
//     }

//     else if (cube.hasColor(R,0,1,0) && cube.hasColor(F,4,0,1) && cube.hasColor(D,2,0,0) && cube.hasColor(F,1,0,2) && cube.hasColor(R,0,2,2)) {
//         cube.execute("U F' U' F U F' U U F");
//     }
//     else if (cube.hasColor(F,0,0,1) && cube.hasColor(R,3,0,1) && cube.hasColor(D,1,0,2) && cube.hasColor(F,0,2,2) && cube.hasColor(R,2,0,0)) {
//         cube.execute("U' R U R' U' R U U R'");
//     }
//     else if (cube.hasColor(F,0,1,2) && cube.hasColor(R,2,0,1) && cube.hasColor(D,2,0,0) && cube.hasColor(F,1,0,2) && cube.hasColor(R,0,2,2)) {
//         cube.execute("U' R U' R' U R U R'");
//     }
//     else if (cube.hasColor(R,0,2,1) && cube.hasColor(F,1,0,1) && cube.hasColor(D,1,0,2) && cube.hasColor(F,0,2,2) && cube.hasColor(R,2,0,0)) {
//         cube.execute("U F' U F U' F' U' F");
//     }

//     else if (cube.hasColor(F,0,0,1) && cube.hasColor(R,4,0,1) && cube.hasColor(D,2,0,0) && cube.hasColor(F,1,0,2) && cube.hasColor(R,0,2,2)) {
//         cube.execute("U' R U R' U R U R'");
//     }
//     else if (cube.hasColor(F,3,0,1) && cube.hasColor(R,0,0,1) && cube.hasColor(D,1,0,2) && cube.hasColor(F,0,2,2) && cube.hasColor(R,2,0,0)) {
//         cube.execute("U F' U' F U' F' U' F");
//     }
//     else if (cube.hasColor(F,0,2,1) && cube.hasColor(R,1,0,1) && cube.hasColor(D,2,0,0) && cube.hasColor(F,1,0,2) && cube.hasColor(R,0,2,2)) {
//         cube.execute("U F' U U F U' R U R'");
//     }
//     else if (cube.hasColor(F,2,0,1) && cube.hasColor(R,0,1,2) && cube.hasColor(D,1,0,2) && cube.hasColor(F,0,2,2) && cube.hasColor(R,2,0,0)) {
//         cube.execute("U' R U U R' U F' U' F");
//     }
       
//     // //  5th: corner pointing up, edge top
//     // else if (cube.hasColor(F,0,2,1) && cube.hasColor(R,1,0,1) && cube.hasColor(D,0,2,2) && cube.hasColor(F,2,0,0) && cube.hasColor(R,1,0,2)) {
//     //     cube.execute("R U R' U' U' R U R' U' R U R'");
//     // }
//     // else if (cube.hasColor(F,2,0,1) && cube.hasColor(R,0,1,2) && cube.hasColor(D,0,2,2) && cube.hasColor(F,2,0,0) && cube.hasColor(R,1,0,2)) {
//     //     cube.execute("Y' R' U' R U U R' U' R U R' U' R' Y");
//     // }
//     // else if (cube.hasColor() && cube.hasColor() && cube.hasColor(D,0,2,2) && cube.hasColor(F,2,0,0) && cube.hasColor(R,1,0,2)) {
//     //     cube.execute("");
//     // }
//     // else if (cube.hasColor() && cube.hasColor() && cube.hasColor(D,0,2,2) && cube.hasColor(F,2,0,0) && cube.hasColor(R,1,0,2)) {
//     //     cube.execute("");
//     // }

//     // else if (cube.hasColor() && cube.hasColor() && cube.hasColor(D,0,2,2) && cube.hasColor(F,2,0,0) && cube.hasColor(R,1,0,2)) {
//     //     cube.execute("");
//     // }
//     // else if (cube.hasColor() && cube.hasColor() && cube.hasColor(D,0,2,2) && cube.hasColor(F,2,0,0) && cube.hasColor(R,1,0,2)) {
//     //     cube.execute("");
//     // }
//     // else if (cube.hasColor() && cube.hasColor() && cube.hasColor(D,0,2,2) && cube.hasColor(F,2,0,0) && cube.hasColor(R,1,0,2)) {
//     //     cube.execute("");
//     // }
//     // else if (cube.hasColor() && cube.hasColor() && cube.hasColor(D,0,2,2) && cube.hasColor(F,2,0,0) && cube.hasColor(R,1,0,2)) {
//     //     cube.execute("");
//     // }


//     // for copypaste
//     else if (cube.hasColor() && cube.hasColor() && cube.hasColor() && cube.hasColor() && cube.hasColor()) {
//         cube.execute("");
//     }


// };