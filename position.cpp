#include "position.h"
#include <stdexcept>
#include <string>

using namespace std;

/* Constructor: Initializes a Position object with given coordinates.
 * @param x: int, the x-coordinate of the position.
 * @param y: int, the y-coordinate of the position.
 */
Position::Position(int x, int y) {
    xPos = x;
    yPos = y;
    wall = false;
}

/* Retrieves the x-coordinate of the position.
 * @return: int, the x-coordinate of the position.
 */
int Position::getX() {
    return xPos;
}

/* Retrieves the y-coordinate of the position.
 * @return: int, the y-coordinate of the position.
 */
int Position::getY() {
    return yPos;
}

/* Marks the position as a wall.
 */
void Position::setWall() {
    wall = true;
}

/* Checks if the position is a wall.
 * @return: bool, true if the position is a wall, false otherwise.
 */
bool Position::isWall() {
    return wall;
}

/* Converts the position to a string representation in the format (x, y).
 * @return: string, the formatted string representation of the position.
 */
string Position::to_string() {
    return "(" + std::to_string(xPos) + ", " + std::to_string(yPos) + ")";
}
