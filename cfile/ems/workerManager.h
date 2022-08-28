#pragma once
#include <iostream>
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;
#include <fstream>
#define FILENAME "empFile.txt"

class WorkerManager{
    public:
        WorkerManager();

        void showMenu();

        void exitSystem();
        
        void addEmp();

        // save the employee info
        void save();

        int getEmpNum();

        // read the data of file to m_EmpArray array
        void initArray();

        void showEmp();
        
        ~WorkerManager();

        int m_EmpNum;
        Worker **m_EmpArray;
        bool m_FileIsEmpty;
};