
#include "libs/Includes.h"
#include "libs/Solver/Solver.h"
#include <iostream>

//int main(int argc, char *argv[])
//{
//    FileProcessor fp;
//    SolverTable solver;
//    solver.extractDataFromString(fp.getFileContent( "C:\\Users\\IvanEarth\\Desktop\\input0.txt"));
//
//
//}

int main(int argc, char *argv[]){

    switch (argc) {
        case 1:
            std::cerr << "No arguments\n";
            break;
        case 3:
            FileProcessor fp;
            auto file_content = fp.getFileContent(argv[1]);
            auto B = fp.extractMatrixforB(file_content);
            auto C = fp.extractMatrixforC(file_content);
            auto A = fp.extractMatrixforA(file_content, B.size());
            Solver solver(A,B,C);
            solver.calculate_simplex_table();


    }



}