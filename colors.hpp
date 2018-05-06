#ifndef COLORS_HPP
#define COLORS_HPP

#include <string>

enum class Color {
    W, R, B, O, G, Y
};

//  Return the string for a color.
std::string stringifyColor(Color c);

//  Return the color from a character.
Color getColor(char s);

#endif