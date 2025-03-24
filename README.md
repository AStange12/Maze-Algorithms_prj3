# A-Maze-ing Race
A C++ program that implements search algorithms (BFS and DFS) to solve a maze by finding a path from start to goal.

## Description
This project allows users to read a maze from a file, visualize it, and solve it using either Breadth-First Search (BFS) or Depth-First Search (DFS). The solution path is displayed in the terminal and saved to an output file. The project is structured with separate classes for handling the maze, positions, and a dictionary for efficient lookups.

### Project Structure:
- `main.cpp` - Handles user input, reads the maze file, and executes the search algorithms.
- `maze.h / maze.cpp` - Defines the `Maze` class, manages the grid, and provides functions for searching and displaying the maze.
- `position.h / position.cpp` - Defines the `Position` class, representing individual grid cells.
- `myDictionary.h / myDictionary.cpp` - Implements a dictionary abstraction for managing visited positions efficiently.
- `mazeUtils.h / mazeUtils.cpp` - Provides utility functions for handling maze operations.

## Getting Started

### Dependencies
Ensure you have the following before running the program:
- A C++ compiler and an IED(preferably Clion) that can run C++
- A terminal or command prompt
- A maze file to use as input (located in cmake-build-debug)

### Installing/Compiling
1. Clone the repository or download the source files.
2. Navigate to the project directory/folder and open it in your IED
3. Run the program and follow menu instructions

### Executing the Program
To run the program, execute the compiled binary and provide the necessary inputs:
Follow the prompts:
1. Enter the path to the maze file.
2. Choose the search algorithm (BFS or DFS).
3. Enter the output file name.

**Example:**

## Help
If you encounter issues, check:
- That the maze file exists and follows the correct format.
- The program is compiled correctly.
- Use a debugger like `gdb` or `valgrind` for memory-related errors.

## Authors
- Aaron Stange: contact info - aaron.w.stange@gmail.com

## Version History
- **0.2**
  - Various bug fixes and optimizations.
  - Improved dictionary implementation for tracking visited nodes.
  - See [commit change]() or [release history]().
- **0.1**
  - Initial Release.

## Acknowledgments
- 



