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

Color  parseColor(char s) {
    switch (s) {
        case ('w'): return Color::W; break;
        case ('r'): return Color::R; break;
        case ('b'): return Color::B; break;
        case ('o'): return Color::O; break;
        case ('g'): return Color::G; break;
        case ('y'): return Color::Y; break;
    }
};