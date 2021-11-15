#include <iostream>
#include "libs/Includes.h"
#include <string>
int main(int argc, char *argv[]) {


    if(argc<=1)
    {
      exit(1);
    }
    if(argc < 2){
      std::cout<< "Please input more then 1 arguments." << std::endl;
    }
    if(argc == 3){

        char *inputFile = argv[1];
        char *outputFile = argv[2];
        FileProcessor fp;
        fp.readFile(inputFile);

       }

    debugClass::dbgPrintArguments(argc,argv);


    return 0;
}

