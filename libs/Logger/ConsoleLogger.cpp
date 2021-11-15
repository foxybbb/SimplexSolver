//
// Created by IvanEarth on 14.11.2021.
//

#include "ConsoleLogger.h"

#include <iostream>


void ConsoleLogger::log(const char *message) const
{
    if (message == nullptr)
        return;
    if(this->isEnable){
        std::cout << message << std::endl;
    }

}

void ConsoleLogger::setLogPermission(bool permission)
{
    isEnable = permission;
}

bool ConsoleLogger::getLogPermission() const
{
    return this->isEnable;
}

ConsoleLogger::ConsoleLogger(const bool *isEnable)
{
    this->isEnable = *isEnable;

}



