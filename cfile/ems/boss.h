#pragma once
#include "worker.h"

class Boss : public Worker{
    public:
        Boss(int, string, int);

        void showInfo();

        string getDeptName();
};