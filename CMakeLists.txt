cmake_minimum_required(VERSION 3.27)
project(Maze3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Maze3
        test.cpp
        position.cpp
        mazeUtils.cpp
        maze.cpp
        myDictionary.h)
