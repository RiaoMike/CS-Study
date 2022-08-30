#pragma once
#include<iostream>
#include<string>
using namespace std;

// abstract class
class Worker{
    // virtual function
    public:
        virtual void showInfo() = 0;

        virtual string getDeptName() = 0;

        // workers infos
        int m_Id;
        string m_Name;
        int m_DeptId;
};