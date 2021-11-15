//
// Created by IvanEarth on 14.11.2021.
//

#ifndef SIMPLEXSOLVER_CONSOLELOGGER_H
#define SIMPLEXSOLVER_CONSOLELOGGER_H

#include "FileLogger.h"

class ConsoleLogger
{
// console logger
public:
    explicit ConsoleLogger(const bool *isEnable);

    void log(const char *message) const;
    void setLogPermission(bool permission);
    bool getLogPermission() const;

private:
    bool isEnable = false;
};


#endif //SIMPLEXSOLVER_CONSOLELOGGER_H
