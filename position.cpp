#include "position.h"
#include <stdexcept>
#include <string>

using namespace std;

Position::Position(int x, int y) {
    xPos = x;
    yPos = y;
    wall = false;
}

int Position::getX()  {
    return xPos;
}

int Position::getY() {
    return yPos;
}

void Position::setWall()  {
    wall = true;
}

bool Position::isWall()  {
    return wall;
}

string Position::to_string()  {
    return "(" + std::to_string(xPos) + ", " + std::to_string(yPos) + ")";
}
