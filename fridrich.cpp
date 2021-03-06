#include "fridrich.hpp"
#include <iostream>

Fridrich::Fridrich(Cube cube): cube(cube) {
    cube.printCube();
};

void Fridrich::solve() {
    std::cout << "-----------------------" << std::endl;;

    std::cout << std::endl << "Fridrich Solution:" << std::endl;
    whiteCross();
    std::cout << std::endl << "-----------------------" << std::endl;;

    FTL();
    std::cout << std::endl << "-----------------------" << std::endl;;

    yellowCross();
    std::cout << std::endl << "-----------------------" << std::endl;;
    positionYellowEdges();

    std::cout << std::endl << "-----------------------" << std::endl;;
    positionYellowCorners();
    std::cout << std::endl << "-----------------------" << std::endl;;
    for (int i = 0; i < 4; i++) {
        orientYellowCorners();
    }
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
    //  Fill thte corners
    for (int i = 0; i < 4; i++) {
        whiteCorner();
        std::cout << std::endl;
        cube.execute("Y");
        std::cout << std::endl;
    }
    std::cout << "-----------------------" << std::endl;;
    cube.execute("X X");
    std::cout << std::endl;

    for (int i = 0; i < 4; i++) {
        edgeFrontRight();        
        std::cout << std::endl;
        cube.execute("Y");
        std::cout << std::endl;

    }};

