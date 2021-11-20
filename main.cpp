
#include "libs/Includes.h"
#include "libs/Solver/Solver.h"
#include <iostream>
#include <fstream>
//int main(int argc, char *argv[])
//{
//    FileProcessor fp;
//    SolverTable solver;
//    solver.extractDataFromString(fp.getFileContent( "C:\\Users\\IvanEarth\\Desktop\\input0.txt"));
//
//
//}

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        std::cerr << "You input wrong arguments \nUsage: ./program <input file> <Output file>" << std::endl;
        return 0;
    }

    if (argc > 3)
    {
        std::cerr << "Too many arguments" << std::endl;
        return 0;
    }

    FileProcessor fp;
    auto file_content = fp.getFileContent(argv[1]);
    auto B = fp.extractMatrixforB(file_content);
    auto C = fp.extractMatrixforC(file_content);
    auto A = fp.extractMatrixforA(file_content, B.size());
    freopen(argv[2], "w", stdout);
    Solver solver(A, B, C);
    solver.calculate_simplex_table();
    solver.saveReport(argv[1]);

    return 0;
}