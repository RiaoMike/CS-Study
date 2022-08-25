#pragma once
#include "worker.h"

class Employee : public Worker{
    // contruct function
    public:
        Employee(int, string, int);

        void showInfo();

        string getDeptName();
};