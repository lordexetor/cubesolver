#include "colors.hpp"

std::string stringifyColor(Color c) {
    switch (c) {
        case (Color::W): return "W"; break;
        case (Color::R): return "R"; break;
        case (Color::B): return "B"; break;
        case (Color::G): return "G"; break;
        case (Color::O): return "O"; break;
        case (Color::Y): return "Y"; break;
        default: return " ";
    }
};

Color  getColor(char s) {
    switch (s) {
        case ('W'): return Color::W; break;
        case ('R'): return Color::R; break;
        case ('B'): return Color::B; break;
        case ('O'): return Color::O; break;
        case ('G'): return Color::G; break;
        case ('Y'): return Color::Y; break;
    }
};