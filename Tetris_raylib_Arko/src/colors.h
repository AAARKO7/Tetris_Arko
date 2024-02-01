#pragma once
#include <raylib.h>
#include <vector>

extern const Color darkGrey; //extern allows to declare a variable in one file and use in another
extern const Color green;    //const= fixed
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color lightBlue;
extern const Color darkBlue;

std::vector<Color> GetCellColors();