/* Assignment: (Project #2) A-maze-ing Race
 * Author(s): Aaron Stange
 * Due Date: 3/23/25
 *
 * Description: In this project I used the BFS and DFS search algorithm to solve a maze.
 *              The program reads a maze from a file, solves it using the specified
 *              search algorithm, and outputs the solution path, path length, and
 *              number of visited nodes during the search to both the terminal and an output file.
 *
 * Comments: None
 *
 * Honor Pledge: I have abided by the Wheaton Honor Code and
 *              all work below was performed by (Aaron Stange).
*/

#include <iostream>
#include <string>
#include <fstream>
#include "maze.h"
#include "mazeUtils.h"

using namespace std;

int main() {
    cout << "Welcome to The A-Maze-ing Race." << endl;
    cout << "Key:\n Dots '.' = Open path\n Hashtags '#' = Wall\n Ats '@' = Path to Goal" << endl;

    string map;
    cout << "where is your maze file? ";
    cin >> map;

    string search;
    cout << "Which search algorithm to use (BFS or DFS)? ";
    while (true) {
        cin >> search;
        if (search == "BFS" || search == "DFS") {
            break; // Valid input, exit loop
        }
        cout << "Invalid input. Please enter 'BFS' or 'DFS': ";
    }


    string outfile;
    cout << "What is the name of the output file? ";
    cin >> outfile;

    try {
        // 1. Read in the map and handle potential errors
        cout << "Loading " << map << "..." << endl;
        Maze* maze = loadMap(map);

        // 2. Display the map to the terminal
        cout << maze->getWidth() << " " << maze->getHeight() << "\nMaze: " << endl;
        maze->print();

        vector<Position*> path;

        ofstream outFile(outfile);
        if (!outFile) {
            cerr << "Error: Unable to open output file." << endl;
            delete maze;
            return 1;
        }

        cout << search << " Searching..." << endl;

        // 3. Call appropriate functions to solve the maze
        if (search == "BFS") {
            path = maze->solveBreadthFirst();
            // 4. Display the solution path to the terminal
            cout << "Solution Path: \n (0, 0)";
            outFile << "Solution Path: \n (0, 0)";
            for (int i = 1; i < path.size(); i++) {
                cout << " -> " << path[i]->to_string();
                outFile << " -> " << path[i]->to_string();
            }
            cout << endl;
        } else if (search == "DFS") {
            path = maze->solveDepthFirst();
            // 4. Display the solution path to the terminal
            cout << "Solution Path: \n (0, 0)";
            outFile << "Solution Path: \n (0, 0)";
            for (int i = 1; i < path.size(); i++) {
                cout << " -> " << path[i]->to_string();
                outFile << " -> " << path[i]->to_string();
            }
            cout << endl;
        }

        string solution = renderAnswer(maze, path);
        cout << solution;


        // 5. Write the solution to the output file
        outFile << solution;
        outFile.close();

        // 6. Output the path length and # of visited nodes
        cout << "Path length: " << maze->getPathLength() << endl;
        cout << "# of visited nodes: " << maze->getVisitedNodes() << endl;

        delete maze;
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }


    return 0;
}