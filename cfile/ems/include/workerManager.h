#pragma once
#include <iostream>
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;
#include <fstream>
#define FILENAME "../build/empFile.txt"

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

        // delete employee
        void delEmp();

        // check out that employee is exists or not
        // and return the index
        int isExists(int);

        void modEmp();

        void findEmp();

        // sort ascent or descent
        void sortEmp();

        void clearFile();
        
        ~WorkerManager();

        int m_EmpNum;
        Worker **m_EmpArray;
        bool m_FileIsEmpty;
};