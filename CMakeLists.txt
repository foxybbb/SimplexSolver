cmake_minimum_required(VERSION 3.0)
project(SimplexSolver)

set(CMAKE_CXX_STANDARD 23)

add_executable(SimplexSolver main.cpp libs/SolverTable.cpp libs/SolverTable.h libs/Includes.h libs/FileProcessor.cpp libs/FileProcessor.h libs/Fraction.cpp libs/Fraction.h libs/Solver/Solver.cpp libs/Solver/Solver.h)
