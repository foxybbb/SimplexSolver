//
// Created by IvanEarth on 14.11.2021.
//

#include "debugClass.h"
#include <iostream>


 void debugClass::dbgPrintArguments(int argc, char *argv[])
{
   std::cout << "There are " << argc << " arguments:\n";

   // Перебираем каждый аргумент и выводим его порядковый номер и значение
   for (int count=0; count < argc; ++count)
     std::cout << count << " " << argv[count] << '\n';
 }