void Fridrich::whiteCorner() {
    Color F = cube.f("F");
    Color U = cube.f("U");
    Color R = cube.f("R");

    // FUR F=F
    if (cube.cornerAtPosition(F,U,R,"FUR", "RUF", "UFR") && cube.fc("UFR", U)) {
        // do nothing
    } 
    //  When in corner FDR, move to corner FUR, depending on orientation
    //  FDR U=D
    else if (cube.cornerAtPosition(F,U,R,"FDR", "RDF", "DFR") && cube.fc("DFR", U)) {
        cube.execute("R' D R F D D F'");
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

void Fridrich::edgeFrontRight() {
    Color F = cube.f("F");
    Color R = cube.f("R");

    std::string topRightAlgorithm = "U R U' R' U' F' U F";
    std::string topLeftAlgorithm = "U' L' U L U F U' F'";

    //  The edge is already in the correct orientation and position.
    if (cube.edgeAtPosition(F,R,"FR","RF") && cube.fc("FR",F)) {/* Do nothing */}
    //  UF, F=F
    else if (cube.edgeAtPosition(F,R,"FU","UF") && cube.fc("FU",F)) {
        cube.execute(topRightAlgorithm);
    }
    //  UF, F=U
    else if (cube.edgeAtPosition(F,R,"FU","UF") && cube.fc("UF", F)) {
        cube.execute("U'");
        cube.execute("Y");
        cube.execute(topLeftAlgorithm);
        cube.execute("Y'");
    }
    //  FR, F=R
    else if (cube.edgeAtPosition(F,R,"FR","RF") && cube.fc("FR", R)) {
        cube.execute(topRightAlgorithm);
        edgeFrontRight();
    }
    //  UR
    else if (cube.edgeAtPosition(F,R,"UR","RU")) {
        cube.execute("U");
        edgeFrontRight();
    } 
    //  UB
    else if (cube.edgeAtPosition(F,R,"UB","BU")) {
        cube.execute("U U");
        edgeFrontRight();
    }
    //  UL
    else if (cube.edgeAtPosition(F,R,"UL","LU")) {
        cube.execute("U'");
        edgeFrontRight();
    }
    //  BR
    else if (cube.edgeAtPosition(F,R,"RB","BR")) {
        cube.execute("Y");
        std::cout << std::endl;
        cube.execute(topRightAlgorithm);
        std::cout << std::endl;
        cube.execute("Y'");
        std::cout << std::endl;
        edgeFrontRight();
    }
    //  BL
    else if (cube.edgeAtPosition(F,R,"BL","LB")) {
        cube.execute ("Y Y");
        std::cout << std::endl;
        cube.execute(topRightAlgorithm);
        std::cout << std::endl;
        cube.execute("Y Y");
        std::cout << std::endl;
        edgeFrontRight();
    }
    // FL
    else if (cube.edgeAtPosition(F,R,"FL","LF")) {
        cube.execute(topLeftAlgorithm);
        edgeFrontRight();
    }
};

void Fridrich::yellowCross() {
    std::string yellowCrossAlgorithm = "F R U R' U' F'";
    Color U = cube.f("U");

    //  The edges are already in the correct orientation
    if (cube.fc("UL", U) && cube.fc("UB", U) && cube.fc("UR", U) && cube.fc("UF", U)) { /* Do nothing */ }
    //  left and right edges are in the correct orientation
    else if (cube.fc("UL", U) && cube.fc("UR", U)) {
        cube.execute(yellowCrossAlgorithm);
    }
    //  front and back edges are in the correct orientation
    else if (cube.fc("UB", U) && cube.fc("UF", U)) {
        cube.execute("U");
        yellowCross();
    }
    //  back and left edges are in the correct orientation
    else if (cube.fc("UB", U) && cube.fc("UL", U)) {
        cube.execute(yellowCrossAlgorithm);
        yellowCross();
    }
    //  back and right edges are in the correct orientation
    else if (cube.fc("UB", U) && cube.fc("UR", U)) {
        cube.execute("U'");
        yellowCross();
    }
    //  front and right edges are in the correct orientation
    else if (cube.fc("UR", U) && cube.fc("UF", U)) {
        cube.execute("U U");
        yellowCross();
    }
    //  front and left edges are in the correct orientation
    else if (cube.fc("UL", U) && cube.fc("UF", U)) {
        cube.execute("U");
        yellowCross();
    }
    //  no edges are in the correct orientation
    else {
        cube.execute(yellowCrossAlgorithm);
        yellowCross();
    }
    std::cout << std::endl;
};

void Fridrich::positionYellowEdges() {
    std::string switchPositions = "R U R' U R U U R' U";
    
    Color F = cube.f("F");
    Color L = cube.f("L");
    Color B = cube.f("B");
    Color R = cube.f("R");

    //  Edges are already positioned correctly
    if (cube.fc("FU", F) && cube.fc("LU", L) && cube.fc("BU", B)) { /* Do nothing */ }
    //  F <--> L
    else if (cube.fc("FU", L) && cube.fc("LU", F)) {
        cube.execute(switchPositions);
        positionYellowEdges();
    }
    //  F <--> B
    else if (cube.fc("FU", B) && cube.fc("BU", F)) {
        cube.execute(switchPositions);
        std::cout << std::endl;
        cube.execute("Y Y");
        std::cout << std::endl;
        cube.execute("U");
        std::cout << std::endl;
        cube.execute("Y'");
        std::cout << std::endl;
        cube.execute(switchPositions);
        std::cout << std::endl;
        positionYellowEdges();
    }
    //  F --> B --> L
    else if (cube.fc("FU", B) && cube.fc("BU", L) && cube.fc("LU", F)) {
        cube.execute(switchPositions);
        std::cout << std::endl;
        positionYellowEdges();
    }
    //  any other case
    else {
        cube.execute("Y");
        positionYellowEdges();
    }

    std::cout << std::endl;
};

void Fridrich::positionYellowCorners() {
    std::string positionCorners {"U R U' L' U R' U' L"};
    
    Color F = cube.f("F");
    Color L = cube.f("L");
    Color B = cube.f("B");
    Color R = cube.f("R");
    Color U = cube.f("U");

    if (cube.cornerAtPosition(F, R, U, "FUR", "RUF", "UFR")) {
        //  The corners are positioned correctly
        if (cube.cornerAtPosition(F, U, L, "FUL", "LUF", "UFL")) { /* Do nothing */ }
        else {
            cube.execute(positionCorners);
            positionYellowCorners();
        }
    } else if (cube.cornerAtPosition(F, U, L, "FUL", "LUF", "UFL")) {
        cube.execute("Y'");
        std::cout << std::endl;
        cube.execute(positionCorners);
        std::cout << std::endl;
        cube.execute("Y");
        std::cout << std::endl;
        positionYellowCorners();
    } else if (cube.cornerAtPosition(B, U, R, "BUR", "RUB", "UBR")) {
        cube.execute("Y");
        std::cout << std::endl;
        cube.execute(positionCorners);
        std::cout << std::endl;
        cube.execute("Y'");
        std::cout << std::endl;
        positionYellowCorners();
    } else if (cube.cornerAtPosition(B, U, L, "BUL", "LUB", "UBL")) {
        cube.execute("Y Y");
        std::cout << std::endl;
        cube.execute(positionCorners);
        std::cout << std::endl;
        cube.execute("Y Y");
        std::cout << std::endl;
        positionYellowCorners();
    } else {
        cube.execute(positionCorners);
        positionYellowCorners();
    }
};

void Fridrich::orientYellowCorners() {
    std::string flipFUR {"R' D' R D"};
    Color U = cube.f("U");

    while (!cube.fc("UFR", U)) {
        cube.execute(flipFUR);
        std::cout << std::endl;
    }

    cube.execute("U");
    std::cout << std::endl;
};