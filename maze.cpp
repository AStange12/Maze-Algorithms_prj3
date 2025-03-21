
#include <stdexcept>

/* STL libraries needed */
#include <stack>
#include <queue>
#include <vector>

/* library for reverse function */
#include <algorithm>
#include <iostream>
/* there is a function called "reverse" in this library that can reverse the elements of a vector
 * call it as follows:
 * reverse(v.begin(), v.end()); // this reverses the order of the elements in vector v
 */

#include "maze.h"
#include "myDictionary.h"

using namespace std;

/* Constructor: Initializes the maze with given width and height.
 * @param width: int, the width of the maze.
 * @param height: int, the height of the maze.
 * dependencies: Position class's constructor
 */
Maze::Maze(int width, int height) {
    // initialize width and height
    this->width = width;
    this->height = height;

    positions = new Position**[height]; // Allocate memory for positions matrix, #-o-rows = height
    for (int y = 0; y < height; y++) {
        positions[y] = new Position*[width]; // Allocates memory For each row, #-o-cols = width
        for (int x = 0; x < width; x++) {
            positions[y][x] = new Position(x, y); // Creates position object at (x, y) coordinate
            // we do positions[y][x] because y value corresponds to row and x to the column
        }
    }
}


/* Destructor: Cleans up dynamically allocated memory.
 * dependencies: None.
 */
Maze::~Maze() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            delete positions[y][x]; // Delete each Position object
        }
        delete[] positions[y]; // Delete array for each row
    }
    delete[] positions; // Delete the array
}

/* Returns the width of the maze.
 * @return width: int, the width of the maze.
 * dependencies: None.
 */
int Maze::getWidth() {
    return width;
}

/* Returns the height of the maze.
 * @return height: int, the height of the maze.
 * dependencies: None.
 */
int Maze::getHeight() {
    return height;
}

/* Checks if a given position contains a wall.
 * @param x: int, the x-coordinate.
 * @param y: int, the y-coordinate.
 * @return bool, true if there is a wall, false otherwise.
 * dependencies: Position class's isWall()
 */
bool Maze::isWall(int x, int y) {
    if (x < 0 or x >= width or y < 0 or y >= height) {
        throw out_of_range("Coordinates out of bounds");
    }
    return positions[y][x]->isWall();
}

/* Marks a position as a wall.
 * @param x: int, the x-coordinate.
 * @param y: int, the y-coordinate.
 * dependencies: Position class's setWall()
 */
void Maze::setWall(int x, int y) {
    if (x < 0 or x >= width or y < 0 or y >= height) {
        throw out_of_range("Coordinates out of bounds");
    }
    positions[y][x]->setWall();
}

/* you will need an unordered_map to store the previous of each position */
/* the keys for this map are the to_string of a position object
 * the associated value should be a pointer to the Position from which
 * you saw the key
 */

/* Solves the maze using Breadth-First Search (BFS).
 * @return vector<Position*>, the path to the goal position or an empty vector if no path exists.
 * dependencies: getNeighbors function.
 */
vector<Position*> Maze::solveBreadthFirst() {
    queue<Position*> q; // Queue for BFS traversal
    MyDictionary cameFrom; // Dictionary to store previous positions

    q.push(positions[0][0]); // add start to Queue
    cameFrom.insert(positions[0][0]->to_string(), nullptr); // mark start as visited

    while (!q.empty()) { // while (Queue is not empty)
        Position* current = q.front(); // Current = dequeue node from Queue
        q.pop();

        if (current->getX() == (width - 1) and current->getY() == (height - 1)) { // if (Current == Goal)
            vector<Position*> path;
            while (current != nullptr) { // build the path
                path.push_back(current);
                current = cameFrom.find(current->to_string());
            }
            reverse(path.begin(), path.end()); // Reverse the path for correct order
            return path;
        }


        for (Position* neighbor : getNeighbors(current)) { // iterate over the list possible next moves
            if (!cameFrom.exists(neighbor->to_string())) { // if neighbor not visited
                q.push(neighbor); // add neighbor to Queue
                cameFrom.insert(neighbor->to_string(), current); // record prev move as value for neighbors key
            }
        }
    }

    return {}; // return no path exists
}

/* Solves the maze using Depth-First Search (DFS).
 * @return vector<Position*>, the path to the goal position or an empty vector if no path exists.
 * dependencies: getNeighbors function.
 */
vector<Position*> Maze::solveDepthFirst() {
    stack<Position*> s; // Stack for DFS traversal
    MyDictionary cameFrom; // Dictionary to store previous positions

    s.push(positions[0][0]); // add start to Stack
    cameFrom.insert(positions[0][0]->to_string(), nullptr);// mark start as visited

    while (!s.empty()) { // while (Stack is not empty)
        Position* current = s.top(); // Current = pop node from Stack
        s.pop();

        if (current->getX() == (width - 1) and current->getY() == (height - 1)) { // if (Current == Goal)
            vector<Position*> path;
            while (current != nullptr) { // build the path
                path.push_back(current);
                current = cameFrom.find(current->to_string());
            }
            reverse(path.begin(), path.end()); // Reverse the path for correct order
            return path;
        }

        for (Position* neighbor : getNeighbors(current)) { // iterate over the list possible next moves
            if (!cameFrom.exists(neighbor->to_string())) { // if neighbor not visited
                s.push(neighbor); // add neighbor to Stack
                cameFrom.insert(neighbor->to_string(), current); // record prev move as value for neighbors key
            }
        }
    }

    return {}; // return no path exists
}

/* Returns valid neighbors of a given position (explores up, left, right, and then down).
 * @param position: Position*, the current position.
 * @return vector<Position*>, the list of valid neighboring positions.
 * dependencies: isWall and Position class's constructor, getX(), and getY()
 */
vector<Position*> Maze::getNeighbors(Position* position) {
    vector<Position*> neighbors;
    // current position
    int x = position->getX();
    int y = position->getY();

    // up
    if (y != 0 and !isWall(x, y - 1)) { // is wall conveniently also checks if the position is out of bound :)
        neighbors.push_back(new Position(x, y - 1));  // append to vector
    }

    // left
    if (x != 0 and !isWall(x - 1, y)) {
        neighbors.push_back(new Position(x - 1, y));
    }

    // right
    if (x + 1 != width and !isWall(x + 1, y)) {
        neighbors.push_back(new Position(x + 1, y));
    }

    // down
    if (y + 1 != height and !isWall(x, y + 1)) {
        neighbors.push_back(new Position(x, y + 1));
    }

    return neighbors;
}
