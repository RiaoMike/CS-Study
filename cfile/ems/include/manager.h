#pragma once
#include "worker.h"

class Manager : public Worker{
    public:
        Manager(int, string, int);

        void showInfo();

        string getDeptName();
};